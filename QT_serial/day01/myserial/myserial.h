#ifndef MYSERIAL_H
#define MYSERIAL_H

#include <QMainWindow>

namespace Ui {
class myserial;
}

class myserial : public QMainWindow
{
    Q_OBJECT

public:
    explicit myserial(QWidget *parent = nullptr);
    ~myserial();

private:
    Ui::myserial *ui;
};

#endif // MYSERIAL_H
