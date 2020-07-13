#include "staff_operation.h"
#include "ui_staff_operation.h"

#include "readwritejson.h"

#include "login.h"


staff_operation::staff_operation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staff_operation)
{
    ui->setupUi(this);

    //获取货品列表
    readWriteJson *RWJson = new readWriteJson();
    QList<goods> goodslist;
    RWJson->goodsJsonTolist(filename,goodslist);

    showStock(filename);
    showShoppingcar();

    QStringList goodstypelist;
    QList<goods>::iterator iter;
    for (iter = goodslist.begin(); iter != goodslist.end(); ++iter) {
        ui->goods_name_comboBox->addItem(iter->getName());
        ui->goods_type_comboBox->addItem(iter->getSpecies());

//        for (int i = 0;i < ui->goods_type_comboBox->count();i++) {
//            goodstypelist.append(ui->goods_type_comboBox->itemText(i));
//        }
//        if( goodstypelist.contains(iter->getSpecies()))
//            continue;
    }



}

staff_operation::~staff_operation()
{
    delete ui;
}

void staff_operation::showStock(QString filename)
{
    //获取货品列表
    readWriteJson *RWJson = new readWriteJson();
    QList<goods> goodslist;
    /* 创建数据模型 */
    QStandardItemModel* model = new QStandardItemModel();
    /* 设置表格标题行(输入数据为QStringList类型) */
    model->setHorizontalHeaderLabels({"name","quantity","cost","price"});
    /* 自适应所有列，让它布满空间 */
    ui->goods_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    RWJson->goodsJsonTolist(filename,goodslist);

    /* 加载共10行数据，并每行有6列数据 */
    for(int i = 0;i<goodslist.size();i++)
    {
        /* 加载第一列(ID)数据 */
        model->setItem(i, 0, new QStandardItem(QString("%1").arg(goodslist.at(i).getID())));
        /* 加载第二列(species)数据 */
        model->setItem(i, 1, new QStandardItem(goodslist.at(i).getSpecies()));
        /* 加载第三列(name)数据 */
        model->setItem(i, 2, new QStandardItem(goodslist.at(i).getName()));
        /* 加载第四列(quantity)数据 */
        model->setItem(i, 3, new QStandardItem(QString("%1").arg(goodslist.at(i).getQuantity())));
        /* 加载第五列(cost)数据 */
        model->setItem(i, 4, new QStandardItem(QString("%1").arg(goodslist.at(i).getCost())));
        /* 加载第六列(price)数据 */
        model->setItem(i, 5, new QStandardItem(QString("%1").arg(goodslist.at(i).getPrice())));
        /* 加载第七列(unit)数据 */
        model->setItem(i, 6, new QStandardItem(goodslist.at(i).getUnit()));
    }


    /* 设置表格视图数据 */
    ui->goods_tableView->setModel(model);
}

void staff_operation::showShoppingcar()
{
    //获取货品列表
    readWriteJson *RWJson = new readWriteJson();

    QList<goods> goodslist;
    /* 创建数据模型 */
    QStandardItemModel* model = new QStandardItemModel();
    /* 设置表格标题行(输入数据为QStringList类型) */
    model->setHorizontalHeaderLabels({"name","quantity","cost","price"});
    /* 自适应所有列，让它布满空间 */
    ui->pay_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    RWJson->goodsJsonTolist(filename,goodslist);

    /* 加载共10行数据，并每行有6列数据 */
    for(int i = 0;i<goodslist.size();i++)
    {
        /* 加载第一列(ID)数据 */
        model->setItem(i, 0, new QStandardItem(QString("%1").arg(goodslist.at(i).getID())));
        /* 加载第二列(species)数据 */
        model->setItem(i, 1, new QStandardItem(goodslist.at(i).getSpecies()));
        /* 加载第三列(name)数据 */
        model->setItem(i, 2, new QStandardItem(goodslist.at(i).getName()));
        /* 加载第四列(quantity)数据 */
        model->setItem(i, 3, new QStandardItem(QString("%1").arg(goodslist.at(i).getQuantity())));
        /* 加载第五列(cost)数据 */
        model->setItem(i, 4, new QStandardItem(QString("%1").arg(goodslist.at(i).getCost())));
        /* 加载第六列(price)数据 */
        model->setItem(i, 5, new QStandardItem(QString("%1").arg(goodslist.at(i).getPrice())));
        /* 加载第七列(unit)数据 */
        model->setItem(i, 6, new QStandardItem(goodslist.at(i).getUnit()));
    }

    /* 设置表格视图数据 */
    ui->pay_tableView->setModel(model);
}


void staff_operation::on_wind_up_Btn_clicked()
{

}

void staff_operation::on_clean_Btn_clicked()
{

}

void staff_operation::on_delete_Btn_clicked()
{

}

void staff_operation::on_back_Btn_clicked()
{
    //返回登录界面
    login* log = new login();
    log->show();

    this->close();
}

void staff_operation::on_return_Btn_clicked()
{
    //返回结算界面
    ui->pay_tab->show();
}

void staff_operation::on_goods_type_comboBox_currentTextChanged(const QString &arg1)
{
    //将当前选项名赋值给变量str，输出当前选项名
        QString str = ui->goods_type_comboBox->currentText();
        qDebug()<<"Text:"<< str;
}

void staff_operation::on_goods_name_comboBox_currentTextChanged(const QString &arg1)
{
    //将当前选项名赋值给变量str，输出当前选项名
        QString str = ui->goods_name_comboBox->currentText();
        qDebug()<<"Text:"<< str;
}


