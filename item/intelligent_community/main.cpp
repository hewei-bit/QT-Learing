#include "intelligent_community.h"
#include "advertisement.h"
#include "community_service.h"


#include "login.h"
#include "QFile"



#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //定制皮肤在程序运行之前设置
//    QFile file(":/qss/mystyle.qss");
//    file.open(QIODevice::ReadOnly);
//    QByteArray array =  file.readAll();
//    // #define qApp (static_cast<QApplication *>(QCoreApplication::instance()))
//    qApp->setStyleSheet(array);



    login log;
    log.show();

//    intelligent_community w;
//    w.show();

//    advertisement ad;
//    ad.show();



    return a.exec();
}
