#include "newowner.h"
#include "ui_newowner.h"

newowner::newowner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newowner)
{
    ui->setupUi(this);
}

newowner::~newowner()
{
    delete ui;
}
