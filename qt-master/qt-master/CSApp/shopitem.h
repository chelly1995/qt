#ifndef SHOPITEM_H
#define SHOPITEM_H

#include <QTreeWidgetItem>

class ShopItem : public QTreeWidgetItem
{
public:
   explicit ShopItem(int sid=0, QString = "", QString = "", QString = "", QString = "", int totalPrice = 0);

    QString getCalender() const;
    void setCalender(QString&);

    int getcid() const;
    int getpid() const;

    QString getname() const;
    void setname(QString&);

    QString getphonenumber() const;
    void setphonenumber(QString&);

    QString getaddress() const;
    void setaddress(QString&);

    QString getproductname() const;
    void setproductname(QString&);

    QString getprice() const;
    void setprice(QString&);

    QString getquantity() const;
    void setquantity(QString&);

    int gettotalPrice() const;
    void settotalPrice(int&);

    int sid()const;

};

#endif // SHOPITEM_H
