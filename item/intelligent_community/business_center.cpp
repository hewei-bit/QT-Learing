#include "business_center.h"
#include "ui_business_center.h"
#include "login.h"

#include "mange_business.h"
#include "mange_owner.h"

business_center::business_center(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::business_center)
{
    ui->setupUi(this);
}

business_center::~business_center()
{
    delete ui;
}

void business_center::on_owner_manage_Btn_clicked()
{
    mange_owner *mo = new mange_owner(this);
    mo->show();
    this->hide();
}

void business_center::on_business_Btn_clicked()
{
    mange_business *mb = new mange_business(this);
    mb->show();
    this->hide();
}

void business_center::on_back_Btn_clicked()
{
    //显示登录界面
    ((login *)this->parentWidget())->show();


    this->close();
}
