#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QtDebug>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase database =  QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("shcool.db");

    //[2] 打开数据库
    bool ok = database.open();

    if(!ok)
    {
        qDebug() << "open database failed"<< database.lastError();
    }

    //创建一个表，年级表（classandgrade）//建议用图形工具来完成表的创建
//    QSqlQuery query;
//    QString sqlTable = QString("CREATE TABLE classandgrade("
//                               "id integer PRIMARY KEY autoincrement NOT NULL,"
//                               "name TEXT NOT NULL,"
//                               "class TEXT NOT NULL,"
//                               "score REAL NOT NULL)");
//    if(!query.exec(sqlTable))
//    {
//        qDebug() << "create  table failed"<< database.lastError();
//    }

    //批量导入数据
    QSqlQuery query;
    //[1] 准备批量数据
    QStringList names;
    names << "张三"<<"李四"<<"王五"<<"张三三"<<"张三四"<<"张三五";
    QStringList classes;
    classes << "一年级一班"<<"一年级二班"<< "一年级一班"<<"一年级二班" << "一年级三班"<<"一年级四班";
   //[2]提前准备好要的执行的sql，bool QSqlQuery::prepare(const QString &query)
    query.prepare("INSERT INTO classandgrade(name,class,score)"
                  " VALUES(:name,:class,:score)");
    //[3] 使用bindValue来动态绑定占位符的值
    //void QSqlQuery::bindValue(const QString &placeholder,
    //const QVariant &val, QSql::ParamType paramType = QSql::In)
    foreach(QString name,names)
    {
        query.bindValue(":name",name);
        query.bindValue(":class",classes[qrand()%classes.length()]);
        query.bindValue(":score",(qrand()%101));

        //[4]
       if(! query.exec())//将每一条记录依次插入数库表中
       {
            qDebug() << "INSERT into  table failed"<< database.lastError();
       }
    }

    database.close(); //关闭操作库

}

MainWindow::~MainWindow()
{
    delete ui;
}
