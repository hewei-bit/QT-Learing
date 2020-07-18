#ifndef ITEMFORM_H
#define ITEMFORM_H

#include <QWidget>

namespace Ui {
class itemform;
}

class itemform : public QWidget
{
    Q_OBJECT

public:
    explicit itemform(QWidget *parent = nullptr);
    ~itemform();
    void setItem(int id,QString name,int age,QString addr,int salary);

private:
    Ui::itemform *ui;
};

#endif // ITEMFORM_H
