#include "leisure.h"
#include "ui_leisure.h"

leisure::leisure(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::leisure)
{
    ui->setupUi(this);
}

leisure::~leisure()
{
    delete ui;
}
