#include <vector>
#include <setupapi.h>
#include <devguid.h>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QDebug>
#include "CanPort.h"
#include "UartPort.h"
#include "BmsProtocol.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

void setLedStatus(QLabel *ledLabel, LedColor color)
{
    QString style = "border-radius: 12px; ";
    switch (color) {
    case Led_Off:
        style += "background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.3, fy:0.3, stop:0 #B0B0B0, stop:1 #606060);";
        break;
    case Led_Green:
        style += "background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.3, fy:0.3, stop:0 #A1FF96, stop:1 #00A000);";
        break;
    case Led_Yellow:
        style += "background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.3, fy:0.3, stop:0 #99D0FF, stop:1 #0066CC);";
        break;
    case Led_Red:
        style += "background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.3, fy:0.3, stop:0 #FF9A9A, stop:1 #D30000);";
        break;
    }
    ledLabel->setStyleSheet(style);
}

void parseJsonFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open :" << filePath;
        return;
    }
    QByteArray data = file.readAll();
    file.close();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "JSON Parsing Error:" << filePath << "Error Reason:" << parseError.errorString();
        return;
    }

    if (doc.isObject()) {   //{}
        QJsonObject jsonObj = doc.object();
        qDebug() << "Successfully Parsing JSON Object:" << QFileInfo(filePath).fileName();
    } else if (doc.isArray()) { //[]
        QJsonArray jsonArray = doc.array();
        qDebug() << "Successfully Parsing JSON Array:" << QFileInfo(filePath).fileName();
    }
}

void parseDfuFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Cannot open :" << filePath;
        return;
    }
    QByteArray dfuData = file.readAll();
    file.close();
    if (dfuData.isEmpty()) {
        qDebug() << "the dfu file size is 0";
        return;
    }
    qDebug() << "Successfully reading dfu file and the total bytes is " << dfuData.size();
}

std::vector<std::pair<QString, QString>> getAvailableUartPorts()
{
    std::vector<std::pair<QString, QString>> portList;
    HDEVINFO hDevInfo = SetupDiGetClassDevs(&GUID_DEVCLASS_PORTS, nullptr, nullptr, DIGCF_PRESENT);
    if (hDevInfo == INVALID_HANDLE_VALUE) {
        return portList;
    }
    SP_DEVINFO_DATA deviceInfoData;
    deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
    int i = 0;
    while (SetupDiEnumDeviceInfo(hDevInfo, i, &deviceInfoData)) {
        HKEY hKey = SetupDiOpenDevRegKey(hDevInfo, &deviceInfoData, DICS_FLAG_GLOBAL, 0, DIREG_DEV, KEY_READ);
        if (hKey == INVALID_LINK_INDEX) {
            continue;
        }
        wchar_t port_name[256] = {0};
        uint32_t data_size = 256;
        uint32_t type = 0;
        int res = RegQueryValueExW(hKey, L"PortName", nullptr, &type, (LPBYTE)port_name, &data_size);
        RegCloseKey(hKey);
        if (res != ERROR_SUCCESS) {
            continue;
        }
        if (wcsncmp(port_name, L"COM", 3) != 0) {
            continue;
        }
        wchar_t description[512] = {0};
        SetupDiGetDeviceRegistryPropertyW(hDevInfo, &deviceInfoData,
            SPDRP_FRIENDLYNAME, nullptr, (PBYTE)description, 512, nullptr);
        portList.push_back(std::make_pair(QString::fromWCharArray(port_name), QString::fromWCharArray(description)));
        portList.emplace_back(portInfo);
        ++i;
    }
    SetupDiDestroyDeviceInfoList(hDeviceInfo);
    return portList;
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->chkConnect->setChecked(false);
    ui->stackedWidget->setCurrentIndex(0);
    //connect(ui->btnSetting, &QPushButton::clicked, this, &MainWindow::on_btnSetting_clicked);
    //connect(ui->btnMonitor, &QPushButton::clicked, this, &MainWindow::on_btnMonitor_clicked);
    //connect(ui->btnParam, &QPushButton::clicked, this, &MainWindow::on_btnParam_clicked);
    //connect(ui->btnConfig, &QPushButton::clicked, this, &MainWindow::on_btnConfig_clicked);
    //connect(ui->btnStorage, &QPushButton::clicked, this, &MainWindow::on_btnStorage_clicked);
    //connect(ui->btnUpgrade, &QPushButton::clicked, this, &MainWindow::on_btnUpgrade_clicked);
    //connect(ui->cmbInterface, &QComboBox::activated, this, &MainWindow::on_cmbInterface_activated);
    //connect(ui->btnImport, &QPushButton::clicked, this, &MainWindow::on_btnImport_clicked);
    //connect(ui->btnExport, &QPushButton::clicked, this, &MainWindow::on_btnExport_clicked);
    //connect(ui->btnOpenDfu, &QPushButton::clicked, this, &MainWindow::on_btnOpenDfu_clicked);
    ui->cmbInterface->setCurrentIndex(0);
    inf = UART;
    bms_protocol = new BmsProtocol(this);
    connect(bms_protocol, &BmsProtocol::onRawDataReady, this, &MainWindow::onBmsDataUpdated);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_chkConnect_checkStateChanged(const Qt::CheckState &state)
{
    UART_Config cfg;
    switch (state) {
    case Qt::Unchecked:
        if (inf == UART) {
            bms_protocol->disconnectUartDevice();
        } else { //inf == CAN

        }
        break;
    case Qt::Checked:
        if (inf == UART) {
            QString uart_port = ui->cmbPortUart->currentData().toString();
            cfg.data_bits = 8;
            cfg.stop_bits = ui->cmbStopbits->currentData().toInt();
            cfg.parity = ui->cmbParitycheck->currentData().toInt();
            int idx = ui->cmbBaudrateUart->currentData().toInt();
            cfg.baudrate = UartBaudRate[idx];
            if (!bms_protocol->connectUartDevice(uart_port, cfg)) {
                QMessageBox::critical(this, tr("Error"), tr("Connection Error！"));
            }
        }  else {   //inf == CAN

        }
        break;
    }
}

void MainWindow::on_btnSetting_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_Interface->setCurrentIndex(0);
}

void MainWindow::on_btnMonitor_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnParam_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btnConfig_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->tabCablibration->setCurrentIndex(0);
}

void MainWindow::on_btnStorage_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_btnUpgrade_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_cmbInterface_activated(int index)
{
    ui->stackedWidget_Interface->setCurrentIndex(index);
    if (index == 0) {
        inf = UART;
        std::vector<std::pair<QString, QString>> port_list = getAvailableUartPorts();
        for (int i = 0; i < port_list.size(); ++i) {
            ui->cmbPortUart->addItem(port_list[i].first() + QChar(':') + port_list[i].second(), port_list[i].first());
        }
        ui->cmbStopbits->addItem("1", ONESTOPBIT);
        ui->cmbStopbits->addItem("2", TWOSTOPBITS);
        ui->cmbParitycheck->addItem("None", NOPARITY);
        ui->cmbParitycheck->addItem("Odd", ODDPARITY);
        ui->cmbParitycheck->addItem("Even", EVENPARITY);
        for (int i = 0; i < sizeof(UartBaudRate)/sizeof(int); ++i) {
            ui->cmbBaudrateUart->addItem(QString::number(UartBaudRate[i]) + " bps", i);
        }
    } else {    //index == 1
        inf = CAN;
        ui->cmbPortCan->addItem("CX CANANALYSTII", 0);
        ui->cmbPortCan->addItem("ZLG USBCANII", 1);
        //for ZLG USBCANII and CX USBCAN adaptor board
        ui->cmbPortCan->addItem("CAN1", 0);
        ui->cmbPortCan->addItem("CAN2", 1);
        for (int i = 0; i < sizeof(CanBaudRate)/sizeof(int); ++i) {
            ui->cmbBaudrateCan->addItem(QString::number(CanBaudRate[i]) + " bps", i);
        }
    }
}

void MainWindow::on_cmbPortUart_activated(int index)
{
    ui->chkConnect->setChecked(false);
}

void MainWindow::on_cmbStopbits_activated(int index)
{

    ui->chkConnect->setChecked(false);
}

void MainWindow::on_cmbParitycheck_activated(int index)
{
    ui->chkConnect->setChecked(false);
}

void MainWindow::on_cmbBaudrateUart_activated(int index)
{
    ui->chkConnect->setChecked(false);
}

void MainWindow::on_cmbAdaptor_activated(int index)
{
    ui->chkConnect->setChecked(false);
}

void MainWindow::on_cmbPortCan_activated(int index)
{
    ui->chkConnect->setChecked(false);
}

void MainWindow::on_cmbBaudrateCan_activated(int index)
{
    ui->chkConnect->setChecked(false);
}

void MainWindow::on_btnImport_clicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(this,
        tr("Please choose the directory contains the parameter json5 files"),
        QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (dirPath.isEmpty()) {
        return;
    }
    QDir dir(dirPath);
    QStringList filters;
    filters << "*.json5";
    dir.setNameFilters(filters);
    dir.setFilter(QDir::Files | QDir::NoSymLinks);  //only choose json5 files
    const QFileInfoList fileList = dir.entryInfoList();
    if (fileList.isEmpty()) {
        QMessageBox::information(this, tr("Hint"), tr("this directory doesn't contain any json5 files"));
        return;
    }
    int cnt = 0;
    for (const QFileInfo &fileInfo : fileList) {
        QString filePath = fileInfo.absoluteFilePath();
        qDebug() << "try to reading :" << fileInfo.fileName();
        //parseJsonFile(filePath);
        ++cnt;
    }
    QMessageBox::information(this, tr("Completed"), QString("Successfully loading %1 json5 files").arg(cnt));
}

void MainWindow::on_btnExport_clicked()
{

}

void MainWindow::on_btnOpenDfu_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
        tr("Please choose .dfu file"), QDir::homePath(),
        tr("DFU Firmware File (*.dfu);; All Files (*.*)"));
    if (filePath.isEmpty()) {
        return;
    }
    qDebug() << "The choosed dfu file :" << filePath;
    parseDfuFile(filePath);
}
