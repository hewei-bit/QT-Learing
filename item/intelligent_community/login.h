#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_property_Btn_clicked();

    void on_owner_Btn_clicked();



    void on_password_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_exit_btn_clicked();

    void on_account_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_account_lineEdit_editingFinished();

    void on_password_lineEdit_editingFinished();

private:
    Ui::login *ui;
};


static bool account_keyboard = false;
static bool password_keyboard = false;
#endif // LOGIN_H
