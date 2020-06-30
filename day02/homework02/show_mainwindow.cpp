#include "show_mainwindow.h"
#include "ui_show_mainwindow.h"

show_MainWindow::show_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::show_MainWindow)
{
    ui->setupUi(this);
}

show_MainWindow::~show_MainWindow()
{
    delete ui;
}
