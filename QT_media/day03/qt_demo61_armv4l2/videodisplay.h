#ifndef VIDEODISPLAY_H
#define VIDEODISPLAY_H

#include <QWidget>
#include "v4l2.h"
#include <QTimer>
#include <QPixmap>
//#include <QtDebug>

namespace Ui {
class videodisplay;
}

class videodisplay : public QWidget
{
    Q_OBJECT

public:
    explicit videodisplay(QWidget *parent = nullptr);
    ~videodisplay();

private slots:
    void on_startBtn_clicked();
    void flushButff();





    void on_startBtn_2_clicked();

private:
    Ui::videodisplay *ui;
    pass_data pd; //定义一个相关的摄像头对象

     unsigned char *bufrgb; //获取摄像头数据指针
     QTimer timer;
};

#endif // VIDEODISPLAY_H
