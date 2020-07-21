#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCamera>
#include <QCameraInfo>
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    qDebug() << cameras.size();
    foreach (const QCameraInfo &cameraInfo, cameras) {
            qDebug() << cameraInfo.deviceName();
            qDebug() << cameraInfo.description();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
