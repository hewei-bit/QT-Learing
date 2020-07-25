#include "myserial.h"
#include "ui_myserial.h"

myserial::myserial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myserial)
{
    ui->setupUi(this);
}

myserial::~myserial()
{
    delete ui;
}
