#include "mainwindow.h"
#include <QApplication>
#include "connectdatabase.h"
#include "edittablesqlmodel.h"
#include <QTableView>

void initalizeModel(QSqlQueryModel* model,const QString&sql)
{

    model->setQuery(sql);

    //设置表的列名
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("name"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("password"));
}

QTableView* createView(QSqlQueryModel* model,const QString& title = "")
{
    static int offset = 0;
    QTableView* view = new QTableView;
    view->setModel(model);
    view->setWindowTitle(title);
    view->move(100 + offset,100 + offset);

    offset += 20;
    view->show();
    return  view;
}

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
   //创建数据库表
  isCreateDatabaseTable("user","name","password");


  //创建一个可编辑的model对象
    editTableSqlModel editmodel;

    //初始model
    initalizeModel(&editmodel,"select * from user");

    //定义一个View
    createView(&editmodel,QObject::tr("可编辑的账户"));
    return a.exec();
}