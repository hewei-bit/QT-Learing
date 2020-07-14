#ifndef NEW_GOODS_H
#define NEW_GOODS_H

#include <QMainWindow>

namespace Ui {
class new_goods;
}

class new_goods : public QMainWindow
{
    Q_OBJECT

public:
    explicit new_goods(QWidget *parent = nullptr);
    ~new_goods();

private slots:
    void on_return_Btn_clicked();

private:
    Ui::new_goods *ui;
};

#endif // NEW_GOODS_H
