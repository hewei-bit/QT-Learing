#ifndef INTELLIGENT_COMMUNITY_H
#define INTELLIGENT_COMMUNITY_H

#include <QMainWindow>
#include <QTimer>

#include <QProcess>
#include <QtDebug>


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




private slots:


    void on_server_Btn_clicked();

    void on_leien_Btn_clicked();

    void on_selfinfo_Btn_clicked();

    void on_news_Btn_clicked();

    void on_back_Btn_clicked();

private:
    Ui::intelligent_community *ui;

    QProcess in_video_Process;
    QTimer *timer;

};

#endif // INTELLIGENT_COMMUNITY_H
