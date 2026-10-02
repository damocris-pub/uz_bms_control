#pragma once

#include <QObject>
#include "UartPort.h"

#define SERIAL_CMD_SOP14        0x7E
#define SERIAL_CMD_EOP14        0x0D
#define SERIAL_RSP_SOP14        0x7E

#define SERIAL_ADR_OFFSET1      (1)
#define SERIAL_CMD_OFFSET1      (2)
#define SERIAL_LEN_OFFSET1      (3)
#define SERIAL_DAT_OFFSET1      (4)
#define SERIAL_CHK_OFFSET1(len) (len+4)
#define SERIAL_EOP_OFFSET1(len) (len+5)

uint8_t uart_packet_check(uint8_t *buffer, int len);

class BmsProtocol : public QObject {
    Q_OBJECT

public:
    BmsProtocols(QObject *parent = nullptr);
    bool connectUartDevice(const QString &portName, const UART_Config &cfg);
    void disconnectUartDevice();
    bool sendBmsUartCommand(const QByteArray& cmdFrame);

    //bool connectCanDevice();
    //void disconnectCanDevice();
    //bool sendBmsCanCommand(const QByteArray& cmdFrame);
signals:

private slots:
    void onRawDataReady();

private:
    UartPort *uart_port = nullptr;
    CanPort *can_port = nullptr;
};
