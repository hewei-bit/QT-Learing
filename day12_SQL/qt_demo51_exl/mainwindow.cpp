#include "mainwindow.h"
#include "ui_mainwindow.h"


bool MainWindow::openDataBase()
{
    database =  QSqlDatabase::addDatabase("QSQLITE");
   database.setDatabaseName("shcool.db");

   //[2] 打开数据库
   bool ok = database.open();

   if(!ok)
   {
       qDebug() << "open database failed"<< database.lastError();
   }
   return ok;
}

void MainWindow::isCreateDatabaseTable()
{
    if(!isCreateTable)
    {
        //创建表
         QString sqlTable = QString("CREATE TABLE COMPANY("
                                       "id INTEGER PRIMARY KEY AUTOINCREMENT  NOT NULL,"
                                       "name TEXT NOT NULL,"
                                       "age INT NOT NULL,"
                                       "address CHAR(50),"
                                       "salary REAL)");

         QSqlQuery query;

         if(!query.exec(sqlTable))
         {
             qDebug() << "create  table failed"<< database.lastError();
         }else {
             //写入一个值，代表表已创建好，以后不重要重新来创建
             file.write("1");

             file.close();

             qDebug() << "create  table scuess";
       }


    }
}

void MainWindow::insertData()
{
    QSqlQuery query;
    //[1] 准备批量数据
    QStringList names;
    names << "张三"<<"李四"<<"王五"<<"张三三";
    QStringList addres;
    addres << "广东省佛山市"<<"广东省佛山市"<< "广东省东莞市"<<"广东省江门市" ;
   //[2]提前准备好要的执行的sql，bool QSqlQuery::prepare(const QString &query)
    query.prepare("INSERT INTO COMPANY(name,age,address,salary)"
                  " VALUES(?,?,?,?)");
    //[3] 使用bindValue来动态绑定占位符的值
    //void QSqlQuery::bindValue(const QString &placeholder,
    //const QVariant &val, QSql::ParamType paramType = QSql::In)
    foreach(QString name,names)
    {
        query.bindValue(0,name);
        query.bindValue(1,qrand() % 65);
        query.bindValue(2,addres[qrand()%addres.length()]);
        query.bindValue(3,(qrand()%10000));

        //[4]
       if(! query.exec())//将每一条记录依次插入数库表中
       {
            qDebug() << "INSERT into  table failed"<< database.lastError();
       }
    }
//关闭操作库
    database.close();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     openDataBase();


    file.setFileName("../createTable.txt");


     if(file.open(QIODevice::ReadWrite))
     {
         QByteArray data = file.readAll();
         qDebug() << data;
        isCreateTable =  data.toUInt();
         qDebug() << isCreateTable;
     }

     //是否要创建表
     isCreateDatabaseTable();

     //
     //批量导入数据
     insertData();



}

MainWindow::~MainWindow()
{
    delete ui;
}
