#ifndef SHOPMANAGERFORM_H
#define SHOPMANAGERFORM_H

#include <QWidget>
#include <QHash>

#include "shopitem.h"

class QMenu;
class QTreeWidgetItem;

namespace Ui {
class ShopManagerForm;
}

class ShopManagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ShopManagerForm(QWidget *parent = nullptr);
    ~ShopManagerForm();
    void loadData();


private slots:
    /* QTreeWidget을 위한 슬롯 */
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void showContextMenu(const QPoint &);
    void removeItem();              /* QAction을 위한 슬롯 */
    void on_addPushButton_clicked();
    void on_modifyPushButton_clicked();
    void on_searchPushButton_clicked();

    void on_ProductnameComboBox_textActivated(const QString &arg1);

    void on_quantityLineEdit_textChanged(const QString &arg1);

public slots:
    void clientComboboxSended(int, QString);
    void productComboboxSended(int, QString);
    void ClientInformSended(QString,QString,QString);
    void ProductInformSended(QString,QString,QString);


    void on_ClientnameComboBox_textActivated(const QString &arg1);

signals :
    void CID(int);
    void sendProductPID(int);

private:
    int makeId();

    QMap<int, ShopItem*> shopList;
    Ui::ShopManagerForm *ui;
    QMenu* menu;

};

#endif // SHOPMANAGERFORM_H
