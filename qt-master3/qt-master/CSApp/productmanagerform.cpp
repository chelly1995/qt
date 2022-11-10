#include "productmanagerform.h"
#include "ui_productmanagerform.h"
#include "productitem.h"

#include <QFile>
#include <QMenu>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

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


    ui->producttableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->producttableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    connect(ui->searchLineEdit, SIGNAL(returnPressed()),
            this, SLOT(on_searchPushButton_clicked()));

}

ProductManagerForm::~ProductManagerForm()
{
    delete ui;

    QSqlDatabase db = QSqlDatabase::database("productConnection");
    if(db.isOpen()) {
        productqueryModel->submitAll();
        db.close();
        QSqlDatabase::removeDatabase("productConnection");
    }
}

int ProductManagerForm::makeId( )
{
    if(productqueryModel->rowCount() == 0) {
        return 200;
    } else {
        auto id = productqueryModel->data(productqueryModel->index(productqueryModel->rowCount()-1,0)).toInt();
        return ++id;
    }
}

void ProductManagerForm::removeItem()
{
    QModelIndex index=ui->producttableView->currentIndex();

    if(index.isValid()){
        productqueryModel->removeRow(index.row());
        productqueryModel->select();
        ui->producttableView->resizeColumnsToContents();
    }
}

void ProductManagerForm::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->producttableView->mapToGlobal(pos);
    if(ui->producttableView->indexAt(pos).isValid())
        menu->exec(globalPos);
}

void ProductManagerForm::on_searchPushButton_clicked()
{
    ui->searchTreeWidget->clear();

    int i = ui->searchComboBox->currentIndex();
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains
                   : Qt::MatchCaseSensitive;
    {

        QModelIndexList indexes = productqueryModel->match(productqueryModel->index(0,i), Qt::EditRole, ui->searchLineEdit->text(),-1,Qt::MatchFlags(flag));
        foreach(auto ix, indexes) {

            int id = productqueryModel->data(ix.siblingAtColumn(0)).toInt();
            QString productName = productqueryModel->data(ix.siblingAtColumn(1)).toString();
            QString price = productqueryModel->data(ix.siblingAtColumn(2)).toString();
            QString quantity = productqueryModel->data(ix.siblingAtColumn(3)).toString();
            QStringList strings;
            strings << QString::number(id) << productName<<price<<quantity;
            new QTreeWidgetItem(ui->searchTreeWidget, strings);

            for(int i=0; i<ui->searchTreeWidget->columnCount(); i++)
                ui->searchTreeWidget->resizeColumnToContents(i);
        }
    }
}

void ProductManagerForm::on_modifyPushButton_clicked()
{
    QModelIndex index = ui->producttableView->currentIndex();

    if(index.isValid()){
        QString productName, price, stock;
        int pid = ui->PidLineEdit->text().toInt();
        productName = ui->nameLineEdit->text();
        price = ui->PriceLineEdit->text();
        stock = ui->stockLineEdit->text();

        QSqlQuery query(productqueryModel->database());
        query.prepare(QString("UPDATE product SET productname = ?, price = ?, stock = ? WHERE pid=?"));
        query.bindValue(0, productName);
        query.bindValue(1, price);
        query.bindValue(2, stock);
        query.bindValue(3, pid);
        query.exec();

        productqueryModel->select();
        ui->producttableView->resizeColumnsToContents();

    }

}

void ProductManagerForm::on_addPushButton_clicked()
{
    QString productName, price, quantity;
    int id = makeId( );
    ui->PidLineEdit->setText(QString::number(id));
    productName = ui->nameLineEdit->text();
    price = ui->PriceLineEdit->text();
    quantity = ui->stockLineEdit->text();

    if(productName.length()) {
        QSqlQuery query(productqueryModel->database());
        query.prepare("INSERT INTO product VALUES (?, ?, ?, ?)");
        query.bindValue(0,id);
        query.bindValue(1,productName);
        query.bindValue(2,price);
        query.bindValue(3,quantity);
        query.exec();
        productqueryModel->select();
        ui->producttableView->resizeColumnsToContents();

        emit sendProductInfo(id, productName);
    }

    //    QSqlQuery query;
    //    query.exec(QString("INSERT INTO product VALUES (%1, '%2', '%3','%4')").arg(id).arg(productName).arg(price).arg(quantity));
    //    productqueryModel->select();
}


void ProductManagerForm::loadData()
{

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE","productConnection");
    db.setDatabaseName("product.db");
    if(db.open()){

        QSqlQuery query(db);
        query.exec("CREATE TABLE IF NOT EXISTS product(pid INTEGER Primary Key,""productname VARCHAR(20) NOT NULL, price VARCHAR(20), stock VARCHAR(20));");


        productqueryModel = new QSqlTableModel(this, db);
        productqueryModel->setTable("product");
        productqueryModel->select();
        productqueryModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        productqueryModel->setHeaderData(1,Qt::Horizontal, QObject::tr("Product name"));
        productqueryModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Price"));
        productqueryModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Stock"));

        ui->producttableView->setModel(productqueryModel);
        ui->producttableView->resizeColumnsToContents();

    }

    for(int i = 0; i < productqueryModel->rowCount(); i++) {
        int id = productqueryModel->data(productqueryModel->index(i, 0)).toInt();
        QString productname = productqueryModel->data(productqueryModel->index(i, 1)).toString();
        emit sendProductInfo(id, productname);
    }
}

void ProductManagerForm::productPIDSended(int id)
{

    QModelIndexList indexes = productqueryModel->match(productqueryModel->index(0, 0), Qt::EditRole, id, -1, Qt::MatchFlags(Qt::MatchCaseSensitive));
    foreach(auto index, indexes) {

        QString productname = productqueryModel->data(index.siblingAtColumn(1)).toString();
        QString price = productqueryModel->data(index.siblingAtColumn(2)).toString();
        QString stock = productqueryModel->data(index.siblingAtColumn(3)).toString();

        emit sendProductInform(productname,price,stock);
    }
}

void ProductManagerForm::on_producttableView_clicked(const QModelIndex &index)
{
    QString id = productqueryModel->data(index.siblingAtColumn(0)).toString();
    QString productname = productqueryModel->data(index.siblingAtColumn(1)).toString();
    QString price = productqueryModel->data(index.siblingAtColumn(2)).toString();
    QString stock = productqueryModel->data(index.siblingAtColumn(3)).toString();

    ui->PidLineEdit->setText(id);
    ui->nameLineEdit->setText(productname);
    ui->PriceLineEdit->setText(price);
    ui->stockLineEdit->setText(stock);
    ui->toolBox->setCurrentIndex(0);


}

