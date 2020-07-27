#include "intelligent_community.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    intelligent_community w;
    w.show();

    return a.exec();
}
