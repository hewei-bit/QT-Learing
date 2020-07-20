#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
void MainWindow::openDataBase()
{
    QSqlDatabase database =  QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("test.db");

    //[2] 打开数据库
    bool ok = database.open();

    if(!ok)
    {
        qDebug() << "open database failed"<< database.lastError();
    }

    //[3] 给数据库创建表 COMPANY
    /*
    CREATE TABLE COMPANY(
    ID INT PRIMARY KEY     NOT NULL,
    NAME           TEXT    NOT NULL,
    AGE            INT     NOT NULL,
    ADDRESS        CHAR(50),
    SALARY         REAL
  );

    */
    //情况一：创建表时，没有设置主键
 //   QString sqlTable = QString("CREATE TABLE COMPANY("
 //                              "NAME TEXT NOT NULL,"
 //                              "AGE INT NOT NULL,"
 //                              "ADDRESS CHAR(50),"
 //                              "SALARY REAL)");
     //情况二，创建表时，设置一个主键,如果将主键设置为NOT NULL，那么在插入数据到表中时，
    //一定要给它赋值，并且该值唯一
 //      QString sqlTable = QString("CREATE TABLE COMPANY1("
 //                                 "ID INT PRIMARY KEY NOT NULL,"
 //                                 "NAME TEXT NOT NULL,"
 //                                 "AGE INT NOT NULL,"
 //                                 "ADDRESS CHAR(50),"
 //                                 "SALARY REAL)");

       //情况三，创建表时，设置一个主键，将它设置为自增长，在插入数据时，可以不用给它赋值
//    QString sqlTable = QString("CREATE TABLE COMPANY2("
//                               "ID integer PRIMARY KEY autoincrement NOT NULL,"
//                               "NAME TEXT NOT NULL,"
//                               "AGE INT NOT NULL,"
//                               "ADDRESS CHAR(50),"
//                               "SALARY REAL)");
//    QSqlQuery sqlQuery;

//   // sqlQuery.prepare(""); //提前准备好要执行的命令
//   // sqlQuery.exec(); 命令执行
//    if(!sqlQuery.exec(sqlTable))
//    {
//        qDebug() << "crate table failed"<<database.lastError();
//    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //[1] 打开数据库,通常情况 下，这个函数只需要执行一次
   openDataBase();
   //插入操作
    //QSqlQuery(const QString &query = QString(), QSqlDatabase db = QSqlDatabase())
    QSqlQuery query; //在创建对象时，默认设置了一个数据库对象，默认进行关联

    if(!query.exec("INSERT INTO COMPANY2(NAME,AGE,ADDRESS,SALARY) VALUES('li4',20,'广东省江门市',10000)"))
    {
        qDebug() << "INSERT INTO failed";
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}
