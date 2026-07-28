#include "mainwindow.h"
#include "ui_mainwindow.h"

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
