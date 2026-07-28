#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
