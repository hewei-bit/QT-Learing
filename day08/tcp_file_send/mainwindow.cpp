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
    connect(&msocket,&QTcpSocket::connected,this,&MainWindow::send_file_head);
    connect(&msocket,&QTcpSocket::bytesWritten,this,&MainWindow::send_file_text);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendBtn_clicked()
{
    msocket.connectToHost(ui->ipEdit->text(),ui->portEdit->text().toUShort());
    filesize = 0;
    sendsize= 0;
}

void MainWindow::on_selectBtn_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this);
    ui->fileEdit->setText(filepath);
}

void MainWindow::send_file_head()
{
    //创建文件信息对象
    QFileInfo info
}

void MainWindow::send_file_text()
{

}
