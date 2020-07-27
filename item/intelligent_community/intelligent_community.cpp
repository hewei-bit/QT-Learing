#include "intelligent_community.h"
#include "ui_intelligent_community.h"

intelligent_community::intelligent_community(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::intelligent_community)
{
    ui->setupUi(this);
}

intelligent_community::~intelligent_community()
{
    delete ui;
}
