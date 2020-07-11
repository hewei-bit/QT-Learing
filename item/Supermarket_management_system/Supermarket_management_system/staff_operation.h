#ifndef STAFF_OPERATION_H
#define STAFF_OPERATION_H

#include <QMainWindow>

namespace Ui {
class staff_operation;
}

class staff_operation : public QMainWindow
{
    Q_OBJECT

public:
    explicit staff_operation(QWidget *parent = nullptr);
    ~staff_operation();

private slots:
    void on_tableWidget_itemClicked(QTableWidgetItem *item);

private:
    Ui::staff_operation *ui;
};

#endif // STAFF_OPERATION_H
