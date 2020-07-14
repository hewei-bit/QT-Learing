#include "new_goods.h"
#include "ui_new_goods.h"
#include "manager_operation.h"



new_goods::new_goods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::new_goods)
{
    ui->setupUi(this);
}

new_goods::~new_goods()
{
    delete ui;
}

void new_goods::on_return_Btn_clicked()
{
    //返回登录界面
//    login* log = new login();
//    log->show();
    ((manager_operation*)this->parentWidget())->show(); //QWidget*
    this->close();
}
