#ifndef SHOW_MAINWINDOW_H
#define SHOW_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class show_MainWindow;
}

class show_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit show_MainWindow(QWidget *parent = nullptr);
    ~show_MainWindow();

private:
    Ui::show_MainWindow *ui;
};

#endif // SHOW_MAINWINDOW_H
