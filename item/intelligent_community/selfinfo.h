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

private:
    Ui::selfinfo *ui;
};

#endif // SELFINFO_H
