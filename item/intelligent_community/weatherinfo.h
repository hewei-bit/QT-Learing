#ifndef WEATHERINFO_H
#define WEATHERINFO_H

#include <QWidget>

namespace Ui {
class WeatherInfo;
}

class WeatherInfo : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherInfo(QWidget *parent = nullptr);
    ~WeatherInfo();

private:
    Ui::WeatherInfo *ui;
};

#endif // WEATHERINFO_H
