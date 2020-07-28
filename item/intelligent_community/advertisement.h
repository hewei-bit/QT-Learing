#ifndef ADVERTISEMENT_H
#define ADVERTISEMENT_H

#include <QWidget>

namespace Ui {
class advertisement;
}

class advertisement : public QWidget
{
    Q_OBJECT

public:
    explicit advertisement(QWidget *parent = nullptr);
    ~advertisement();

private:
    Ui::advertisement *ui;
};

#endif // ADVERTISEMENT_H
