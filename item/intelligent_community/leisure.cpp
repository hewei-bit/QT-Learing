#include "leisure.h"
#include "ui_leisure.h"
#include "intelligent_community.h"

#include "nodepad.h"
#include "runningtime.h"
#include "caular.h"

#include "character_calc_mainwindow.h"

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
    Nodepad * np = new Nodepad(this);
    np->show();
    this->hide();
}

void leisure::on_calc_btn_clicked()
{
    Caular *ca = new Caular(this);
    ca->show();
    this->hide();
}

void leisure::on_stopwatch_Btn_clicked()
{
    runningTimer *runT = new runningTimer(this);
    runT->show();
    this->hide();
}

void leisure::on_game_Btn_clicked()
{
    character_calc_MainWindow *w = new character_calc_MainWindow(this);
    w->show();
    this->hide();
}
