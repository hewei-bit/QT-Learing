#include "bill.h"
#include "ui_bill.h"

bill::bill(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bill)
{
    ui->setupUi(this);
}

bill::~bill()
{
    delete ui;
}

void bill::on_return_Btn_clicked()
{
    this->close();
}

void bill::showbill(QList<goods> &glist)
{

}
