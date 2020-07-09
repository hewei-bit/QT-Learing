#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->setWindowTitle(QString::fromStdString("文件发送客户端"));

    //客户端连接成功，才考虑发送文件，连接成功时，会发送一个信号：connected,
    //如果掉线时会发送disconnect

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendBtn_clicked()
{

}

void MainWindow::on_selectBtn_clicked()
{

}

void MainWindow::send_file_head()
{

}

void MainWindow::send_file_text()
{

}
