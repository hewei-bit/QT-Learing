#include "videodisplay.h"
#include "ui_videodisplay.h"
#include <QMessageBox>
#include <QImage>
#include <QPixmap>
#include <QtDebug>
#include <QDate>

videodisplay::videodisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::videodisplay)
  ,bufrgb(nullptr)
{
    ui->setupUi(this);
    pd.dev_name = (char*)"/dev/video7";








    connect(&timer,&QTimer::timeout,this,&videodisplay::flushButff);
    timer.setInterval(20);
}

videodisplay::~videodisplay()
{
    delete ui;
}

void videodisplay::on_startBtn_clicked()
{
     int flag = init_dev(&pd);
     if(flag == -1)
     {
         QMessageBox::information(this,"tip","no device");
         exit(1);
     }else if (flag == -2) {
         QMessageBox::information(this,"tip"," device is worng");
         exit(2);
    } else if (flag == -3) {
         QMessageBox::information(this,"tip"," can not open device");
         exit(3);
    }
     ui->startBtn->setDisabled(1);
     timer.start(); //开启捕获数据
}

void videodisplay::flushButff()
{
    read_frame(&pd); //读取数据

    if(!bufrgb)
        bufrgb = (unsigned char *)malloc(640*480*3);
    memset(bufrgb,0,640*480*3);

    convert_yuv_to_rgb_buffer((unsigned char*)pd.buffers[pd.buf.index].start,
            bufrgb,640,480);

    QImage image(bufrgb,640,480,QImage::Format_RGB888);
         ui->displaytLabel->setPixmap(QPixmap::fromImage(image));

    return_data(&pd);
}




void videodisplay::on_startBtn_2_clicked()
{

    QImage image(bufrgb,640,480,QImage::Format_RGB888);
         ui->displaytLabel->setPixmap(QPixmap::fromImage(image));
    QDate nowdate = QDate::currentDate();
    QString filename = QString("%1.png").arg(nowdate.toString("yyyy-MM-dd"));
    image.save(filename);
    qDebug() << filename;
//    printf("save");
//    return_data(&pd);
    QPixmap pixmap = QPixmap::fromImage(image);


    ui->shotlabel->setPixmap(pixmap.scaled(ui->shotlabel->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
//    ui->startBtn->setDisabled(0);




}
