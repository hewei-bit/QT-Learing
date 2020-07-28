#include "login.h"
#include "ui_login.h"
#include "intelligent_community.h"
#include "advertisement.h"


login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{


    ui->setupUi(this);


    this->setWindowIcon(QIcon(":/pic/school.png"));
    QImage img;
    img.load(":/pic/school.png");
    QPixmap originalPixmap = QPixmap::fromImage(img);
    ui->pic_label->setPixmap(originalPixmap.scaled(ui->pic_label->size(),
                         Qt::IgnoreAspectRatio,
                         Qt::SmoothTransformation));

    //播广告
    advertisement *adv = new advertisement(this);
    adv->show();

    this->hide();

    ui->widget_4->hide();



}

login::~login()
{
    delete ui;
}

void login::on_property_Btn_clicked()
{

}

void login::on_owner_Btn_clicked()
{

    intelligent_community * intc = new intelligent_community(this);
    intc->show();

    this->hide();
}



void login::on_password_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    ui->widget_4->show();
}

void login::on_exit_btn_clicked()
{
    this->close();
}

void login::on_account_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    ui->widget_4->show();
}

void login::on_account_lineEdit_editingFinished()
{
    ui->widget_4->hide();
}

void login::on_password_lineEdit_editingFinished()
{
    ui->widget_4->hide();
}
