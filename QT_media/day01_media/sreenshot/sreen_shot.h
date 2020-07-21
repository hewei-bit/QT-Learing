#ifndef SREEN_SHOT_H
#define SREEN_SHOT_H
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QPixmap>
#include <QMainWindow>

namespace Ui {
class sreen_shot;
}

class sreen_shot : public QMainWindow
{
    Q_OBJECT

public:
    explicit sreen_shot(QWidget *parent = nullptr);
    ~sreen_shot();

private slots:
    void on_startbtn_clicked();

    void on_save_btn_clicked();

    void on_pushButton_3_clicked();

    void on_exit_btn_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::sreen_shot *ui;
};

#endif // SREEN_SHOT_H
