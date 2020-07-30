#ifndef CONNECTDATABASE_H
#define CONNECTDATABASE_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QtDebug>
#include <QFile>
#include <QSqlQuery>
#include "dbtable.h"

bool isCreateTable = false;
//实现与数据库相关的连接操作

static bool createConnection(const QString& dbName)
{
    QSqlDatabase db =   QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);

    if(!db.open())
    {
        qDebug() << "cannot open database";
        return  false;
    }
    return  true;
}

//static void isCreateDatabaseTable(const DbTale& dbtable)
static void isCreateDatabaseTable(const  QString & tableName,const QString& name
                                  ,const QString & password)
{
    QFile file;
    file.setFileName("./createTable.txt");


     if(file.open(QIODevice::ReadWrite))
     {
         QByteArray data = file.readAll();
         qDebug() << data;
        isCreateTable =  data.toUInt();
         qDebug() << isCreateTable;
     }

    if(!isCreateTable)
    {
        //创建表
         QString sqlTable = QString("CREATE TABLE %1("
                                    "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                                       "%2 TEXT NOT NULL,"
                                       "%3 TEXT NOT NULL)")
                                        .arg(tableName)
                                       .arg(name)
                                        .arg(password);
       qDebug() << sqlTable;
         QSqlQuery query;

         if(!query.exec(sqlTable))
         {
             qDebug() << "create  table failed";
         }else {
             //写入一个值，代表表已创建好，以后不重要重新来创建
             file.write("1");

             file.close();

             qDebug() << "create  table scuess";
       }


    }
}

#endif // CONNECTDATABASE_H
