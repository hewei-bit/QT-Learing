#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readrfidid.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    while(1)
    {
        readCardId(); //在功能需求来进行读取

        sleep(1);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
