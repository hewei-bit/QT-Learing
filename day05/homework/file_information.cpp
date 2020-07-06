#include "file_information.h"
#include "ui_file_information.h"

file_information::file_information(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::file_information)
{
    ui->setupUi(this);
    this->resize(this->width(),this->height());
}

file_information::~file_information()
{
    delete ui;
}

void file_information::show_file_info(QFileInfo fileinfo)
{

    ui->label->setText(fileinfo.fileName());
    qDebug() << fileinfo.fileName();
    int size = fileinfo.size()/1024;
    QString ssize = QString("%1kb").arg(size);
    ui->label_2->setText(ssize);
    qDebug() << fileinfo.size();
}
void file_information::show_file_info_1(QFileInfo fileinfo)
{

    ui->label->setText(fileinfo.fileName());
    qDebug() << fileinfo.fileName();
//    int size = fileinfo.size()/1024;
//    QString ssize = QString("%1kb").arg(size);
//    ui->label_2->setText(ssize);
//    qDebug() << fileinfo.size();
}
