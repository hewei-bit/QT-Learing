#include "staff_operation.h"
#include "ui_staff_operation.h"

staff_operation::staff_operation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staff_operation)
{
    ui->setupUi(this);
}

staff_operation::~staff_operation()
{
    delete ui;
}

void staff_operation::on_tableWidget_itemClicked(QTableWidgetItem *item)
{

}
