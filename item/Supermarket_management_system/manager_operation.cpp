#include "manager_operation.h"
#include "ui_manager_operation.h"
#include "login.h"
#include "readwritejson.h"
#include "new_goods.h"
#include "new_staff.h"
#include "goods.h"

/* 创建结算界面数据模型 */
QStandardItemModel* staff_model = new QStandardItemModel();
//库存界面数据模型
QStandardItemModel* stock_model = new QStandardItemModel();


//货物链表
QList<goods> goodslist_1;


manager_operation::manager_operation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manager_operation)
{
    ui->setupUi(this);

}

manager_operation::~manager_operation()
{
    delete ui;
}

void manager_operation::on_add_goods_Btn_clicked()
{
    //跳转至新建货品界面
    new_goods *newgoods = new new_goods(this);
    newgoods->show();

    this->hide();
}

void manager_operation::on_return_Btn_2_clicked()
{
    //返回登录界面
//    login* log = new login();
//    log->show();
    ((login*)this->parentWidget())->show(); //QWidget*
    this->close();
}

void manager_operation::on_add_staff_Btn_clicked()
{
    //跳转至新增员工界面
    new_goods *newgoods = new new_goods(this);
    newgoods->show();
    this->hide();
}

void manager_operation::on_delete__staff_Btn_clicked()
{

}

void manager_operation::on_return_Btn_clicked()
{
    //返回登录界面
//    login* log = new login();
//    log->show();
    ((login*)this->parentWidget())->show(); //QWidget*
    this->close();
}
