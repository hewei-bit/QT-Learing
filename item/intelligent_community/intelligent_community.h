#ifndef INTELLIGENT_COMMUNITY_H
#define INTELLIGENT_COMMUNITY_H

#include <QMainWindow>

namespace Ui {
class intelligent_community;
}

class intelligent_community : public QMainWindow
{
    Q_OBJECT

public:
    explicit intelligent_community(QWidget *parent = nullptr);
    ~intelligent_community();

private:
    Ui::intelligent_community *ui;
};

#endif // INTELLIGENT_COMMUNITY_H
