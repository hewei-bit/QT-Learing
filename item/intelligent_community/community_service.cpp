#include "community_service.h"
#include "ui_community_service.h"

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
