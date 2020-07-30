#include "edit_table_model.h"



edit_table_model::edit_table_model(QObject *parent)
{

}

bool edit_table_model::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //根据表的列数，判断是否为有效列
    if(index.column() < 1 || index.column() > 5)
        return false;

    //为了获取得到id
    QModelIndex prinmaryKeyIndex = QSqlQueryModel::index(index.row(),0);
//    qDebug() <<  data(QSqlQueryModel::index(index.row(),0)).toInt();
    int id  = data(prinmaryKeyIndex).toInt();
    //清除操作
    clear();
    qDebug() << "=====" << id << "=====" << index.column();

    bool ok;

    if(index.column()==1)
    {
        //设置单元格上的内容
        ok = setNotifier(id,value.toString());
    }
    if(index.column()==2)
    {
        //设置单元格上的内容
        ok = setTele(id,value.toString());
    }
    refresh(index.column());

    return  ok;




}

Qt::ItemFlags edit_table_model::flags(const QModelIndex &index) const
{
    //获取当前条目的标志

   Qt::ItemFlags flags = QSqlQueryModel::flags(index);

   //根据自己表中的列数情况，设置对应列的标志
   if(index.column() == 1)
       flags |= Qt::ItemIsEditable; //给条目增加一个可编辑的标志
   if(index.column() == 2)
       flags |= Qt::ItemIsEditable; //给条目增加一个可编辑的标志
   if(index.column() == 3)
       flags |= Qt::ItemIsEditable; //给条目增加一个可编辑的标志

   if(index.column() == 4)
       flags |= Qt::ItemIsEditable; //给条目增加一个可编辑的标志

   if(index.column() == 5)
       flags |= Qt::ItemIsEditable; //给条目增加一个可编辑的标志

   return flags;
}

void edit_table_model::refresh(int i)
{
    setQuery("select * from business");
    if(i == 1)
    {
        setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
    }

    if(i == 2)
    {
         setHeaderData(2,Qt::Horizontal,QObject::tr("Tele"));
    }

}

bool edit_table_model::setAddress(int userId, const QString &useraddr)
{
    QSqlQuery query;
    query.prepare("update user set address = ? where id = ?");
    query.addBindValue(useraddr);
    query.addBindValue(userId);
    return  query.exec();
}

bool edit_table_model::setMisson(int userId, const QString &usermission)
{
    QSqlQuery query;
    query.prepare("update user set mission = ? where id = ?");
    query.addBindValue(usermission);
    query.addBindValue(userId);
    return  query.exec();
}

bool edit_table_model::setstate(int userId, const QString &userstate)
{
    QSqlQuery query;
    query.prepare("update user set state = ? where id = ?");
    query.addBindValue(userstate);
    query.addBindValue(userId);
    return  query.exec();
}

bool edit_table_model::setNotifier(int userId, const QString &userName)
{
    QSqlQuery query;
    query.prepare("update user set notifier = ? where id = ?");
    query.addBindValue(userName);
    query.addBindValue(userId);
    return  query.exec();
}

bool edit_table_model::setTele(int userId, const QString &usertele)
{
    QSqlQuery query;
    query.prepare("update user set tele = ? where id = ?");
    query.addBindValue(usertele);
    query.addBindValue(userId);
    return  query.exec();
}
