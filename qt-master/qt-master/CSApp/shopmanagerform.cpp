#include "shopmanagerform.h"
#include "ui_shopmanagerform.h"
#include "shopitem.h"

#include <QFile>
#include <QMenu>

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

    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    connect(ui->searchLineEdit, SIGNAL(returnPressed()),
            this, SLOT(on_searchPushButton_clicked()));

}

ShopManagerForm::~ShopManagerForm()     // 파일 저장
{
    delete ui;

    QFile file("shoplist.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (const auto& v : shopList) {
        ShopItem* c = v;
        out << c->sid() << ", " << c->getname() << ", ";
        out << c->getproductname() << ", ";
        out << c->getprice() << ", ";
        out << c->getquantity() << ", ";
        out << c->gettotalPrice() << "\n";
    }
    file.close( );
}

int ShopManagerForm::makeId( )      // SID 생성
{
    if(shopList.size( ) == 0) {
        return 300;
    } else {
        auto id = shopList.lastKey();
        return ++id;
    }
}

void ShopManagerForm::removeItem()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if(item != nullptr) {
        shopList.remove(item->text(0).toInt());
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item));
        ui->treeWidget->update();
    }
}

void ShopManagerForm::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->treeWidget->mapToGlobal(pos);
    menu->exec(globalPos);
}

void ShopManagerForm::on_searchPushButton_clicked()     // search 버튼 클릭
{
    ui->searchTreeWidget->clear();

    int i = ui->searchComboBox->currentIndex();
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains
                   : Qt::MatchCaseSensitive;
    {
        auto items = ui->treeWidget->findItems(ui->searchLineEdit->text(), flag, i);

        foreach(auto i, items) {
            ShopItem* c = static_cast<ShopItem*>(i);
            int id = c->sid();
            QString name = c->getname();
            QString productname = c->getproductname();
            QString price = c->getprice();
            QString quantity = c->getquantity();
            int totalPrice = c->gettotalPrice();

            ShopItem* item = new ShopItem(id, name, productname, price, quantity, totalPrice);
            ui->searchTreeWidget->addTopLevelItem(item);
        }
    }
}

void ShopManagerForm::on_modifyPushButton_clicked()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if(item != nullptr) {
        int key = item->text(0).toInt();
        //int num = item->text(4).toInt();
        ShopItem* c = shopList[key];
        QString name,productname,price,quantity;
        int totalPrice;

        name = ui->ClientnameComboBox->currentText();
        productname = ui->ProductnameComboBox->currentText();
        price = ui->priceLineEdit->text();
        quantity = ui->quantityLineEdit->text();
        totalPrice = ui->totalLineEdit->text().toInt();

        c->setname(name);
        c->setproductname(productname);
        c->setprice(price);
        c->setquantity(quantity);
        c->settotalPrice(totalPrice);
        shopList[key] = c;
    }
}

void ShopManagerForm::on_addPushButton_clicked()
{
    QString name, productname, price, quantity;
    int id = makeId( );
    int totalPrice;


    name = ui->ClientnameComboBox->currentText();
    productname = ui->ProductnameComboBox->currentText();
    price = ui->priceLineEdit->text();
    quantity = ui->quantityLineEdit->text();
    totalPrice= ui->totalLineEdit->text().toInt();

    if(name.length()) {
        ShopItem* c = new ShopItem (id, name, productname, price, quantity, totalPrice);
        shopList.insert(id, c);
        ui->treeWidget->addTopLevelItem(c);
   }
}

void ShopManagerForm::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)  // 트리 위젯 아이템 클릭 시
{

    Q_UNUSED(column);
    ui->sidLineEdit->setText(item->text(0));
    ui->ClientnameComboBox->setCurrentText(item->text(1));
    ui->ProductnameComboBox->setCurrentText(item->text(2));
    ui->quantityLineEdit->setText(item->text(4));
    ui->priceLineEdit->setText(item->text(3));
    ui->totalLineEdit->setText(item->text(5));



    emit CID(item->text(1).right(4).left(3).toInt());
    emit sendProductPID(item->text(2).right(4).left(3).toInt());


}



void ShopManagerForm:: loadData()
{

    QFile file("shoplist.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(", ");
        if(row.size()) {
            int id = row[0].toInt();
            int totalprice = row[5].toInt();
            ShopItem* c = new ShopItem(id, row[1], row[2], row[3], row[4], totalprice);
            ui->treeWidget->addTopLevelItem(c);
            shopList.insert(id, c);

           // emit sendClientCID(id);
        }
    }
    file.close( );

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

void ShopManagerForm::ProductInformSended(QString productname, QString price, QString stock)    // product 트리 위젯에 상품정보(상품이름, 가격, 재고량) 출력
{
    qDebug() << productname;
    qDebug() << price;

    ui->producttreeWidget->clear();
    QTreeWidgetItem *item = new QTreeWidgetItem;
    item->setText(0, productname);
    item->setText(1, price);
    item->setText(2, stock);
    ui->producttreeWidget->addTopLevelItem(item);

    ui->priceLineEdit->setText(price);         // priceLineEdit에 가격 자동으로 불러오기

}




void ShopManagerForm::on_ClientnameComboBox_textActivated(const QString &arg1)  // client 콤보박스 클릭 시
{

    qDebug() << arg1;
    qDebug() << arg1.right(4).left(3).toInt();
    emit CID(arg1.right(4).left(3).toInt());

}


void ShopManagerForm::on_ProductnameComboBox_textActivated(const QString &arg1) // product 콤보박스 클릭 시
{
    qDebug() << arg1;
    qDebug() << arg1.right(4).left(3).toInt();

    emit sendProductPID(arg1.right(4).left(3).toInt());
}


void ShopManagerForm::on_quantityLineEdit_textChanged(const QString &arg1)
{
    ui->totalLineEdit->setText(QString::number(arg1.toInt() * ui->priceLineEdit->text().toInt()));
}

