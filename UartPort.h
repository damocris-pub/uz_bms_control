#pragma once

#include <QObject>
#include <QThread>
#include <QByteArray>
#include <windows.h>
#include "SpscRingBuffer.h"

#define kTimeout 1000

static const int kUartBaudrate[] = {
    9600,
    19200,
    38400,
    57600,
    115200,
    230400,
};

struct UART_Config {
    int data_bits = 8;
    UartStopBits stop_bits = ONESTOPBIT;    //or TWOSTOPBITS
    UartParity parity = NOPARITY;   //or ODDPARITY, EVENPARITY
    int baudrate = 115200;
};

class UartPort : public QObject {
    Q_OBJECT

private:
    HANDLE hDevice = INVALID_HANDLE_VALUE;
    HANDLE close_event = nullptr;
    QThread *workerThread = nullptr;

    void readLoop();

public:
    bool isOpen = false;
    SpscRingBuffer<4096> ring_buffer;

    UartPort(QObject *parent = nullptr);
    ~UartPort();
    bool openPort(const QString &portName, const UART_Config &cfg);
    void closePort();
    bool writeDataAsync(const QByteArray &data, int timeoutMs = kTimeout);

signals:
    void dataReceived();
    void errorOccurred(const QString &errorMsg);
};
