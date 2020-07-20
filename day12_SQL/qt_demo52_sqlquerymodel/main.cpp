#include "mainwindow.h"
#include <QApplication>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
   // w.show();

      //打开数据库
    if(!createConnection("stafDB.db"))
    {
        return  1;
    }


    QSqlQueryModel* model = new QSqlQueryModel;
    model->setQuery("select name,password from user"); //从表中，查询出字段为name password数据
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Name"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PassWord"));
   //下标是从0开始
  qDebug() <<  model->record(0).value("name").toString();

   QTableView* view = new QTableView;
   view->setModel(model);
   view->show();

    return a.exec();
}
