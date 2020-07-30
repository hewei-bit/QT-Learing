#ifndef MANGE_BUSINESS_H
#define MANGE_BUSINESS_H

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
class mange_business;
}

class mange_business : public QMainWindow
{
    Q_OBJECT

public:
    explicit mange_business(QWidget *parent = nullptr);
    ~mange_business();

    void open_table();

private slots:
    void on_back_clicked();

private:
    Ui::mange_business *ui;

    QString dbname = "../intelligent_community/intell_com.db";
    QSqlDatabase database;
    QSqlQuery sqlQuery;
    QString sqlSelect;
    QString sqlInsert;
    QString sqlupdate;
    QString sqldelete;
};

#endif // MANGE_BUSINESS_H
