#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtDebug>
#include <QJsonParseError>
//文件IO
#include <QFile>
#include <QTextCodec>

//JSON数据解析
#include<QJsonArray>  //[]
#include <QJsonDocument> //JSON文档 --- 将服务器数据转换成一个QJsonDocument
#include <QJsonObject> //{}
#include <QJsonArray>

#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>

#include <QDateTime>
#include <QDir>


namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    void addJson(QString account,QString password);
    int isAccountInJson(QString account);
    bool isPasswordCorrect(QString account,QString password);
    void deleteJson(QString account);
    QByteArray open_json();
    void JsonToFile(QJsonObject object);
private slots:
    void on_mannager_Btn_clicked();

    void on_staff_Btn_clicked();

    void on_exit_btn_clicked();



private:
    Ui::login *ui;
    QString account;
    QString password;
};

#endif // LOGIN_H
