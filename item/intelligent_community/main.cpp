#include "advertisement.h"

#include "intelligent_community.h"
#include "community_service.h"

#include "login.h"
#include "caular.h"
#include "news.h"
#include <QFile>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //定制皮肤在程序运行之前设置
    QFile file(":/qss/mystyle.qss");
    file.open(QIODevice::ReadOnly);
    QByteArray array =  file.readAll();
    // #define qApp (static_cast<QApplication *>(QCoreApplication::instance()))
    qApp->setStyleSheet(array);

    login lin;
    lin.show();


//    Caular w;
//    w.show();

//    news n;
//    n.show();

//    community_service cs;
//    cs.show();

//    intelligent_community w;
//    w.show();

//    advertisement ad;
//    ad.show();



    return a.exec();
}
