#include "weatherinfo.h"
#include "ui_weatherinfo.h"

WeatherInfo::WeatherInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherInfo)
{
    ui->setupUi(this);
}

WeatherInfo::~WeatherInfo()
{
    delete ui;
}
