#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QMainWindow>

namespace Ui {
class keyboard;
}

class keyboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit keyboard(QWidget *parent = nullptr);
    ~keyboard();

private:
    Ui::keyboard *ui;
};

#endif // KEYBOARD_H
