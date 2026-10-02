#include "BmsProtocol.h"

uint8_t uart_packet_check(uint8_t *buffer, int len)
{
    int i;
    uint8_t chk = 0;
    uint8_t sum = 0;
    for (int i=0; i<len; ++i) {
        chk ^= buffer[i];
        sum += buffer[i];
    }
    return chk ^ sum;
}

BmsProtocol::BmsProtocol(QObject *parent) : QObject(parent) {}

bool BmsProtocol::connectUartDevice(const QString &portName, const UART_Config &cfg)
{
    uart_port = new UartPort(this);
    if (!uart_port) {
        return false;
    }
    connect(uart_port, &dataReceived, this, &BmsProtocol::onRawDataReady);
    bool ok = uart_port->openPort(portName, cfg);
    if (!ok) {
        delete uart_port;
        uart_port = nullptr;
    }
    return ok;
}

void BmsProtocol::disconnectUartDevice() {
    if (uart_port != nullptr) {
        uart_port->closePort();
        uart_port = nullptr;
    }
}

bool BmsProtocol::sendBmsUartCommand(const QByteArray& cmdFrame) {
    if (uart_port && uart_port->isOpen) {
        return uart_port->writeDataAsync(cmdFrame);
    }
    return false;
}

void BmsProtocol::onRawDataReady()
{

}
