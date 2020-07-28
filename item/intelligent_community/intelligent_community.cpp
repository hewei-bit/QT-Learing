#include "intelligent_community.h"
#include "ui_intelligent_community.h"
#include "weatherinfo.h"
#include "news.h"
#include "leisure.h"
#include "login.h"
intelligent_community::intelligent_community(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::intelligent_community)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/pic/school.png"));
//    QImage img;
//    img.load(":/pic/school.png");
//    QPixmap originalPixmap = QPixmap::fromImage(img);
//    ui->label->setPixmap(originalPixmap.scaled(ui->label->size(),
//                         Qt::IgnoreAspectRatio,
//                         Qt::SmoothTransformation));

    //天气信息
    WeatherInfo *winfo = new WeatherInfo(this);
    winfo->show();
    winfo->move(540,20);

    //播广告
    ad_video();








}

intelligent_community::~intelligent_community()
{
    delete ui;
}

void intelligent_community::ad_video()
{
    if(in_video_Process.state() == QProcess::Running)
    {
        in_video_Process.kill();
        in_video_Process.waitForFinished();
    }
    QString cmd = QString("mplayer -slave -quiet "
                          " -geometry 0:0 -zoom -x %1 -y %2 "
                          " -wid %3 "
                          " ./Manchester.mp4")
            .arg(ui->label_17->width())
            .arg(ui->label_17->height())
            .arg(QString::number(ui->label_17->winId()));
    qDebug() << "cmd = " << cmd;

    in_video_Process.start(cmd);
}


void intelligent_community::on_server_Btn_clicked()
{

}

void intelligent_community::on_leien_Btn_clicked()
{
    leisure *leien = new leisure(this);
    leien->show();


    this->hide();
}

void intelligent_community::on_selfinfo_Btn_clicked()
{

}

void intelligent_community::on_news_Btn_clicked()
{
    news *nn = new news (this);
    nn->show();

    this->hide();
}

void intelligent_community::on_back_Btn_clicked()
{
    ((login *)this->parentWidget())->show();
    in_video_Process.kill();
    this->close();
}
