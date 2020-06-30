#include "teacher_system_mainwindow.h"
#include "ui_teacher_system_mainwindow.h"

teacher_system_MainWindow::teacher_system_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teacher_system_MainWindow)
{
    ui->setupUi(this);
}

teacher_system_MainWindow::~teacher_system_MainWindow()
{
    delete ui;
}
