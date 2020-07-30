#include "selfinfo.h"
#include "ui_selfinfo.h"

#include "intelligent_community.h"

selfinfo::selfinfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::selfinfo)
{
    ui->setupUi(this);

}

selfinfo::~selfinfo()
{
    delete ui;
}

void selfinfo::getname(QString &name)
{
    mmmname = name;

    //     数据库读取载入
    QString sqlall = QString("SELECT * FROM owner");

    if(!sqlQuery.exec(sqlall))
    {
        qDebug() << "Error:Failed to SELECT record"<< database.lastError();
    }else
    {
        qDebug() << "success";
    }


    QString sqlorder = QString("SELECT * FROM owner where name = '%1' ").arg(mmmname);

    if(!sqlQuery.exec(sqlorder))
    {
        qDebug() << "Error:Failed to SELECT record"<< database.lastError();
    }else
    {
        qDebug() << "success6666";
    }
    sqlQuery.next();
    qDebug()<<sqlQuery.value(1)<<sqlQuery.value(2)<<sqlQuery.value(5)<<sqlQuery.value(4);

    ui->name_label->setText(sqlQuery.value(1).toString());
    ui->tele_label->setText(sqlQuery.value(2).toString());
    ui->birth_label->setText(sqlQuery.value(5).toString());
    ui->addr_label->setText(sqlQuery.value(6).toString());

}

void selfinfo::on_back_Btn_clicked()
{
    ((intelligent_community *)this->parentWidget())->show();
    this->close();
}
