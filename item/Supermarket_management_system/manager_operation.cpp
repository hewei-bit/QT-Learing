#include "manager_operation.h"
#include "ui_manager_operation.h"

#include "readwritejson.h"


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

}

void manager_operation::on_return_Btn_2_clicked()
{

}

void manager_operation::on_add_staff_Btn_clicked()
{

}

void manager_operation::on_delete__staff_Btn_clicked()
{

}

void manager_operation::on_return_Btn_clicked()
{

}
