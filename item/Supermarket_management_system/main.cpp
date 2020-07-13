#include "login.h"
#include "manager_operation.h"
#include "staff_operation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    w.show();

//    staff_operation so;
//    so.show();

    return a.exec();
}
