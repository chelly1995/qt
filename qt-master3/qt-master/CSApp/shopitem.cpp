#include "shopitem.h"

#include <QLabel>
#include <iostream>

using namespace std;

ShopItem::ShopItem(int sid, QString clientname, QString productname, QString price, QString quantity, int totalPrice )
{
    setText(0, QString::number(sid));
    setText(1, clientname);
    setText(2, productname);
    setText(3, price);
    setText(4, quantity);
    setText(5, QString::number(totalPrice));

}


int ShopItem::sid() const
{
    return text(0).toInt();

}


QString ShopItem::getname() const
{
    return text(1);
}

void ShopItem::setname(QString& clientname)
{
    setText(1, clientname);
}

int ShopItem::pid() const
{
    return text(2).toInt();

}
QString ShopItem::getproductname() const
{
    return text(2);
}

void ShopItem::setproductname(QString& productname)
{
    setText(3, productname);
}

QString ShopItem::getprice() const
{
    return text(3);
}

void ShopItem::setprice(QString& price)
{
    setText(4, price);
}


QString ShopItem::getquantity() const
{
    return text(4);
}


void ShopItem::setquantity(QString& quantity)
{
    setText(4,quantity);
}


int ShopItem::gettotalPrice() const
{
    return text(5).toInt();
}

void ShopItem::settotalPrice(int& quantity)
{
    setText(7, QString::number(quantity));

}
