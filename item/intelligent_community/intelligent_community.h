#ifndef INTELLIGENT_COMMUNITY_H
#define INTELLIGENT_COMMUNITY_H

#include <QMainWindow>
#include <QTimer>

#include <QProcess>
#include <QtDebug>

#include <QListWidgetItem>
#include <QTime>
#include <QTimer>
#include <QRunnable>
#include <QtDebug>
#include <QThread>
#include <QThreadPool>
#include <QMutex>
#include <QPen>
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QMutex>
//完成对网络数据的请求
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

//JSON数据解析
#include<QJsonArray>  //[]
#include <QJsonDocument> //JSON文档 --- 将服务器数据转换成一个QJsonDocument
#include <QJsonObject> //{}
namespace Ui {
class intelligent_community;
}

class intelligent_community : public QMainWindow
{
    Q_OBJECT

public:
    explicit intelligent_community(QWidget *parent = nullptr);
    ~intelligent_community();

    void ad_video();

    void run_time();

    void read_data(QNetworkReply* reply);

signals:
    void sendname(QString &name);

private slots:

    void on_server_Btn_clicked();

    void on_leien_Btn_clicked();

    void on_selfinfo_Btn_clicked();

    void on_news_Btn_clicked();

    void on_back_Btn_clicked();

    void show_time();

    void http_weather();

public slots:
    void setusername(QString name);


private:
    Ui::intelligent_community *ui;

    QProcess in_video_Process;
    QTimer *timer;
    QNetworkAccessManager *manager;

};

static QMutex mutex;
class Myclock:public QThread
{
    Q_OBJECT
public:
    explicit Myclock(QWidget *parent = nullptr){}
    ~Myclock(){}

    void run() override
    {
        while(1)
        {
            mutex.lock();
//            QTime mtime = QTime::currentTime();
//            qDebug() << mtime.toString("hh:mm:ss");
            QThread::sleep(1);
            emit send();

            mutex.unlock();
        }
    }
signals:
    void send();
};

#endif // INTELLIGENT_COMMUNITY_H
