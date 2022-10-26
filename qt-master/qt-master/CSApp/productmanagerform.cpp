#include "productmanagerform.h"
#include "ui_productmanagerform.h"
#include "productitem.h"

#include <QFile>
#include <QMenu>

ProductManagerForm::ProductManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductManagerForm)
{
    ui->setupUi(this);


    QList<int> sizes;
    sizes << 540 << 400;
    ui->splitter->setSizes(sizes);

    QAction* removeAction = new QAction(tr("&Remove"));
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));

    menu = new QMenu;
    menu->addAction(removeAction);
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    connect(ui->searchLineEdit, SIGNAL(returnPressed()),
            this, SLOT(on_searchPushButton_clicked()));

}

ProductManagerForm::~ProductManagerForm()
{
    delete ui;

    QFile file("productlist.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (const auto& v : productList) {
        ProductItem* c = v;
        out << c->id() << ", " << c->getProductName() << ", ";
        out << c->getPrice() << ", ";
        out << c->getStock() << "\n";
    }
    file.close( );
}

int ProductManagerForm::makeId( )
{
    if(productList.size( ) == 0) {
        return 200;
    } else {
        auto id = productList.lastKey();
        return ++id;
    }
}

void ProductManagerForm::removeItem()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if(item != nullptr) {
        productList.remove(item->text(0).toInt());
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item));
//        delete item;
        ui->treeWidget->update();
    }
}

void ProductManagerForm::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->treeWidget->mapToGlobal(pos);
    menu->exec(globalPos);
}

void ProductManagerForm::on_searchPushButton_clicked()
{
    ui->searchTreeWidget->clear();
//    for(int i = 0; i < ui->treeWidget->columnCount(); i++)
    int i = ui->searchComboBox->currentIndex();
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains
                   : Qt::MatchCaseSensitive;
    {
        auto items = ui->treeWidget->findItems(ui->searchLineEdit->text(), flag, i);

        foreach(auto i, items) {
            ProductItem* c = static_cast<ProductItem*>(i);
            int id = c->id();
            QString productName = c->getProductName();
            QString price = c->getPrice();
            QString quantity = c->getStock();
            ProductItem* item = new ProductItem(id, productName, price, quantity);
            ui->searchTreeWidget->addTopLevelItem(item);
        }
    }
}

void ProductManagerForm::on_modifyPushButton_clicked()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if(item != nullptr) {
        int key = item->text(0).toInt();
        ProductItem* c = productList[key];
        QString productName, price, stock;
        productName = ui->nameLineEdit->text();
        price = ui->PricelineEdit->text();
        stock = ui->quantitylineEdit->text();
        c->setProductName(productName);
        c->setPrice(price);
        c->setStock(stock);
        productList[key] = c;
    }
}

void ProductManagerForm::on_addPushButton_clicked()
{
    QString productName, price, quantity;
    int id = makeId( );
    productName = ui->nameLineEdit->text();
    price = ui->PricelineEdit->text();
    quantity = ui->quantitylineEdit->text();
    if(productName.length()) {
        ProductItem* c = new ProductItem(id, productName, price, quantity);
        productList.insert(id, c);
        ui->treeWidget->addTopLevelItem(c);

        emit sendProductInfo(id, productName);
    }
}

void ProductManagerForm::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);
    ui->PidLineEdit->setText(item->text(0));
    ui->nameLineEdit->setText(item->text(1));
    ui->PricelineEdit->setText(item->text(2));
    ui->quantitylineEdit->setText(item->text(3));

}

void ProductManagerForm::loadData()
{
    QFile file("productlist.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(", ");
        if(row.size()) {
            int id = row[0].toInt();
            ProductItem* c = new ProductItem(id, row[1], row[2], row[3]);
            ui->treeWidget->addTopLevelItem(c);
            productList.insert(id, c);

            emit sendProductInfo(id, row[1]);
        }
    }
    file.close( );
}

void ProductManagerForm::productPIDSended(int id)
{

    ProductItem *p =productList[id];
    QString productname = p->getProductName();
    QString price = p->getPrice();
    QString stock = p->getStock();

    qDebug() << productname;
    qDebug() << price;

    emit sendProductInform(productname,price,stock);
}

