#include <string.h>
#include "CanPort.h"
#include <QDebug>

CanPort::CanPort(QObject *parent) : QObject(parent)
{
    //load library
    close_event = CreateEvent(nullptr, true, false, nullptr); //manually reset
}

CanPort::~CanPort()
{
    //TODO
}

bool CanPort::openPort(uint32_t chan, uint32_t baudrate)
{
    if (chan != 0 && chan != 1) {
        return false;
    }
    int idx = std::lower_bound(kCanBaudrate, kCanBaudrate + sizeof(kCanBaudrate)/sizeof(int), baudrate) - kCanBaudrate;
    if (kCanBaudrate[idx] != baudrate) {
        return false;
    }
    HINSTANCE handle = LoadLibraryA("cxcan.dll");
    if (handle == nullptr) {
        return false;
    }

    VCI_OpenDevice = (can_openDevice)GetProcAddress(handle, "VCI_OpenDevice");
    VCI_CloseDevice = (can_closeDevice)GetProcAddress(handle, "VCI_CloseDevice");
    VCI_ReadBoardInfo = (can_readBoardInfo)GetProcAddress(handle, "VCI_ReadBoardInfo");
    VCI_InitCAN = (can_initCAN)GetProcAddress(handle, "VCI_InitCAN");
    VCI_StartCAN = (can_startCAN)GetProcAddress(handle, "VCI_StartCAN");
    VCI_ResetCAN = (can_resetCAN)GetProcAddress(handle, "VCI_ResetCAN");
    VCI_ClearBuffer = (can_clearBuffer)GetProcAddress(handle, "VCI_ClearBuffer");
    VCI_GetReceiveNum = (can_getReceiveNum)GetProcAddress(handle, "VCI_GetReceiveNum");
    VCI_Transmit = (can_transmit)GetProcAddress(handle, "VCI_Transmit");
    VCI_Receive = (can_receive)GetProcAddress(handle, "VCI_Receive");
    VCI_SetReference = (can_setReference)GetProcAddress(handle, "VCI_SetReference");
    VCI_UsbDeviceReset = (can_usbDeviceReset)GetProcAddress(handle, "VCI_UsbDeviceReset");

    if (isOpen) {
        closePort();
    }
    if (VCI_OpenDevice(VCI_USBCAN2, 0, 0) != STATUS_OK) {
        return false;
    }
    VCI_INIT_CONFIG config;
    memset(&config, 0, sizeof(config));
    config.timing0 = kTimingCode[idx] & 0xFF;
    config.timing1 = (kTimingCode[idx] >> 8) & 0xFF;
    config.acc_code = 0;
    config.acc_mask = 0xffffffff;
    config.mode = 0; //0 - normal mode, 1 - listen only mode, 2 - loopback mode
    if (VCI_InitCAN(VCI_USBCAN2, 0, chan, &config) != STATUS_OK) {
        return false;
    }
    if (VCI_StartCAN(VCI_USBCAN2, 0, chan) != STATUS_OK) {
        return false;
    }
    hDevice = VCI_USBCAN2;
    channel = chan;

    workerThread = QThread::create([this]() { this->readLoop(); });
    workerThread->start();

    return true;
}

void CanPort::closePort()
{

}

bool CanPort::writeDataAsync(const QByteArray &data, int timeoutMs)
{

}

void CanPort::readLoop()
{

}
