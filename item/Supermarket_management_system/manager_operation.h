#ifndef MANAGER_OPERATION_H
#define MANAGER_OPERATION_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QWidget>

#include "goods.h"
#include "staff.h"

namespace Ui {
class manager_operation;
}

class manager_operation : public QMainWindow
{
    Q_OBJECT

public:
    explicit manager_operation(QWidget *parent = nullptr);
    ~manager_operation();

    //显示员工
    void show_staff(QList<Staff> &slist);
    //显示库存
    void show_stock(QList<goods> &glist);

signals:
    void sendAstaff(Staff anyone);

    void sendAgoods(goods anything);

private slots:
    void on_add_goods_Btn_clicked();

    void on_return_Btn_2_clicked();

    void on_add_staff_Btn_clicked();

    void on_delete__staff_Btn_clicked();

    void on_return_Btn_clicked();

public slots:
    void addToStaffList(Staff anyone);

    void addToGoodsList(goods anyone);

private:
    Ui::manager_operation *ui;
    QString account_filename = "./resources/account.json";
    QString goods_filename = "./resources/goods.json";


};

#endif // MANAGER_OPERATION_H
