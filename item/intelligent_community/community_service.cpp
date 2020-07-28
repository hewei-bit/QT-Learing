#include "community_service.h"
#include "ui_community_service.h"
#include "intelligent_community.h"



Community_service::Community_service(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Community_service)
{
    ui->setupUi(this);
}

Community_service::~Community_service()
{
    delete ui;
}

void Community_service::on_back_Btn_clicked()
{
    ((intelligent_community *)this->parentWidget())->show();
    this->close();
}
