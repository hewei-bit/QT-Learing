#include "sreen_shot.h"
#include "ui_sreen_shot.h"



sreen_shot::sreen_shot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sreen_shot)
{
    ui->setupUi(this);
}

sreen_shot::~sreen_shot()
{
    delete ui;
}

void sreen_shot::on_startbtn_clicked()
{
    QScreen *sreen = QGuiApplication::primaryScreen();

}

void sreen_shot::on_save_btn_clicked()
{

}



void sreen_shot::on_exit_btn_clicked()
{

}

void sreen_shot::on_checkBox_stateChanged(int arg1)
{

}
