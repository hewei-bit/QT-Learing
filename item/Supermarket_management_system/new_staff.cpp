#include "new_staff.h"
#include "ui_new_staff.h"
#include "manager_operation.h"
new_staff::new_staff(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::new_staff)
{
    ui->setupUi(this);
}

new_staff::~new_staff()
{
    delete ui;
}

void new_staff::on_register_Btn_clicked()
{

}

void new_staff::on_exit_btn_clicked()
{
    //返回登录界面
//    login* log = new login();
//    log->show();
    ((manager_operation*)this->parentWidget())->show(); //QWidget*
    this->close();
}
