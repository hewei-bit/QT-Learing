#include "login.h"
#include "ui_login.h"
#include "staff_operation.h"
#include "new_staff.h"
#include "manager_operation.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);


}

login::~login()
{
    delete ui;
}
//添加员工账户，不存在才执行
void login::addJson(QString account, QString password)
{
    if(isAccountInJson(account) == 0)
    {
        QByteArray text = open_json();
        // 使用QJsonObject对象插入键值对。
        QJsonDocument doc(QJsonDocument::fromJson(text));
        QJsonObject object = doc.object();
        QJsonArray staffarray = object.value("staff").toArray();
        QJsonObject accountObject;
        accountObject.insert("account",account);
        accountObject.insert("password",password);
        staffarray.append(accountObject);
        object.insert("staff",staffarray);

        JsonToFile(object);
    }
    else
    {
        qDebug() << "exits";
    }

}
//检查员工密码是否正确，正确返回true，错误返回false
bool login::isPasswordCorrect(QString account, QString password)
{
    int i = isAccountInJson(account);
    if(i != 0)
    {
        QByteArray text = open_json();
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
        else {
            return true;
        }
    }
    else {
        return false;
    }
}
//遍历员工账号，未找到返回0，已找到返回1
int login::isAccountInJson(QString account)
{
    QByteArray text = open_json();


    QJsonDocument doc = QJsonDocument::fromJson(text);
    QJsonObject object = doc.object();
    QJsonArray staffarray = object.value("staff").toArray();

    for (int i = 0; i < staffarray.count(); ++i) {
        QJsonObject anyoneObject = staffarray.at(i).toObject();
        QString anyone_account = anyoneObject.value("account").toString();

        if(anyone_account != account)
            continue;
        else {
            return i;
        }
    }

    return 0;
}
//
void login::deleteJson(QString account)
{
    int i = isAccountInJson(account);
    if(i != 0)
    {
        QFile file;
        file.setFileName("./resources/account.json");
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


        JsonToFile(object);
    }
    else
    {
        qDebug() << "don't exist";
    }
}
//打开json文件返回QByteArray
QByteArray login::open_json()
{
    QFile file;
    file.setFileName("./resources/account.json");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug() << "file open error";
    }
    else {
        qDebug() << "file open";
    }
    QByteArray text = file.readAll();
    file.close();
    return text;
}

//将jsonobject返回文件
void login::JsonToFile(QJsonObject object)
{
    QJsonDocument doc;
    doc.setObject(object);
    QFile file;
    file.setFileName("./resources/account.json");
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    file.write(doc.toJson());
    file.close();
}

void login::on_mannager_Btn_clicked()
{
    //获取键入账号密码
    QString account = ui->account_lineEdit->text();
    QString password = ui->password_lineEdit->text();
    //打开json文件
    QByteArray text = open_json();
    //获取json中管理员账号密码
    QJsonDocument doc = QJsonDocument::fromJson(text);
    QJsonObject object = doc.object();
    QJsonArray staffarray = object.value("manager").toArray();
    QJsonObject anyoneObject = staffarray.at(0).toObject();
    //校验密码
    if(anyoneObject.value("account").toString()==account)
    {

        if(anyoneObject.value("password").toString()==password)
        {
            QMessageBox::warning(this,"成功","success");
        }
        else {
            QMessageBox::warning(this,"fail","password wrong");
        }
    }
    else {
        QMessageBox::warning(this,"fail","account wrong");
    }

    manager_operation *mop = new manager_operation(this);
    mop->show();

}

void login::on_staff_Btn_clicked()
{
    QString account = ui->account_lineEdit->text();
    QString password = ui->password_lineEdit->text();
    int i = 4;
    while (i--)
    {
        if(isAccountInJson(account)!= 0)
        {
            if(isPasswordCorrect(account,password)!=0)
            {
                QMessageBox::warning(this,"成功","success");
                break;
            }
            else {
                QMessageBox::warning(this,"fail","password wrong");
            }
        }
        else {
            QMessageBox::warning(this,"fail","account wrong");
        }
        if(i == 1)
        {
            QMessageBox::warning(this,"fail","you have try 3 times");
        }
    }

    staff_operation *sop = new staff_operation(this);
    sop->show();




}

//退出
void login::on_exit_btn_clicked()
{
    this->close();
}
