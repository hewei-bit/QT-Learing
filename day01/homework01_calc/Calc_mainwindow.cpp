#include "calc_mainwindow.h"
#include "ui_calc_mainwindow.h"

Calc_MainWindow::Calc_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calc_MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_0->click();
}

Calc_MainWindow::~Calc_MainWindow()
{
    delete ui;
}
