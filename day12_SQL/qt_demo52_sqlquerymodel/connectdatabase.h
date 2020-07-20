#ifndef CONNECTDATABASE_H
#define CONNECTDATABASE_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QtDebug>
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
#endif // CONNECTDATABASE_H
