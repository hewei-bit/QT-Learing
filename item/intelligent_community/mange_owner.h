#ifndef MANGE_OWNER_H
#define MANGE_OWNER_H

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlError>
#include <QtDebug>
#include <QFile>
#include <QSqlQuery>
#include <QApplication>
#include <QTableView>
#include <QSqlQueryModel>

namespace Ui {
class mange_owner;
}

class mange_owner : public QMainWindow
{
    Q_OBJECT

public:
    explicit mange_owner(QWidget *parent = nullptr);
    ~mange_owner();

    void open_table();

private slots:
    void on_back_clicked();

private:
    Ui::mange_owner *ui;

    QString dbname = "../intelligent_community/intell_com.db";
    QSqlDatabase database;
    QSqlQuery sqlQuery;
    QString sqlSelect;
    QString sqlInsert;
    QString sqlupdate;
    QString sqldelete;
};

#endif // MANGE_OWNER_H
