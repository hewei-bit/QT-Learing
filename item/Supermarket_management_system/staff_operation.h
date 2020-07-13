#ifndef STAFF_OPERATION_H
#define STAFF_OPERATION_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QStandardItemModel>


#include "goods.h"






namespace Ui {
class staff_operation;
}

class staff_operation : public QMainWindow
{
    Q_OBJECT

public:
    explicit staff_operation(QWidget *parent = nullptr);
    ~staff_operation();

    void showStock(QString filename);

    void showShoppingcar();

private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_wind_up_Btn_clicked();

    void on_clean_Btn_clicked();

    void on_delete_Btn_clicked();

    void on_back_Btn_clicked();

    void on_return_Btn_clicked();

    void on_goods_type_comboBox_currentTextChanged(const QString &arg1);

    void on_goods_name_comboBox_currentTextChanged(const QString &arg1);



private:
    Ui::staff_operation *ui;
    QString filename = "./resources/goods.json";
};

#endif // STAFF_OPERATION_H
