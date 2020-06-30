#include "set_mainwindow.h"
#include "ui_set_mainwindow.h"

set_MainWindow::set_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::set_MainWindow)
{
    ui->setupUi(this);
}

set_MainWindow::~set_MainWindow()
{
    delete ui;
}
