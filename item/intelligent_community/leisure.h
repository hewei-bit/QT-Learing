#ifndef LEISURE_H
#define LEISURE_H

#include <QMainWindow>

namespace Ui {
class leisure;
}

class leisure : public QMainWindow
{
    Q_OBJECT

public:
    explicit leisure(QWidget *parent = nullptr);
    ~leisure();

private:
    Ui::leisure *ui;
};

#endif // LEISURE_H
