#include "UartPort.h"
#include <QDebug>

UartPort::UartPort(QObject *parent) : QObject(parent)
{
    close_event = CreateEvent(nullptr, true, false, nullptr); //manually reset
}

UartPort::~UartPort()
{
    closePort();
    if (close_event != nullptr) {
        CloseHandle(close_event);
    }
}

bool UartPort::openPort(const QString &portName, const UART_Config &cfg)
{
    if (isOpen) {
        closePort();
    }
    std::string path = "\\\\.\\" + portName.toStdString();
    hDevice = CreateFileA(path.c_str(), GENERIC_READ | GENERIC_WRITE,
        0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);  //Asynchrous mode
    if (hDevice == INVALID_HANDLE_VALUE) {
        emit errorOccurred("Cannot open serial port, error code is，: " + QString::number(GetLastError()));
        return false;
    }

    DCB dcb = {0};
    dcb.DCBlength = sizeof(DCB);
    GetCommState(hDevice, &dcb);
    dcb.BaudRate = cfg.baudrate;
    dcb.ByteSize = cfg.data_bits;
    dcb.Parity = cfg.parity;
    dcb.StopBits = cfg.stop_bits;
    SetCommState(hDevice, &dcb);

    COMMTIMEOUTS timeouts = {0};
    timeouts.ReadIntervalTimeout = 10;          // byte interval timeout (in ms)
    timeouts.ReadTotalTimeoutConstant = kTimeout;    // read timeout (in ms)
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = kTimeout;   // write timeout (in ms)
    timeouts.WriteTotalTimeoutMultiplier = 10;
    SetCommTimeouts(hDevice, &timeouts);

    PurgeComm(hDevice, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
    isOpen = true;
    ResetEvent(close_event);

    workerThread = QThread::create([this]() { this->readLoop(); });
    workerThread->start();
    return true;
}

void UartPort::closePort()
{
    if (!isOpen)
        return;
    isOpen = false;
    SetEvent(close_event);
    if (workerThread != nullptr) {
        workerThread->quit();
        workerThread->wait();
        delete workerThread;
        workerThread = nullptr;
    }
    if (hDevice != INVALID_HANDLE_VALUE) {
        CloseHandle(hDevice);
        hDevice = INVALID_HANDLE_VALUE;
    }
}

bool UartPort::writeDataAsync(const QByteArray &data, int timeoutMs)
{
    if (!isOpen || hDevice == INVALID_HANDLE_VALUE)
        return false;
    OVERLAPPED osWrite = {0};
    osWrite.hEvent = CreateEvent(nullptr, true, false, nullptr);    //manually reset
    uint32_t bytesWritten = 0;
    bool result = WriteFile(hDevice, data.constData(), data.size(), &bytesWritten, &osWrite); //return immediately
    if (!result) {
        if (GetLastError() == ERROR_IO_PENDING) {
            if (WaitForSingleObject(osWrite.hEvent, timeoutMs) == WAIT_OBJECT_0) {
                GetOverlappedResult(hDevice, &osWrite, &bytesWritten, false);
                result = true;
            } else {
                CancelIo(hDevice);
                result = false;
            }
        }
    }
    CloseHandle(osWrite.hEvent);
    return result;
}

void UartPort::readLoop()
{
    OVERLAPPED osWait = {0};
    osWait.hEvent = CreateEvent(nullptr, true, false, nullptr);     //manually reset
    OVERLAPPED osRead = {0};
    osRead.hEvent = CreateEvent(nullptr, true, false, nullptr);     //manually reset
    SetCommMask(hDevice, EV_RXCHAR);    //wakeup only when there is new byte received
    HANDLE handles[2] = { osWait.hEvent, hCloseEvent };

    while (isOpen) {
        uint32_t eventMask = 0;
        if (!WaitCommEvent(hDevice, &eventMask, &osWait)) {
            if (GetLastError() == ERROR_IO_PENDING) {
                uint32_t closeWait = WaitForMultipleObjects(2, handles, false, INFINITE);     //any event can trigger
                if (closeWait == WAIT_OBJECT_0 + 1) {
                    break;
                }
            }
        }
        if (!isOpen) {
            break;
        }
        if (eventMask & EV_RXCHAR) {
            uint8_t buffer[1024];
            uint32_t bytesRead = 0;
            if (!ReadFile(hDevice, buffer, sizeof(buffer), &bytesRead, &osRead)) {
                if (GetLastError() == ERROR_IO_PENDING) {
                    GetOverlappedResult(hDevice, &osRead, &bytesRead, true);    //wait until byte interval timeout triggered
                }
            }
            if (bytesRead > 0) {
                ring_buffer.write(buffer, bytesRead);
                emit dataReady();
            }
        }
    }
    CloseHandle(osWait.hEvent);
    CloseHandle(osRead.hEvent);
}
