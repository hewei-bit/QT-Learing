#include "goods.h"



goods::goods(int ID,QString species,QString name,
             int quantity,int cost,int price,QString unit):
    ID(ID),species(species),name(name),
    quantity(quantity),cost(cost),price(price),unit(unit)
{}

goods::~goods()
{

}

bool goods::isgoodsInrepository(goods goodsname, QList<goods> &glist)
{
    for (int i = 0; i < glist.size(); ++i) {
        if(glist.at(i).getName() == goodsname.name)
        {
            return true;
        }
    }
    return false;
}

void goods::addgoods(goods goodsname, QList<goods> &glist)
{
    if(isgoodsInrepository(goodsname, glist))
    {
        return;
    }
    glist.append(goodsname);
}

void goods::deletegoods(goods goodsname, QList<goods> &glist)
{
    for (int i = 0; i < glist.size(); ++i)
    {
        if(glist.at(i).getName() == goodsname.name)
        {
            glist.removeAt(i);
        }
    }
}

QString goods::getName() const
{
    return name;
}

int goods::getQuantity() const
{
    return quantity;
}

int goods::getCost() const
{
    return cost;
}

int goods::getPrice() const
{
    return price;
}

int goods::getID() const
{
    return ID;
}

QString goods::getSpecies() const
{
    return species;
}

QString goods::getUnit() const
{
    return unit;
}
