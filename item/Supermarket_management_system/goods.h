#ifndef GOODS_H
#define GOODS_H

#include <iostream>

//文件IO
#include <QFile>
#include <QTextCodec>

using namespace std;

class goods
{
public:

    goods(int ID=1000,QString species="",QString name="",
          int quantity=0,int cost=0,int price=0,QString unit="");
    ~goods();

    bool isgoodsInrepository(goods goodsname,QList<goods>& glist);
    void addgoods(goods goodsname,QList<goods>& glist);
    void deletegoods(goods goodsname,QList<goods>& glist);


    QString getName() const;

    int getQuantity() const;

    int getCost() const;

    int getPrice() const;

    int getID() const;

    QString getSpecies() const;

    QString getUnit() const;

private:
    int ID;
    QString species;
    QString name;
    int quantity;
    int cost;
    int price;
    QString unit;

};

#endif // GOODS_H
