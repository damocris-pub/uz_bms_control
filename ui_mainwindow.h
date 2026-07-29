/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_Main;
    QHBoxLayout *horizontalLayout_TopBar;
    QPushButton *btnSetting;
    QPushButton *btnMonitor;
    QPushButton *btnParam;
    QPushButton *btnConfig;
    QPushButton *btnStorage;
    QPushButton *btnUpgrade;
    QLabel *lblAddress;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QStackedWidget *stackedWidget;
    QWidget *page_setting;
    QHBoxLayout *horizontalLayout_PageHome;
    QGroupBox *groupBox_setting;
    QStackedWidget *stackedWidget_Interface;
    QWidget *page_uart;
    QLabel *label_11;
    QComboBox *cmbPortUart;
    QLabel *label_12;
    QComboBox *cmbStopbits;
    QLabel *label_13;
    QComboBox *cmbParitycheck;
    QLabel *label_14;
    QComboBox *cmbBaudrateUart;
    QWidget *page_can;
    QLabel *label_15;
    QComboBox *cmbAdaptor;
    QLabel *label_16;
    QComboBox *cmbPortCan;
    QComboBox *cmbBaudrateCan;
    QLabel *label_17;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *cmbLanguage;
    QComboBox *cmbPlatform;
    QComboBox *cmbInterface;
    QWidget *page_monitor;
    QGroupBox *groupBox_2;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_27;
    QLineEdit *lineEditSOC;
    QLineEdit *lineEditSOH;
    QLabel *label_26;
    QLabel *label_28;
    QLineEdit *lineEditCycle;
    QLineEdit *lineEditRemainCapacity;
    QLineEdit *lineEditCurrent;
    QLineEdit *lineEditTotalVoltage;
    QPushButton *btnForceUpdate;
    QGroupBox *groupBox_3;
    QTableWidget *tableCellVoltage;
    QGroupBox *groupBox_4;
    QTableWidget *tableCellTemperature;
    QGroupBox *groupBoxProtect;
    QVBoxLayout *verticalLayout_Protect;
    QHBoxLayout *hLayout_P1;
    QLabel *led_ProtectVolt;
    QLabel *lbl_ProtectVolt;
    QHBoxLayout *hLayout_P2;
    QLabel *led_ProtectCurr;
    QLabel *lbl_ProtectCurr;
    QHBoxLayout *hLayout_P3;
    QLabel *led_ProtectTemp;
    QLabel *lbl_ProtectTemp;
    QHBoxLayout *hLayout_P4;
    QLabel *led_ProtectShort;
    QLabel *lbl_ProtectShort;
    QGroupBox *groupBoxWarning;
    QVBoxLayout *verticalLayout_Warning;
    QHBoxLayout *hLayout_P5;
    QLabel *led_WarningVolt;
    QLabel *lbl_WarningVolt;
    QHBoxLayout *hLayout_P6;
    QLabel *led_WarningCurr;
    QLabel *lbl_WarningCurr;
    QHBoxLayout *hLayout_P7;
    QLabel *led_WarningTemp;
    QLabel *lbl_WarningTemp;
    QHBoxLayout *hLayout_P8;
    QLabel *led_WarningShort;
    QLabel *lbl_WarningShort;
    QWidget *page_param;
    QHBoxLayout *horizontalLayout_PageParam;
    QTableWidget *tableParameter;
    QGroupBox *groupBox_param;
    QPushButton *btnRead;
    QPushButton *btnWrite;
    QPushButton *btnImport;
    QPushButton *btnExport;
    QPlainTextEdit *plainTextParameter;
    QWidget *page_config;
    QVBoxLayout *verticalLayout_PageConfig;
    QGroupBox *groupBox;
    QPushButton *btnCfgRead;
    QPushButton *btnCfgWrite;
    QTabWidget *tabCablibration;
    QWidget *CurrentCalibration;
    QWidget *VoltageCalibration;
    QWidget *TemperatureCalibration;
    QWidget *OtherCalibration;
    QLabel *label_4;
    QSpinBox *spbBatteryCellcount;
    QLabel *label_5;
    QLineEdit *lineEditFullCapacity;
    QLabel *label_6;
    QLineEdit *lineEditSystemInfo;
    QLabel *label_7;
    QLineEdit *lineEditPackInfo;
    QWidget *page_store;
    QPushButton *btnReadBmsTimestamp;
    QPushButton *btnWriteBmsTimestamp;
    QDateTimeEdit *dtBmsTimestamp;
    QDateTimeEdit *dtSystemTimestamp;
    QPushButton *btnStartRecord;
    QPushButton *btnStopRecord;
    QPushButton *btnSaveRecord;
    QPlainTextEdit *plainTextEditStore;
    QSpinBox *spbTimeInterval;
    QLabel *label_3;
    QLabel *label_29;
    QCheckBox *checkBoxVoltage;
    QCheckBox *checkBoxSoC;
    QCheckBox *checkBoxTemperature;
    QWidget *page_upgrade;
    QProgressBar *progressUpgrade;
    QPushButton *btnOpenDfu;
    QPushButton *btnUpgradeDfu;
    QPlainTextEdit *plainTextUpgrade;
    QPushButton *btnDump;
    QLineEdit *lineEditFromAddr;
    QLineEdit *lineEditToAddr;
    QLabel *label;
    QLabel *label_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(944, 508);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_Main = new QVBoxLayout(centralwidget);
        verticalLayout_Main->setObjectName("verticalLayout_Main");
        horizontalLayout_TopBar = new QHBoxLayout();
        horizontalLayout_TopBar->setObjectName("horizontalLayout_TopBar");
        btnSetting = new QPushButton(centralwidget);
        btnSetting->setObjectName("btnSetting");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        btnSetting->setFont(font);
        btnSetting->setFlat(true);

        horizontalLayout_TopBar->addWidget(btnSetting);

        btnMonitor = new QPushButton(centralwidget);
        btnMonitor->setObjectName("btnMonitor");
        btnMonitor->setFont(font);
        btnMonitor->setFlat(true);

        horizontalLayout_TopBar->addWidget(btnMonitor);

        btnParam = new QPushButton(centralwidget);
        btnParam->setObjectName("btnParam");
        btnParam->setFont(font);
        btnParam->setFlat(true);

        horizontalLayout_TopBar->addWidget(btnParam);

        btnConfig = new QPushButton(centralwidget);
        btnConfig->setObjectName("btnConfig");
        btnConfig->setFont(font);
        btnConfig->setFlat(true);

        horizontalLayout_TopBar->addWidget(btnConfig);

        btnStorage = new QPushButton(centralwidget);
        btnStorage->setObjectName("btnStorage");
        btnStorage->setFont(font);
        btnStorage->setFlat(true);

        horizontalLayout_TopBar->addWidget(btnStorage);

        btnUpgrade = new QPushButton(centralwidget);
        btnUpgrade->setObjectName("btnUpgrade");
        btnUpgrade->setFont(font);
        btnUpgrade->setFlat(true);

        horizontalLayout_TopBar->addWidget(btnUpgrade);

        lblAddress = new QLabel(centralwidget);
        lblAddress->setObjectName("lblAddress");
        lblAddress->setFont(font);
        lblAddress->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lblAddress->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_TopBar->addWidget(lblAddress);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout_TopBar->addWidget(comboBox);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setFont(font);

        horizontalLayout_TopBar->addWidget(checkBox);


        verticalLayout_Main->addLayout(horizontalLayout_TopBar);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page_setting = new QWidget();
        page_setting->setObjectName("page_setting");
        horizontalLayout_PageHome = new QHBoxLayout(page_setting);
        horizontalLayout_PageHome->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_PageHome->setObjectName("horizontalLayout_PageHome");
        groupBox_setting = new QGroupBox(page_setting);
        groupBox_setting->setObjectName("groupBox_setting");
        stackedWidget_Interface = new QStackedWidget(groupBox_setting);
        stackedWidget_Interface->setObjectName("stackedWidget_Interface");
        stackedWidget_Interface->setGeometry(QRect(330, 10, 291, 211));
        page_uart = new QWidget();
        page_uart->setObjectName("page_uart");
        label_11 = new QLabel(page_uart);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 30, 51, 16));
        cmbPortUart = new QComboBox(page_uart);
        cmbPortUart->addItem(QString());
        cmbPortUart->addItem(QString());
        cmbPortUart->addItem(QString());
        cmbPortUart->addItem(QString());
        cmbPortUart->setObjectName("cmbPortUart");
        cmbPortUart->setGeometry(QRect(100, 20, 150, 30));
        label_12 = new QLabel(page_uart);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 70, 51, 16));
        cmbStopbits = new QComboBox(page_uart);
        cmbStopbits->addItem(QString());
        cmbStopbits->addItem(QString());
        cmbStopbits->setObjectName("cmbStopbits");
        cmbStopbits->setGeometry(QRect(100, 60, 150, 30));
        label_13 = new QLabel(page_uart);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 110, 71, 16));
        cmbParitycheck = new QComboBox(page_uart);
        cmbParitycheck->addItem(QString());
        cmbParitycheck->addItem(QString());
        cmbParitycheck->addItem(QString());
        cmbParitycheck->setObjectName("cmbParitycheck");
        cmbParitycheck->setGeometry(QRect(100, 100, 150, 30));
        label_14 = new QLabel(page_uart);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 150, 91, 16));
        cmbBaudrateUart = new QComboBox(page_uart);
        cmbBaudrateUart->addItem(QString());
        cmbBaudrateUart->addItem(QString());
        cmbBaudrateUart->addItem(QString());
        cmbBaudrateUart->addItem(QString());
        cmbBaudrateUart->setObjectName("cmbBaudrateUart");
        cmbBaudrateUart->setGeometry(QRect(100, 140, 150, 30));
        stackedWidget_Interface->addWidget(page_uart);
        page_can = new QWidget();
        page_can->setObjectName("page_can");
        label_15 = new QLabel(page_can);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 30, 91, 16));
        cmbAdaptor = new QComboBox(page_can);
        cmbAdaptor->addItem(QString());
        cmbAdaptor->addItem(QString());
        cmbAdaptor->setObjectName("cmbAdaptor");
        cmbAdaptor->setGeometry(QRect(120, 20, 150, 30));
        label_16 = new QLabel(page_can);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 70, 91, 16));
        cmbPortCan = new QComboBox(page_can);
        cmbPortCan->addItem(QString());
        cmbPortCan->addItem(QString());
        cmbPortCan->setObjectName("cmbPortCan");
        cmbPortCan->setGeometry(QRect(120, 60, 150, 30));
        cmbBaudrateCan = new QComboBox(page_can);
        cmbBaudrateCan->addItem(QString());
        cmbBaudrateCan->addItem(QString());
        cmbBaudrateCan->addItem(QString());
        cmbBaudrateCan->setObjectName("cmbBaudrateCan");
        cmbBaudrateCan->setGeometry(QRect(120, 100, 150, 30));
        label_17 = new QLabel(page_can);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 110, 101, 16));
        stackedWidget_Interface->addWidget(page_can);
        label_8 = new QLabel(groupBox_setting);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 40, 61, 21));
        label_9 = new QLabel(groupBox_setting);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(50, 80, 61, 21));
        label_10 = new QLabel(groupBox_setting);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(50, 120, 61, 21));
        cmbLanguage = new QComboBox(groupBox_setting);
        cmbLanguage->addItem(QString());
        cmbLanguage->addItem(QString());
        cmbLanguage->setObjectName("cmbLanguage");
        cmbLanguage->setGeometry(QRect(140, 110, 150, 30));
        cmbPlatform = new QComboBox(groupBox_setting);
        cmbPlatform->addItem(QString());
        cmbPlatform->addItem(QString());
        cmbPlatform->setObjectName("cmbPlatform");
        cmbPlatform->setGeometry(QRect(140, 70, 150, 30));
        cmbInterface = new QComboBox(groupBox_setting);
        cmbInterface->addItem(QString());
        cmbInterface->addItem(QString());
        cmbInterface->setObjectName("cmbInterface");
        cmbInterface->setGeometry(QRect(140, 30, 150, 30));

        horizontalLayout_PageHome->addWidget(groupBox_setting);

        stackedWidget->addWidget(page_setting);
        page_monitor = new QWidget();
        page_monitor->setObjectName("page_monitor");
        groupBox_2 = new QGroupBox(page_monitor);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 20, 230, 310));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(20, 30, 71, 21));
        label_18->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(200, 30, 31, 21));
        label_19->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(20, 70, 71, 21));
        label_20->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(200, 70, 31, 21));
        label_21->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(20, 110, 71, 21));
        label_22->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(200, 110, 31, 21));
        label_23->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(200, 150, 31, 21));
        label_24->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(20, 150, 71, 21));
        label_25->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_27 = new QLabel(groupBox_2);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 230, 71, 21));
        label_27->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEditSOC = new QLineEdit(groupBox_2);
        lineEditSOC->setObjectName("lineEditSOC");
        lineEditSOC->setGeometry(QRect(100, 100, 100, 30));
        lineEditSOH = new QLineEdit(groupBox_2);
        lineEditSOH->setObjectName("lineEditSOH");
        lineEditSOH->setGeometry(QRect(100, 140, 100, 30));
        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(0, 190, 101, 21));
        label_26->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(210, 190, 31, 21));
        label_28->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEditCycle = new QLineEdit(groupBox_2);
        lineEditCycle->setObjectName("lineEditCycle");
        lineEditCycle->setGeometry(QRect(100, 220, 100, 30));
        lineEditRemainCapacity = new QLineEdit(groupBox_2);
        lineEditRemainCapacity->setObjectName("lineEditRemainCapacity");
        lineEditRemainCapacity->setGeometry(QRect(100, 180, 100, 30));
        lineEditCurrent = new QLineEdit(groupBox_2);
        lineEditCurrent->setObjectName("lineEditCurrent");
        lineEditCurrent->setGeometry(QRect(100, 60, 100, 30));
        lineEditTotalVoltage = new QLineEdit(groupBox_2);
        lineEditTotalVoltage->setObjectName("lineEditTotalVoltage");
        lineEditTotalVoltage->setGeometry(QRect(100, 20, 100, 30));
        btnForceUpdate = new QPushButton(groupBox_2);
        btnForceUpdate->setObjectName("btnForceUpdate");
        btnForceUpdate->setGeometry(QRect(70, 270, 100, 30));
        groupBox_3 = new QGroupBox(page_monitor);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(450, 20, 220, 420));
        tableCellVoltage = new QTableWidget(groupBox_3);
        if (tableCellVoltage->columnCount() < 2)
            tableCellVoltage->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableCellVoltage->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableCellVoltage->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableCellVoltage->setObjectName("tableCellVoltage");
        tableCellVoltage->setGeometry(QRect(0, 20, 210, 400));
        groupBox_4 = new QGroupBox(page_monitor);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(670, 20, 220, 420));
        tableCellTemperature = new QTableWidget(groupBox_4);
        if (tableCellTemperature->columnCount() < 2)
            tableCellTemperature->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableCellTemperature->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableCellTemperature->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableCellTemperature->setObjectName("tableCellTemperature");
        tableCellTemperature->setGeometry(QRect(10, 20, 210, 400));
        groupBoxProtect = new QGroupBox(page_monitor);
        groupBoxProtect->setObjectName("groupBoxProtect");
        groupBoxProtect->setGeometry(QRect(240, 20, 200, 180));
        verticalLayout_Protect = new QVBoxLayout(groupBoxProtect);
        verticalLayout_Protect->setSpacing(5);
        verticalLayout_Protect->setObjectName("verticalLayout_Protect");
        hLayout_P1 = new QHBoxLayout();
        hLayout_P1->setObjectName("hLayout_P1");
        led_ProtectVolt = new QLabel(groupBoxProtect);
        led_ProtectVolt->setObjectName("led_ProtectVolt");
        led_ProtectVolt->setMinimumSize(QSize(24, 24));
        led_ProtectVolt->setMaximumSize(QSize(24, 24));
        led_ProtectVolt->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        hLayout_P1->addWidget(led_ProtectVolt);

        lbl_ProtectVolt = new QLabel(groupBoxProtect);
        lbl_ProtectVolt->setObjectName("lbl_ProtectVolt");

        hLayout_P1->addWidget(lbl_ProtectVolt);


        verticalLayout_Protect->addLayout(hLayout_P1);

        hLayout_P2 = new QHBoxLayout();
        hLayout_P2->setObjectName("hLayout_P2");
        led_ProtectCurr = new QLabel(groupBoxProtect);
        led_ProtectCurr->setObjectName("led_ProtectCurr");
        led_ProtectCurr->setMinimumSize(QSize(24, 24));
        led_ProtectCurr->setMaximumSize(QSize(24, 24));

        hLayout_P2->addWidget(led_ProtectCurr);

        lbl_ProtectCurr = new QLabel(groupBoxProtect);
        lbl_ProtectCurr->setObjectName("lbl_ProtectCurr");

        hLayout_P2->addWidget(lbl_ProtectCurr);


        verticalLayout_Protect->addLayout(hLayout_P2);

        hLayout_P3 = new QHBoxLayout();
        hLayout_P3->setObjectName("hLayout_P3");
        led_ProtectTemp = new QLabel(groupBoxProtect);
        led_ProtectTemp->setObjectName("led_ProtectTemp");
        led_ProtectTemp->setMinimumSize(QSize(24, 24));
        led_ProtectTemp->setMaximumSize(QSize(24, 24));

        hLayout_P3->addWidget(led_ProtectTemp);

        lbl_ProtectTemp = new QLabel(groupBoxProtect);
        lbl_ProtectTemp->setObjectName("lbl_ProtectTemp");

        hLayout_P3->addWidget(lbl_ProtectTemp);


        verticalLayout_Protect->addLayout(hLayout_P3);

        hLayout_P4 = new QHBoxLayout();
        hLayout_P4->setObjectName("hLayout_P4");
        led_ProtectShort = new QLabel(groupBoxProtect);
        led_ProtectShort->setObjectName("led_ProtectShort");
        led_ProtectShort->setMinimumSize(QSize(24, 24));
        led_ProtectShort->setMaximumSize(QSize(24, 24));

        hLayout_P4->addWidget(led_ProtectShort);

        lbl_ProtectShort = new QLabel(groupBoxProtect);
        lbl_ProtectShort->setObjectName("lbl_ProtectShort");

        hLayout_P4->addWidget(lbl_ProtectShort);


        verticalLayout_Protect->addLayout(hLayout_P4);

        groupBoxWarning = new QGroupBox(page_monitor);
        groupBoxWarning->setObjectName("groupBoxWarning");
        groupBoxWarning->setGeometry(QRect(240, 210, 200, 180));
        verticalLayout_Warning = new QVBoxLayout(groupBoxWarning);
        verticalLayout_Warning->setSpacing(5);
        verticalLayout_Warning->setObjectName("verticalLayout_Warning");
        hLayout_P5 = new QHBoxLayout();
        hLayout_P5->setObjectName("hLayout_P5");
        led_WarningVolt = new QLabel(groupBoxWarning);
        led_WarningVolt->setObjectName("led_WarningVolt");
        led_WarningVolt->setMinimumSize(QSize(24, 24));
        led_WarningVolt->setMaximumSize(QSize(24, 24));
        led_WarningVolt->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        hLayout_P5->addWidget(led_WarningVolt);

        lbl_WarningVolt = new QLabel(groupBoxWarning);
        lbl_WarningVolt->setObjectName("lbl_WarningVolt");

        hLayout_P5->addWidget(lbl_WarningVolt);


        verticalLayout_Warning->addLayout(hLayout_P5);

        hLayout_P6 = new QHBoxLayout();
        hLayout_P6->setObjectName("hLayout_P6");
        led_WarningCurr = new QLabel(groupBoxWarning);
        led_WarningCurr->setObjectName("led_WarningCurr");
        led_WarningCurr->setMinimumSize(QSize(24, 24));
        led_WarningCurr->setMaximumSize(QSize(24, 24));

        hLayout_P6->addWidget(led_WarningCurr);

        lbl_WarningCurr = new QLabel(groupBoxWarning);
        lbl_WarningCurr->setObjectName("lbl_WarningCurr");

        hLayout_P6->addWidget(lbl_WarningCurr);


        verticalLayout_Warning->addLayout(hLayout_P6);

        hLayout_P7 = new QHBoxLayout();
        hLayout_P7->setObjectName("hLayout_P7");
        led_WarningTemp = new QLabel(groupBoxWarning);
        led_WarningTemp->setObjectName("led_WarningTemp");
        led_WarningTemp->setMinimumSize(QSize(24, 24));
        led_WarningTemp->setMaximumSize(QSize(24, 24));

        hLayout_P7->addWidget(led_WarningTemp);

        lbl_WarningTemp = new QLabel(groupBoxWarning);
        lbl_WarningTemp->setObjectName("lbl_WarningTemp");

        hLayout_P7->addWidget(lbl_WarningTemp);


        verticalLayout_Warning->addLayout(hLayout_P7);

        hLayout_P8 = new QHBoxLayout();
        hLayout_P8->setObjectName("hLayout_P8");
        led_WarningShort = new QLabel(groupBoxWarning);
        led_WarningShort->setObjectName("led_WarningShort");
        led_WarningShort->setMinimumSize(QSize(24, 24));
        led_WarningShort->setMaximumSize(QSize(24, 24));

        hLayout_P8->addWidget(led_WarningShort);

        lbl_WarningShort = new QLabel(groupBoxWarning);
        lbl_WarningShort->setObjectName("lbl_WarningShort");

        hLayout_P8->addWidget(lbl_WarningShort);


        verticalLayout_Warning->addLayout(hLayout_P8);

        stackedWidget->addWidget(page_monitor);
        page_param = new QWidget();
        page_param->setObjectName("page_param");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(page_param->sizePolicy().hasHeightForWidth());
        page_param->setSizePolicy(sizePolicy);
        horizontalLayout_PageParam = new QHBoxLayout(page_param);
        horizontalLayout_PageParam->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_PageParam->setObjectName("horizontalLayout_PageParam");
        tableParameter = new QTableWidget(page_param);
        if (tableParameter->columnCount() < 6)
            tableParameter->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableParameter->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableParameter->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableParameter->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableParameter->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableParameter->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableParameter->setHorizontalHeaderItem(5, __qtablewidgetitem9);
        tableParameter->setObjectName("tableParameter");
        sizePolicy.setHeightForWidth(tableParameter->sizePolicy().hasHeightForWidth());
        tableParameter->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(9);
        tableParameter->setFont(font1);

        horizontalLayout_PageParam->addWidget(tableParameter);

        groupBox_param = new QGroupBox(page_param);
        groupBox_param->setObjectName("groupBox_param");
        btnRead = new QPushButton(groupBox_param);
        btnRead->setObjectName("btnRead");
        btnRead->setGeometry(QRect(90, 60, 100, 30));
        btnWrite = new QPushButton(groupBox_param);
        btnWrite->setObjectName("btnWrite");
        btnWrite->setGeometry(QRect(220, 60, 100, 30));
        btnImport = new QPushButton(groupBox_param);
        btnImport->setObjectName("btnImport");
        btnImport->setGeometry(QRect(90, 20, 100, 30));
        btnExport = new QPushButton(groupBox_param);
        btnExport->setObjectName("btnExport");
        btnExport->setGeometry(QRect(220, 20, 100, 30));
        plainTextParameter = new QPlainTextEdit(groupBox_param);
        plainTextParameter->setObjectName("plainTextParameter");
        plainTextParameter->setGeometry(QRect(20, 119, 420, 301));

        horizontalLayout_PageParam->addWidget(groupBox_param);

        stackedWidget->addWidget(page_param);
        page_config = new QWidget();
        page_config->setObjectName("page_config");
        verticalLayout_PageConfig = new QVBoxLayout(page_config);
        verticalLayout_PageConfig->setSpacing(10);
        verticalLayout_PageConfig->setContentsMargins(10, 10, 10, 10);
        verticalLayout_PageConfig->setObjectName("verticalLayout_PageConfig");
        groupBox = new QGroupBox(page_config);
        groupBox->setObjectName("groupBox");
        btnCfgRead = new QPushButton(groupBox);
        btnCfgRead->setObjectName("btnCfgRead");
        btnCfgRead->setGeometry(QRect(30, 350, 100, 30));
        btnCfgWrite = new QPushButton(groupBox);
        btnCfgWrite->setObjectName("btnCfgWrite");
        btnCfgWrite->setGeometry(QRect(150, 350, 100, 30));
        tabCablibration = new QTabWidget(groupBox);
        tabCablibration->setObjectName("tabCablibration");
        tabCablibration->setGeometry(QRect(330, 30, 570, 360));
        CurrentCalibration = new QWidget();
        CurrentCalibration->setObjectName("CurrentCalibration");
        QFont font2;
        font2.setBold(true);
        CurrentCalibration->setFont(font2);
        CurrentCalibration->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        tabCablibration->addTab(CurrentCalibration, QString());
        VoltageCalibration = new QWidget();
        VoltageCalibration->setObjectName("VoltageCalibration");
        VoltageCalibration->setFont(font2);
        tabCablibration->addTab(VoltageCalibration, QString());
        TemperatureCalibration = new QWidget();
        TemperatureCalibration->setObjectName("TemperatureCalibration");
        TemperatureCalibration->setFont(font2);
        tabCablibration->addTab(TemperatureCalibration, QString());
        OtherCalibration = new QWidget();
        OtherCalibration->setObjectName("OtherCalibration");
        OtherCalibration->setFont(font2);
        tabCablibration->addTab(OtherCalibration, QString());
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 60, 100, 20));
        spbBatteryCellcount = new QSpinBox(groupBox);
        spbBatteryCellcount->setObjectName("spbBatteryCellcount");
        spbBatteryCellcount->setGeometry(QRect(150, 50, 150, 30));
        spbBatteryCellcount->setValue(16);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 100, 111, 20));
        lineEditFullCapacity = new QLineEdit(groupBox);
        lineEditFullCapacity->setObjectName("lineEditFullCapacity");
        lineEditFullCapacity->setGeometry(QRect(150, 90, 150, 30));
        lineEditFullCapacity->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 140, 111, 20));
        lineEditSystemInfo = new QLineEdit(groupBox);
        lineEditSystemInfo->setObjectName("lineEditSystemInfo");
        lineEditSystemInfo->setGeometry(QRect(150, 130, 150, 30));
        lineEditSystemInfo->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 180, 111, 20));
        lineEditPackInfo = new QLineEdit(groupBox);
        lineEditPackInfo->setObjectName("lineEditPackInfo");
        lineEditPackInfo->setGeometry(QRect(150, 170, 150, 30));
        lineEditPackInfo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_PageConfig->addWidget(groupBox);

        stackedWidget->addWidget(page_config);
        page_store = new QWidget();
        page_store->setObjectName("page_store");
        btnReadBmsTimestamp = new QPushButton(page_store);
        btnReadBmsTimestamp->setObjectName("btnReadBmsTimestamp");
        btnReadBmsTimestamp->setGeometry(QRect(50, 50, 150, 30));
        sizePolicy.setHeightForWidth(btnReadBmsTimestamp->sizePolicy().hasHeightForWidth());
        btnReadBmsTimestamp->setSizePolicy(sizePolicy);
        btnWriteBmsTimestamp = new QPushButton(page_store);
        btnWriteBmsTimestamp->setObjectName("btnWriteBmsTimestamp");
        btnWriteBmsTimestamp->setGeometry(QRect(50, 110, 150, 30));
        sizePolicy.setHeightForWidth(btnWriteBmsTimestamp->sizePolicy().hasHeightForWidth());
        btnWriteBmsTimestamp->setSizePolicy(sizePolicy);
        dtBmsTimestamp = new QDateTimeEdit(page_store);
        dtBmsTimestamp->setObjectName("dtBmsTimestamp");
        dtBmsTimestamp->setGeometry(QRect(240, 50, 180, 30));
        sizePolicy.setHeightForWidth(dtBmsTimestamp->sizePolicy().hasHeightForWidth());
        dtBmsTimestamp->setSizePolicy(sizePolicy);
        dtSystemTimestamp = new QDateTimeEdit(page_store);
        dtSystemTimestamp->setObjectName("dtSystemTimestamp");
        dtSystemTimestamp->setGeometry(QRect(240, 110, 180, 30));
        sizePolicy.setHeightForWidth(dtSystemTimestamp->sizePolicy().hasHeightForWidth());
        dtSystemTimestamp->setSizePolicy(sizePolicy);
        btnStartRecord = new QPushButton(page_store);
        btnStartRecord->setObjectName("btnStartRecord");
        btnStartRecord->setGeometry(QRect(30, 370, 100, 30));
        sizePolicy.setHeightForWidth(btnStartRecord->sizePolicy().hasHeightForWidth());
        btnStartRecord->setSizePolicy(sizePolicy);
        btnStopRecord = new QPushButton(page_store);
        btnStopRecord->setObjectName("btnStopRecord");
        btnStopRecord->setGeometry(QRect(160, 370, 100, 30));
        sizePolicy.setHeightForWidth(btnStopRecord->sizePolicy().hasHeightForWidth());
        btnStopRecord->setSizePolicy(sizePolicy);
        btnSaveRecord = new QPushButton(page_store);
        btnSaveRecord->setObjectName("btnSaveRecord");
        btnSaveRecord->setGeometry(QRect(290, 370, 100, 30));
        sizePolicy.setHeightForWidth(btnSaveRecord->sizePolicy().hasHeightForWidth());
        btnSaveRecord->setSizePolicy(sizePolicy);
        plainTextEditStore = new QPlainTextEdit(page_store);
        plainTextEditStore->setObjectName("plainTextEditStore");
        plainTextEditStore->setGeometry(QRect(450, 30, 500, 450));
        spbTimeInterval = new QSpinBox(page_store);
        spbTimeInterval->setObjectName("spbTimeInterval");
        spbTimeInterval->setGeometry(QRect(240, 290, 100, 30));
        sizePolicy.setHeightForWidth(spbTimeInterval->sizePolicy().hasHeightForWidth());
        spbTimeInterval->setSizePolicy(sizePolicy);
        spbTimeInterval->setMaximum(999999);
        label_3 = new QLabel(page_store);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 210, 150, 25));
        label_29 = new QLabel(page_store);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(50, 290, 120, 25));
        checkBoxVoltage = new QCheckBox(page_store);
        checkBoxVoltage->setObjectName("checkBoxVoltage");
        checkBoxVoltage->setGeometry(QRect(250, 180, 120, 25));
        checkBoxSoC = new QCheckBox(page_store);
        checkBoxSoC->setObjectName("checkBoxSoC");
        checkBoxSoC->setGeometry(QRect(250, 240, 120, 25));
        checkBoxTemperature = new QCheckBox(page_store);
        checkBoxTemperature->setObjectName("checkBoxTemperature");
        checkBoxTemperature->setGeometry(QRect(250, 210, 120, 25));
        stackedWidget->addWidget(page_store);
        page_upgrade = new QWidget();
        page_upgrade->setObjectName("page_upgrade");
        progressUpgrade = new QProgressBar(page_upgrade);
        progressUpgrade->setObjectName("progressUpgrade");
        progressUpgrade->setGeometry(QRect(50, 120, 300, 30));
        progressUpgrade->setValue(0);
        btnOpenDfu = new QPushButton(page_upgrade);
        btnOpenDfu->setObjectName("btnOpenDfu");
        btnOpenDfu->setGeometry(QRect(40, 50, 100, 30));
        btnUpgradeDfu = new QPushButton(page_upgrade);
        btnUpgradeDfu->setObjectName("btnUpgradeDfu");
        btnUpgradeDfu->setGeometry(QRect(260, 50, 100, 30));
        plainTextUpgrade = new QPlainTextEdit(page_upgrade);
        plainTextUpgrade->setObjectName("plainTextUpgrade");
        plainTextUpgrade->setGeometry(QRect(450, 30, 500, 450));
        btnDump = new QPushButton(page_upgrade);
        btnDump->setObjectName("btnDump");
        btnDump->setGeometry(QRect(40, 310, 100, 30));
        lineEditFromAddr = new QLineEdit(page_upgrade);
        lineEditFromAddr->setObjectName("lineEditFromAddr");
        lineEditFromAddr->setGeometry(QRect(280, 280, 100, 30));
        lineEditToAddr = new QLineEdit(page_upgrade);
        lineEditToAddr->setObjectName("lineEditToAddr");
        lineEditToAddr->setGeometry(QRect(280, 330, 100, 30));
        label = new QLabel(page_upgrade);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 290, 91, 20));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(false);
        label->setFont(font3);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(page_upgrade);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 340, 81, 20));
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(page_upgrade);

        verticalLayout_Main->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        tabCablibration->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Battery Control System", nullptr));
        btnSetting->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        btnMonitor->setText(QCoreApplication::translate("MainWindow", "Monitor", nullptr));
        btnParam->setText(QCoreApplication::translate("MainWindow", "Parameter", nullptr));
        btnConfig->setText(QCoreApplication::translate("MainWindow", "Config", nullptr));
        btnStorage->setText(QCoreApplication::translate("MainWindow", "Store", nullptr));
        btnUpgrade->setText(QCoreApplication::translate("MainWindow", "Upgrade", nullptr));
        lblAddress->setStyleSheet(QCoreApplication::translate("MainWindow", "color: blue; font-weight: bold;", nullptr));
        lblAddress->setText(QCoreApplication::translate("MainWindow", "Address", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        checkBox->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
        groupBox_setting->setTitle(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        cmbPortUart->setItemText(0, QCoreApplication::translate("MainWindow", "COM1", nullptr));
        cmbPortUart->setItemText(1, QCoreApplication::translate("MainWindow", "COM2", nullptr));
        cmbPortUart->setItemText(2, QCoreApplication::translate("MainWindow", "COM3", nullptr));
        cmbPortUart->setItemText(3, QCoreApplication::translate("MainWindow", "COM4", nullptr));

        label_12->setText(QCoreApplication::translate("MainWindow", "Stop Bits", nullptr));
        cmbStopbits->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        cmbStopbits->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));

        label_13->setText(QCoreApplication::translate("MainWindow", "Parity Check", nullptr));
        cmbParitycheck->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        cmbParitycheck->setItemText(1, QCoreApplication::translate("MainWindow", "Odd", nullptr));
        cmbParitycheck->setItemText(2, QCoreApplication::translate("MainWindow", "Even", nullptr));

        label_14->setText(QCoreApplication::translate("MainWindow", "Baud Rate (bps)", nullptr));
        cmbBaudrateUart->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        cmbBaudrateUart->setItemText(1, QCoreApplication::translate("MainWindow", "115200", nullptr));
        cmbBaudrateUart->setItemText(2, QCoreApplication::translate("MainWindow", "19200", nullptr));
        cmbBaudrateUart->setItemText(3, QCoreApplication::translate("MainWindow", "38400", nullptr));

        label_15->setText(QCoreApplication::translate("MainWindow", "Adaptor Board", nullptr));
        cmbAdaptor->setItemText(0, QCoreApplication::translate("MainWindow", "CX USBCAN", nullptr));
        cmbAdaptor->setItemText(1, QCoreApplication::translate("MainWindow", "ZLG USBCAN-II", nullptr));

        label_16->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        cmbPortCan->setItemText(0, QCoreApplication::translate("MainWindow", "CAN1", nullptr));
        cmbPortCan->setItemText(1, QCoreApplication::translate("MainWindow", "CAN2", nullptr));

        cmbBaudrateCan->setItemText(0, QCoreApplication::translate("MainWindow", "500", nullptr));
        cmbBaudrateCan->setItemText(1, QCoreApplication::translate("MainWindow", "100", nullptr));
        cmbBaudrateCan->setItemText(2, QCoreApplication::translate("MainWindow", "200", nullptr));

        label_17->setText(QCoreApplication::translate("MainWindow", "Baud Rate (kbps)", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Interface", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Platform", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Language", nullptr));
        cmbLanguage->setItemText(0, QCoreApplication::translate("MainWindow", "English", nullptr));
        cmbLanguage->setItemText(1, QCoreApplication::translate("MainWindow", "\347\256\200\344\275\223\344\270\255\346\226\207", nullptr));

        cmbPlatform->setItemText(0, QCoreApplication::translate("MainWindow", "Low Voltage", nullptr));
        cmbPlatform->setItemText(1, QCoreApplication::translate("MainWindow", "High Voltage", nullptr));

        cmbInterface->setItemText(0, QCoreApplication::translate("MainWindow", "RS-485", nullptr));
        cmbInterface->setItemText(1, QCoreApplication::translate("MainWindow", "CAN", nullptr));

        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Battery Info", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Total Voltage", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "V", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Current", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "SOC", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "SOH", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Battery Cycle", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Remain Capacity", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "mAh", nullptr));
        btnForceUpdate->setText(QCoreApplication::translate("MainWindow", "Force Update", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Battery Cell Voltage", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableCellVoltage->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Cell", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableCellVoltage->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Voltage (mv)", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Battery Cell Temperature", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableCellTemperature->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Item", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableCellTemperature->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        groupBoxProtect->setTitle(QCoreApplication::translate("MainWindow", "Protection Status", nullptr));
        led_ProtectVolt->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.3, fy:0.3, stop:0 #B0B0B0, stop:1 #606060); border-radius: 12px;", nullptr));
        lbl_ProtectVolt->setText(QCoreApplication::translate("MainWindow", "No Voltage Protection", nullptr));
        led_ProtectCurr->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.3, fy:0.3, stop:0 #B0B0B0, stop:1 #606060); border-radius: 12px;", nullptr));
        lbl_ProtectCurr->setText(QCoreApplication::translate("MainWindow", "No Current Protection", nullptr));
        led_ProtectTemp->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.3, fy:0.3, stop:0 #B0B0B0, stop:1 #606060); border-radius: 12px;", nullptr));
        lbl_ProtectTemp->setText(QCoreApplication::translate("MainWindow", "No Temperature Protection", nullptr));
        led_ProtectShort->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.3, fy:0.3, stop:0 #B0B0B0, stop:1 #606060); border-radius: 12px;", nullptr));
        lbl_ProtectShort->setText(QCoreApplication::translate("MainWindow", "No Short Circuit", nullptr));
        groupBoxWarning->setTitle(QCoreApplication::translate("MainWindow", "Warning Status", nullptr));
        led_WarningVolt->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.3, fy:0.3, stop:0 #B0B0B0, stop:1 #606060); border-radius: 12px;", nullptr));
        lbl_WarningVolt->setText(QCoreApplication::translate("MainWindow", "No Voltage Warning", nullptr));
        led_WarningCurr->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.3, fy:0.3, stop:0 #B0B0B0, stop:1 #606060); border-radius: 12px;", nullptr));
        lbl_WarningCurr->setText(QCoreApplication::translate("MainWindow", "No Current Warning", nullptr));
        led_WarningTemp->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.3, fy:0.3, stop:0 #B0B0B0, stop:1 #606060); border-radius: 12px;", nullptr));
        lbl_WarningTemp->setText(QCoreApplication::translate("MainWindow", "No Temperature Warning", nullptr));
        led_WarningShort->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: qradialgradient(cx:0.5, cy:0.5, radius:0.5, fx:0.3, fy:0.3, stop:0 #B0B0B0, stop:1 #606060); border-radius: 12px;", nullptr));
        lbl_WarningShort->setText(QCoreApplication::translate("MainWindow", "MOS Connected", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableParameter->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Parameter", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableParameter->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableParameter->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Minimum", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableParameter->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Maximum", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableParameter->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableParameter->horizontalHeaderItem(5);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Unit", nullptr));
        groupBox_param->setTitle(QString());
        btnRead->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        btnWrite->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        btnImport->setText(QCoreApplication::translate("MainWindow", "Import", nullptr));
        btnExport->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        groupBox->setTitle(QString());
        btnCfgRead->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        btnCfgWrite->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        tabCablibration->setTabText(tabCablibration->indexOf(CurrentCalibration), QCoreApplication::translate("MainWindow", "Current Calibration", nullptr));
        tabCablibration->setTabText(tabCablibration->indexOf(VoltageCalibration), QCoreApplication::translate("MainWindow", "Voltage Calibration", nullptr));
        tabCablibration->setTabText(tabCablibration->indexOf(TemperatureCalibration), QCoreApplication::translate("MainWindow", "Temperature Calibration", nullptr));
        tabCablibration->setTabText(tabCablibration->indexOf(OtherCalibration), QCoreApplication::translate("MainWindow", "Other Calibration", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Battery Cell Count", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Full Capacity (mAh)", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Bms System Info", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Battery Pack Info", nullptr));
        btnReadBmsTimestamp->setText(QCoreApplication::translate("MainWindow", "Get BMS Timestamp", nullptr));
        btnWriteBmsTimestamp->setText(QCoreApplication::translate("MainWindow", "Set System Timestamp", nullptr));
        btnStartRecord->setText(QCoreApplication::translate("MainWindow", "Start Record", nullptr));
        btnStopRecord->setText(QCoreApplication::translate("MainWindow", "Stop Record", nullptr));
        btnSaveRecord->setText(QCoreApplication::translate("MainWindow", "Save Record", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Addtional Record Item", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Record Interval", nullptr));
        checkBoxVoltage->setText(QCoreApplication::translate("MainWindow", "Cell Voltage", nullptr));
        checkBoxSoC->setText(QCoreApplication::translate("MainWindow", "Cell SoC", nullptr));
        checkBoxTemperature->setText(QCoreApplication::translate("MainWindow", "Cell Temperature", nullptr));
        btnOpenDfu->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        btnUpgradeDfu->setText(QCoreApplication::translate("MainWindow", "Upgrade", nullptr));
        btnDump->setText(QCoreApplication::translate("MainWindow", "Dump", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "From Hex Addr", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "To Hex Addr", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
