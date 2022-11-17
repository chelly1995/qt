#include "shopmanagerform.h"
#include "ui_shopmanagerform.h"
#include "shopitem.h"

#include <QFile>
#include <QMenu>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStandardItemModel>
#include <QMessageBox>

ShopManagerForm::ShopManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopManagerForm)
{
    ui->setupUi(this);

    QList<int> sizes;
    sizes << 540 << 400;
    ui->splitter->setSizes(sizes);

    QAction* removeAction = new QAction(tr("&Remove"));             // 오른쪽 마우스 클릭 -> 아이템 삭제
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));
    menu = new QMenu;
    menu->addAction(removeAction);

    ui->shoptableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->shoptableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    connect(ui->searchLineEdit, SIGNAL(returnPressed()),
            this, SLOT(on_searchPushButton_clicked()));

    searchqueryModel = new QStandardItemModel(0, 6);
    searchqueryModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    searchqueryModel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    searchqueryModel->setHeaderData(2, Qt::Horizontal, tr("Product Name"));
    searchqueryModel->setHeaderData(3, Qt::Horizontal, tr("Price"));
    searchqueryModel->setHeaderData(4, Qt::Horizontal, tr("Quantity"));
    searchqueryModel->setHeaderData(5, Qt::Horizontal, tr("TotalPrice"));
    ui->searchTableView->setModel(searchqueryModel);

}

ShopManagerForm::~ShopManagerForm()
{
    delete ui;

    QSqlDatabase db  = QSqlDatabase::database("shopConnection");
    if(db.isOpen()){
        shopqueryModel->submitAll();
        db.close();
        QSqlDatabase::removeDatabase("shopConnection");

    }
}

int ShopManagerForm::makeId( )      // SID 생성
{
    if(shopqueryModel->rowCount() == 0) {
        return 300;
    } else {
        auto id = shopqueryModel->data(shopqueryModel->index(shopqueryModel->rowCount()-1,0)).toInt();
        return ++id;
    }
}

void ShopManagerForm::removeItem()
{

    QModelIndex index=ui->shoptableView->currentIndex();
    //isValid() : 인덱스가 유효한경우 true반환 (음수가 아닌 행 및 열번호)
    if(index.isValid()){
        shopqueryModel->removeRow(index.row());
        shopqueryModel->select();
        ui->shoptableView->resizeRowsToContents();
    }

}

void ShopManagerForm::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->shoptableView->mapToGlobal(pos);
    if(ui->shoptableView->indexAt(pos).isValid())
        menu->exec(globalPos);
}

void ShopManagerForm::on_searchPushButton_clicked()     // Search 버튼 클릭
{
    searchqueryModel->clear();
    //ui->searchTreeWidget->clear();

    int i = ui->searchComboBox->currentIndex();
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains
                   : Qt::MatchCaseSensitive;
    {

        QModelIndexList indexes = shopqueryModel->match(shopqueryModel->index(0,i), Qt::EditRole, ui->searchLineEdit->text(),-1,Qt::MatchFlags(flag));
        foreach(auto ix, indexes) {

            int id = shopqueryModel->data(ix.siblingAtColumn(0)).toInt();
            QString name = shopqueryModel->data(ix.siblingAtColumn(1)).toString();
            QString productname = shopqueryModel->data(ix.siblingAtColumn(2)).toString();
            QString price = shopqueryModel->data(ix.siblingAtColumn(3)).toString();
            QString quantity = shopqueryModel->data(ix.siblingAtColumn(4)).toString();
            int totalprice = shopqueryModel->data(ix.siblingAtColumn(5)).toInt();

            QStringList strings;
            strings << QString::number(id) << name << productname << price<<quantity<< QString::number(totalprice);

            QList<QStandardItem *> items;
            for (int i = 0; i < 4; ++i) {
                items.append(new QStandardItem(strings.at(i)));
            }

            searchqueryModel->appendRow(items);
            searchqueryModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
            searchqueryModel->setHeaderData(1, Qt::Horizontal, tr("Name"));
            searchqueryModel->setHeaderData(2, Qt::Horizontal, tr("Product Name"));
            searchqueryModel->setHeaderData(3, Qt::Horizontal, tr("Price"));
            searchqueryModel->setHeaderData(4, Qt::Horizontal, tr("Quantity"));
            searchqueryModel->setHeaderData(5, Qt::Horizontal, tr("TotalPrice"));
            ui->searchTableView->resizeColumnsToContents();
        }
    }
}

void ShopManagerForm::on_modifyPushButton_clicked()     // Modify 버튼 클릭 시
{

    QModelIndex index = ui->shoptableView->currentIndex();

    if(index.isValid()){
        QString name, productname, price, quantity;
        int totalPrice;
        int sid = ui->sidLineEdit->text().toInt();
        name = ui->ClientnameComboBox->currentText();
        productname = ui->ProductnameComboBox->currentText();
        price = ui->priceLineEdit->text();
        quantity = ui->quantityLineEdit->text();
        totalPrice = ui->totalLineEdit->text().toInt();

        QSqlQuery query(shopqueryModel->database());
        query.prepare(QString("UPDATE shop SET name = ?, productname = ?, price = ?, quantity = ?, totalPrice = ? WHERE sid = ?"));
        query.bindValue(0,name);
        query.bindValue(1,productname);
        query.bindValue(2,price);
        query.bindValue(3,quantity);
        query.bindValue(4,totalPrice);
        query.bindValue(5,sid);
        query.exec();

        shopqueryModel->select();
        ui->shoptableView->resizeColumnsToContents();

    }
}

void ShopManagerForm::on_addPushButton_clicked()        // Add 버튼 클릭 시
{
    QString name, productname, price, quantity;
    int id = makeId( );
    int totalPrice;

    ui->sidLineEdit->setText(QString::number(id));
    name = ui->ClientnameComboBox->currentText();
    productname = ui->ProductnameComboBox->currentText();
    price = ui->priceLineEdit->text();
    quantity = ui->quantityLineEdit->text();
    totalPrice= ui->totalLineEdit->text().toInt();

    if(name.length()) {
        QSqlQuery query(shopqueryModel->database());

        query.prepare("INSERT INTO shop VALUES (?, ?, ?, ?, ?, ?)");
        query.bindValue(0,id);
        query.bindValue(1,name);
        query.bindValue(2,productname);
        query.bindValue(3,price);
        query.bindValue(4,quantity);
        query.bindValue(5,totalPrice);
        qDebug() << query.exec();
        shopqueryModel->select();
        ui->shoptableView->resizeColumnsToContents();
        qDebug()<<name;
    }
}




void ShopManagerForm:: loadData()       // 데이터 불러오기
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE","shopConnection");
    db.setDatabaseName("shop.db");
    if(db.open()){

        QSqlQuery query(db);
        query.exec("CREATE TABLE IF NOT EXISTS shop(sid INTEGER Primary Key, productname VARCHAR(20) NOT NULL, name VARCHAR(20), price VARCHAR(20), quantity VARCHAR(20), totalprice INTEGER);");

        shopqueryModel = new QSqlTableModel(this, db);
        shopqueryModel->setTable("shop");
        shopqueryModel->select();
        shopqueryModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        shopqueryModel->setHeaderData(1,Qt::Horizontal, QObject::tr("name"));
        shopqueryModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Product name"));
        shopqueryModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Price"));
        shopqueryModel->setHeaderData(4,Qt::Horizontal, QObject::tr("Quantity"));
        shopqueryModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Totalprice"));


        ui->shoptableView->setModel(shopqueryModel);
        ui->shoptableView->resizeColumnsToContents();
    }
}

void ShopManagerForm::productComboboxSended(int pid, QString productname)       // 상품이름(PID)를 product 콤보 박스에 출력
{
    ui->ProductnameComboBox->addItem(productname + "(" + QString::number(pid) + ")");

}

void ShopManagerForm::clientComboboxSended(int cid, QString name)               // 고객이름(CID)를 client 콤보 박스에 출력
{

    ui->ClientnameComboBox->addItem(name + "(" + QString::number(cid) + ")");
}

void ShopManagerForm::ClientInformSended(QString name, QString phonenumber, QString address)    // client 트리 위젯에 고객정보(이름, 폰번호, 주소) 출력
{
    qDebug() << name;
    ui->clienttreeWidget->clear();
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, name);
    item->setText(1, phonenumber);
    item->setText(2, address);
    ui->clienttreeWidget->addTopLevelItem(item);


}

void ShopManagerForm::ProductInformSended(QString productname, QString price, QString stock)    // Product 트리 위젯에 상품정보(상품이름, 가격, 재고량) 출력
{
    qDebug() << productname;
    qDebug() << price;

    ui->producttreeWidget->clear();
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, productname);
    item->setText(1, price);
    item->setText(2, stock);
    ui->producttreeWidget->addTopLevelItem(item);

    ui->priceLineEdit->setText(price);         // PriceLineEdit에 가격 자동으로 불러오기

}




void ShopManagerForm::on_ClientnameComboBox_textActivated(const QString &arg1)  // Client 콤보박스 클릭 시
{

    qDebug() << arg1;
    qDebug() << arg1.right(4).left(3).toInt();
    emit CID(arg1.right(4).left(3).toInt());

}


void ShopManagerForm::on_ProductnameComboBox_textActivated(const QString &arg1) // Product 콤보박스 클릭 시
{
    qDebug() << arg1;
    qDebug() << arg1.right(4).left(3).toInt();

    emit sendProductPID(arg1.right(4).left(3).toInt());
}


void ShopManagerForm::on_quantityLineEdit_textChanged(const QString &arg1)      // Quantity LineEdit의 텍스트가 바뀌었을 경우
{
    ui->totalLineEdit->setText(QString::number(arg1.toInt() * ui->priceLineEdit->text().toInt()));
}


void ShopManagerForm::on_shoptableView_clicked(const QModelIndex &index)    // ShopTableView를 클릭했을 경우
{

    QString id = shopqueryModel->data(index.siblingAtColumn(0)).toString();
    QString name = shopqueryModel->data(index.siblingAtColumn(1)).toString();
    QString productname = shopqueryModel->data(index.siblingAtColumn(2)).toString();
    QString price = shopqueryModel->data(index.siblingAtColumn(3)).toString();
    QString quantity = shopqueryModel->data(index.siblingAtColumn(4)).toString();
    QString totalprice = shopqueryModel->data(index.siblingAtColumn(5)).toString();

    ui->sidLineEdit->setText(id);
    ui->ClientnameComboBox->setCurrentText(name);
    ui->ProductnameComboBox->setCurrentText(productname);
    ui->priceLineEdit->setText(price);
    ui->quantityLineEdit->setText(quantity);
    ui->totalLineEdit->setText(totalprice);
    ui->toolBox->setCurrentIndex(0);

    emit CID(name.right(4).left(3).toInt());
    emit sendProductPID(productname.right(4).left(3).toInt());
}

