#include "runningtime.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    runningTimer w;
    w.show();

    return a.exec();
}
