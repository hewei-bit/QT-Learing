#include "bill.h"
#include "ui_bill.h"

bill::bill(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bill)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/pic/school.png"));
    this->setFixedSize(691,587);
}

bill::~bill()
{
    delete ui;
}

void bill::on_return_Btn_clicked()
{
    this->close();
}

void bill::showbill(QList<goods> &glist)
{
    QList<goods>::iterator iter;
    int all_sum = 0;
    //标题
    QListWidgetItem *item_1 = new QListWidgetItem;
    QString title = QString("名称    单价    数量    合计");
    item_1->setText(title);
    ui->listWidget->addItem(item_1);
    //打印清单
    for (iter = glist.begin();iter!= glist.end();++iter) {

        QListWidgetItem *item = new QListWidgetItem;
        QString name = iter->getName();
        int num = iter->getQuantity();
        int price = iter->getPrice();
        int single_sum = iter->getSingle_sum();
        all_sum+=single_sum;
        QString allofone = QString(name+"    %1    %2    %3").arg(price).arg(num).arg(single_sum);
        item->setText(allofone);
        ui->listWidget->addItem(item);
    }

    //打印总和
//    QListWidgetItem *item_2 = new QListWidgetItem;
    QString allofsum = QString("总计： %1").arg(all_sum);
//    item_2->setText(allofsum);
//    ui->listWidget->addItem(item_2);
    ui->label->setText(allofsum);
}
