#ifndef MANAGER_OPERATION_H
#define MANAGER_OPERATION_H

#include <QMainWindow>

namespace Ui {
class manager_operation;
}

class manager_operation : public QMainWindow
{
    Q_OBJECT

public:
    explicit manager_operation(QWidget *parent = nullptr);
    ~manager_operation();

private slots:
    void on_add_goods_Btn_clicked();

    void on_return_Btn_2_clicked();

    void on_add_staff_Btn_clicked();

    void on_delete__staff_Btn_clicked();

    void on_return_Btn_clicked();

private:
    Ui::manager_operation *ui;
};

#endif // MANAGER_OPERATION_H
