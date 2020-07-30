#ifndef NEWOWNER_H
#define NEWOWNER_H

#include <QWidget>

namespace Ui {
class newowner;
}

class newowner : public QWidget
{
    Q_OBJECT

public:
    explicit newowner(QWidget *parent = nullptr);
    ~newowner();

private:
    Ui::newowner *ui;
};

#endif // NEWOWNER_H
