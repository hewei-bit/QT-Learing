#include "selfinfo.h"
#include "ui_selfinfo.h"
#include "intelligent_community.h"



selfinfo::selfinfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::selfinfo)
{
    ui->setupUi(this);
}

selfinfo::~selfinfo()
{
    delete ui;
}

void selfinfo::on_back_Btn_clicked()
{
    ((intelligent_community *)this->parentWidget())->show();
    this->close();
}
