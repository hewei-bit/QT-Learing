#ifndef COMMUNITY_SERVICE_H
#define COMMUNITY_SERVICE_H

#include <QWidget>

namespace Ui {
class Community_service;
}

class Community_service : public QWidget
{
    Q_OBJECT

public:
    explicit Community_service(QWidget *parent = nullptr);
    ~Community_service();

private slots:
    void on_back_Btn_clicked();

private:
    Ui::Community_service *ui;
};

#endif // COMMUNITY_SERVICE_H
