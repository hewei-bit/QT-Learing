#include "selfinfo.h"
#include "ui_selfinfo.h"

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
