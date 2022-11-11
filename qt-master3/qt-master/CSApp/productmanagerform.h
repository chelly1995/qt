#ifndef PRODUCTMANAGERFORM_H
#define PRODUCTMANAGERFORM_H

#include <QWidget>
#include <QHash>
#include <QSqlTableModel>

#include "productitem.h"

class QMenu;
class QTreeWidgetItem;
class QStandardItemModel;

namespace Ui {
class ProductManagerForm;
}

class ProductManagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManagerForm(QWidget *parent = nullptr);
    ~ProductManagerForm();
    void loadData();
    static bool createConnection();

private slots:
    /* QTreeWidget을 위한 슬롯 */
//    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void showContextMenu(const QPoint &);
    void removeItem();              /* QAction을 위한 슬롯 */
    void on_addPushButton_clicked();
    void on_modifyPushButton_clicked();
    void on_searchPushButton_clicked();
    void productPIDSended(int);



    void on_producttableView_clicked(const QModelIndex &index);

signals:
    void sendProductInfo(int, QString);
    void sendProductInform(QString,QString,QString);

private:
    int makeId();

     QMap<int, ProductItem*> productList;
     Ui::ProductManagerForm *ui;
     QMenu* menu;
     QSqlTableModel *productqueryModel;
     QStandardItemModel* searchqueryModel;

};

#endif // PRODUCTMANAGERFORM_H
