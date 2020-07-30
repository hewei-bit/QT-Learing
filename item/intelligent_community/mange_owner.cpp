#include "mange_owner.h"
#include "ui_mange_owner.h"
#include "login.h"
mange_owner::mange_owner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mange_owner)
{
    ui->setupUi(this);
    open_table();
}

mange_owner::~mange_owner()
{
    delete ui;
}

void mange_owner::open_table()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->clearContents();

    // 设置表头
    QStringList header;
    header<<tr("序列号")<<tr("姓名")<<("联系方式")<<tr("登录名")<<tr("密码")<<tr("生日")<<tr("地址")<<tr("RFID");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    qDebug() <<header;

    // 数据库读取载入
    QString sqlall = QString("SELECT * FROM owner");

    if(!sqlQuery.exec(sqlall))
    {
        qDebug() << "Error:Failed to SELECT record"<< database.lastError();
    }else
    {
        qDebug() << "success";
    }

    int i = 0;

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    while(sqlQuery.next())
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(sqlQuery.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(sqlQuery.value(1).toString()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(sqlQuery.value(2).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(sqlQuery.value(3).toString()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(sqlQuery.value(4).toString()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(sqlQuery.value(5).toString()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(sqlQuery.value(6).toString()));


        ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(i,2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(i,3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(i,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->item(i,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        i++;
    }
}

void mange_owner::on_back_clicked()
{
    ((login *)this->parentWidget())->show();
    this->close();
}
