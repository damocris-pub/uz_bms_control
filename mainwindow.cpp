#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

enum LedColor {
    Led_Off,
    Led_Green,
    Led_Yellow,
    Led_Red
};

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

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->btnSetting, &QPushButton::clicked, this, &MainWindow::on_btnSetting_clicked);
    connect(ui->btnMonitor, &QPushButton::clicked, this, &MainWindow::on_btnMonitor_clicked);
    connect(ui->btnParam, &QPushButton::clicked, this, &MainWindow::on_btnParam_clicked);
    connect(ui->btnConfig, &QPushButton::clicked, this, &MainWindow::on_btnConfig_clicked);
    connect(ui->btnStorage, &QPushButton::clicked, this, &MainWindow::on_btnStorage_clicked);
    connect(ui->btnUpgrade, &QPushButton::clicked, this, &MainWindow::on_btnUpgrade_clicked);
    connect(ui->cmbInterface, &QComboBox::activated, this, &MainWindow::on_cmbInterface_activated);
    //connect(ui->btnImport, &QPushButton::clicked, this, &MainWindow::on_btnImport_clicked);
    //connect(ui->btnOpenDfu, &QPushButton::clicked, this, &MainWindow::on_btnOpenDfu_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
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

