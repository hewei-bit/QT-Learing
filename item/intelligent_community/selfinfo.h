#ifndef SELFINFO_H
#define SELFINFO_H

#include <QMainWindow>

namespace Ui {
class selfinfo;
}

class selfinfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit selfinfo(QWidget *parent = nullptr);
    ~selfinfo();

private slots:
    void on_back_Btn_clicked();

private:
    Ui::selfinfo *ui;
};

#endif // SELFINFO_H
