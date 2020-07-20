#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QtDebug>
#include <QSqlQuery>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool openDataBase();

    void isCreateDatabaseTable();

    void insertData();

private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
    QFile file;
    bool isCreateTable; //表是否创建
};

#endif // MAINWINDOW_H
