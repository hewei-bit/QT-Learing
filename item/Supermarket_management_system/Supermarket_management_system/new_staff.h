#ifndef NEW_STAFF_H
#define NEW_STAFF_H

#include <QMainWindow>

namespace Ui {
class new_staff;
}

class new_staff : public QMainWindow
{
    Q_OBJECT

public:
    explicit new_staff(QWidget *parent = nullptr);
    ~new_staff();

private slots:
    void on_register_Btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::new_staff *ui;
};

#endif // NEW_STAFF_H
