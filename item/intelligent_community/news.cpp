#include "news.h"
#include "ui_news.h"
#include "intelligent_community.h"



news::news(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::news)
{
    ui->setupUi(this);
}

news::~news()
{
    delete ui;
}

void news::on_back_Btn_clicked()
{
    ((intelligent_community *)this->parentWidget())->show();
    this->close();
}
