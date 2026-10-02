#pragma once

#include <QMainWindow>
#include "BmsProtocol.h"

enum LedColor {
    Led_Off,
    Led_Green,
    Led_Yellow,
    Led_Red
};

enum Interface {
    UART,
    CAN,
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnParam_clicked();

    void on_btnSetting_clicked();

    void on_cmbInterface_activated(int index);

    void on_btnConfig_clicked();

    void on_btnUpgrade_clicked();

    void on_btnStorage_clicked();

    void on_btnMonitor_clicked();

    void on_btnImport_clicked();

    void on_btnOpenDfu_clicked();

    void on_btnExport_clicked();

    void on_cmbPortUart_activated(int index);

    void on_cmbPortCan_activated(int index);

    void on_cmbAdaptor_activated(int index);

    void on_cmbBaudrateCan_activated(int index);

    void on_cmbStopbits_activated(int index);

    void on_cmbParitycheck_activated(int index);

    void on_cmbBaudrateUart_activated(int index);

    void on_chkConnect_checkStateChanged(const Qt::CheckState &arg);

    void onBmsDataUpdated(const BmsStatusData& data);

private:
    Interface inf;
    BmsProtocoal *bms_protocol = nullptr;
    Ui::MainWindow *ui;
};
