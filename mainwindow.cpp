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
