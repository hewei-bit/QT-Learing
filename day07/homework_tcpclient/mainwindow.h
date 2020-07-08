#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QtDebug>
#include <QHostAddress>
#include <QTextCodec>
#include <QDateTime>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connect_Btn_clicked();

    void on_send_Btn_clicked();

    void on_clear_Btn_clicked();

    void readData();

private:
    Ui::MainWindow *ui;
    QTcpSocket socket;
    bool isconnetion;
};

#endif // MAINWINDOW_H
