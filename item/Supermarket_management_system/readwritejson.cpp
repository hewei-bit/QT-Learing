#include "readwritejson.h"
#include "staff_operation.h"
#include "new_staff.h"
#include "manager_operation.h"


readWriteJson::readWriteJson()
{

}

readWriteJson::~readWriteJson()
{

}
//添加员工账户，不存在才执行
void readWriteJson::addAcount(QString filename, QString account, QString password)
{
    if(isAccountInJson(filename,account) == 0)
    {
        QByteArray text = open_json(filename);
        // 使用QJsonObject对象插入键值对s
        QJsonDocument doc(QJsonDocument::fromJson(text));
        QJsonObject object = doc.object();
        QJsonArray staffarray = object.value("staff").toArray();
        QJsonObject accountObject;
        accountObject.insert("account",account);
        accountObject.insert("password",password);
        staffarray.append(accountObject);
        object.insert("staff",staffarray);

        JsonToFile(object,filename);
    }
    else
    {
        qDebug() << "exits";
    }
}
//遍历员工账号，未找到返回0，已找到返回1
int readWriteJson::isAccountInJson(QString filename, QString account)
{
    QByteArray text = open_json(filename);

    QJsonDocument doc = QJsonDocument::fromJson(text);
    QJsonObject object = doc.object();
    QJsonArray staffarray = object.value("staff").toArray();

    for (int i = 0; i < staffarray.count(); i++) {
        QJsonObject anyoneObject = staffarray.at(i).toObject();
        QString anyone_account = anyoneObject.value("account").toString();
        qDebug()<<anyone_account;
        if(anyone_account != account)
            continue;
        else {
            return i;
        }
    }

    return -1;
}
//检查员工密码是否正确，正确返回true，错误返回false
bool readWriteJson::isPasswordCorrect(QString filename, QString account, QString password)
{
    int i = isAccountInJson(filename,account);
    if(i != -1)
    {
        QByteArray text = open_json(filename);
        QJsonParseError errora;
        QJsonDocument doc(QJsonDocument::fromJson(text,&errora));
        QJsonObject object = doc.object();
        QJsonArray staffarray = object.value("staff").toArray();
        QJsonObject anyoneObject = staffarray.at(i).toObject();
        QString anyone_password = anyoneObject.value("password").toString();
        if(anyone_password != password)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else {
        return false;
    }
}
//删除员工账户
void readWriteJson::deleteAcount(QString filename, QString account)
{
    int i = isAccountInJson(filename,account);
    if(i != -1)
    {
        QFile file;
        file.setFileName(filename);
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            qDebug() << "file open error";
        }
        else {
            qDebug() << "file open";
        }
        QByteArray text = file.readAll();
        file.close();
        file.remove();
        // 使用QJsonObject对象插入键值对。
        QJsonDocument doc(QJsonDocument::fromJson(text));
        QJsonObject object = doc.object();
        QJsonArray staffarray = object.value("staff").toArray();
        QJsonObject anyoneObject = staffarray.at(i).toObject();
        staffarray.removeAt(i);
        object.insert("staff",staffarray);

        JsonToFile(object,filename);
    }
    else
    {
        qDebug() << "don't exist";
    }
}



void readWriteJson::goodsJsonTolist(QString filename,QList<goods>& glist)
{
    //打开文件
    QByteArray text = open_json(filename);
//    QList<goods> goodslist;

    //获取货品信息
    QJsonDocument doc = QJsonDocument::fromJson(text);
    QJsonObject object = doc.object();
    QJsonArray shop_array = object.value("shoparray").toArray();

    //遍历商品
    for (int i = 0;i < shop_array.size();i++) {

        QJsonObject anyone_object = shop_array.at(i).toObject();
        //读取信息
        int ID = anyone_object.value("ID").toInt();
        QString species = anyone_object.value("species").toString();
        QString name = anyone_object.value("name").toString();
        int quantity = anyone_object.value("quantity").toInt();
        int cost =  anyone_object.value("cost").toInt();
        int price =  anyone_object.value("price").toInt();
        QString unit = anyone_object.value("unit").toString();
        qDebug() << quantity;
        qDebug() << cost;
        qDebug() << price;
        //构造商品
        goods anyone(ID,species,name,quantity,cost,price,unit);
        //将商品加入链表
        glist.append(anyone);
    }


}

void readWriteJson::goodslistTojson(QString filename,QList<goods> &glist)
{
    QFile file;
    file.setFileName(filename);
    file.remove();
    QJsonObject object;

    QJsonArray shop_array;
    for (int i = 0; i < glist.count(); ++i) {
        QJsonObject goodsObject;
        goodsObject.insert("ID",glist.at(i).getID());
        goodsObject.insert("species",glist.at(i).getSpecies());
        goodsObject.insert("name",glist.at(i).getName());
        goodsObject.insert("quantity",glist.at(i).getQuantity());
        goodsObject.insert("cost",glist.at(i).getCost());
        goodsObject.insert("price",glist.at(i).getPrice());
        goodsObject.insert("unit",glist.at(i).getUnit());
        shop_array.append(goodsObject);
    }
    object.insert("shoparray",shop_array);

    QJsonDocument doc;
    doc.setObject(object);
    JsonToFile(object,filename);

}


QByteArray readWriteJson::open_json(QString filename)
{
    QFile file;
    //设置文件路径
    file.setFileName(filename);
    //检查是否打开成功
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug() << "file open error";
    }
    else {
        qDebug() << "file open";
    }
    //读取文件信息
    QByteArray text = file.readAll();
    file.close();
    return text;
}

void readWriteJson::JsonToFile(QJsonObject object, QString filename)
{
    QJsonDocument doc;
    doc.setObject(object);
    QFile file;
    file.setFileName(filename);
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    file.write(doc.toJson());
    file.close();
}
