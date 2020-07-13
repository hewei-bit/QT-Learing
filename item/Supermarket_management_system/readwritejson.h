#ifndef READWRITEJSON_H
#define READWRITEJSON_H

#include <QMessageBox>
#include <QtDebug>
//文件IO
#include <QFile>
#include <QTextCodec>
#include <QList>
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

#include "login.h"
#include "goods.h"

class readWriteJson
{
public:
    readWriteJson();
    ~readWriteJson();

    //账户操作
    void addAcount(QString filename,QString account,QString password);
    int isAccountInJson(QString filename,QString account);
    bool isPasswordCorrect(QString filename,QString account,QString password);
    void deleteAcount(QString filename,QString account);

    //货物操作

    void goodsJsonTolist(QString filename,QList<goods>& glist);
    void goodslistTojson(QString filename,QList<goods>& glist);

    //打开json和转换json
    QByteArray open_json(QString filename);
    void JsonToFile(QJsonObject object,QString filename);



private:
    QList<goods> GDLIST;
    QString acount_filename = "./resources/account.json";
    QString goods_filename = "./resources/goods.json";
};





#endif // READWRITEJSON_H
