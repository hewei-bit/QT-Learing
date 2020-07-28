#include "leisure.h"
#include "ui_leisure.h"
#include "intelligent_community.h"
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

void leisure::on_back_btn_clicked()
{
        ((intelligent_community *)this->parentWidget())->show();
        this->close();
}

void leisure::on_notepad_Btn_clicked()
{

}
