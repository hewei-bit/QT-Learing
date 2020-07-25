#include "serialcrt.h"
#include "ui_serialcrt.h"
#include <QtDebug>

SerialCRT::SerialCRT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialCRT)
{
    ui->setupUi(this);

     infos = QSerialPortInfo::availablePorts();
    foreach(QSerialPortInfo info,infos)
    {
        qDebug() << info.portName();
        qDebug() << info.description();
        qDebug() << info.manufacturer();
        qDebug() << infos.size();
    }

    //[1]配置串口
    mserial.setPort(infos.at(1)); //COM5
    mserial.setBaudRate(QSerialPort::Baud115200);
    mserial.setDataBits(QSerialPort::Data8);
    mserial.setParity(QSerialPort::NoParity);
    mserial.setStopBits(QSerialPort::OneStop);




   //[3] 建立与readyRead() 信号的槽函数
   connect(&mserial,&QSerialPort::readyRead,this,&SerialCRT::read_data);
}

SerialCRT::~SerialCRT()
{
    delete ui;
}

void SerialCRT::on_actionopen_triggered()
{
    //[2]打开串口
   if(! mserial.open(QIODevice::ReadWrite))
   {
       qDebug() << " open port fail";
   }
}

void SerialCRT::read_data()
{
        QByteArray array = mserial.readAll();
        qDebug() << array;

        ui->textBrowser->append(array);
}
