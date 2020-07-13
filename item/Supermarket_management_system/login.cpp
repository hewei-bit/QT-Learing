#include "login.h"
#include "ui_login.h"
#include "staff_operation.h"
#include "new_staff.h"
#include "manager_operation.h"

#include "readwritejson.h"
#include "goods.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);


    readWriteJson *RWJson = new readWriteJson();
    goods *GOODS = new goods();
    QList<goods> goodslist;
    RWJson->goodsJsonTolist("./resources/goods.json",goodslist);
    goods aaa(1010,"food","apple",100,5,6,"ge");
    GOODS->addgoods(aaa,goodslist);
    RWJson->goodslistTojson("./resources/goods.json",goodslist);
}

login::~login()
{
    delete ui;
}

void login::on_mannager_Btn_clicked()
{
    readWriteJson *RWJson = new readWriteJson();

    //获取键入账号密码
    QString account = ui->account_lineEdit->text();
    QString password = ui->password_lineEdit->text();

    //打开json文件
    QByteArray text = RWJson->open_json(accountfilename);

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
            //跳转至管理员界面
            manager_operation *mop = new manager_operation(this);
            mop->show();

            this->hide();
        }
        else
        {
            QMessageBox::warning(this,"登录失败","password wrong");
        }
    }
    else
    {
        QMessageBox::warning(this,"登录失败","account wrong");
    }



}

void login::on_staff_Btn_clicked()
{
    readWriteJson *RWJson = new readWriteJson();
    //获取员工账号密码
    QString account = ui->account_lineEdit->text();
    QString password = ui->password_lineEdit->text();

    static int count = 0;
    //校验账号密码
    if(RWJson->isAccountInJson(accountfilename,account)!= -1)
    {
        if(RWJson->isPasswordCorrect(accountfilename,account,password) == true)
        {
            QMessageBox::warning(this,"成功","success");
            staff_operation *sop = new staff_operation(this);
            sop->show();
            this->hide();
        }
        else
        {
            QMessageBox::warning(this,"fail","password wrong");
            count+=1;
        }
    }
    else
    {
        QMessageBox::warning(this,"fail","account wrong");
        count+=1;
    }
    if(count == 3)
    {
        QMessageBox::warning(this,"fail","you have try 3 times");
        this->close();
    }

}


//退出
void login::on_exit_btn_clicked()
{
    this->close();
}
