#ifndef NEWS_H
#define NEWS_H

#include <QMainWindow>

namespace Ui {
class news;
}

class news : public QMainWindow
{
    Q_OBJECT

public:
    explicit news(QWidget *parent = nullptr);
    ~news();

private slots:
    void on_back_Btn_clicked();

private:
    Ui::news *ui;
};

#endif // NEWS_H
