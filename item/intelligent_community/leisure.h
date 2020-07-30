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

private slots:
    void on_back_btn_clicked();

    void on_notepad_Btn_clicked();

    void on_calc_btn_clicked();

    void on_stopwatch_Btn_clicked();

    void on_game_Btn_clicked();

private:
    Ui::leisure *ui;
};

#endif // LEISURE_H
