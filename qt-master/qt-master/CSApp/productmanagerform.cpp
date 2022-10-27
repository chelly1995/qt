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

ProductManagerForm::~ProductManagerForm()           // 상품 정보 저장
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

int ProductManagerForm::makeId( )               // Product ID 생성
{
    if(productList.size( ) == 0) {              // productList의 값이 없을 경우 200 반환
        return 200;
    } else {                                    // 값이 있을 경우 productList의 마지막key 값을 id변수에 저장
        auto id = productList.lastKey();        // id값에 1을 증가하여 반환
        return ++id;
    }
}

void ProductManagerForm::removeItem()           // 아이템 삭제
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();      // treeWidget의 현재 아이템을 item변수에 저장
    if(item != nullptr) {                                       // 아이템이 존재할 경우
        productList.remove(item->text(0).toInt());              // productList의 id삭제
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item));

        ui->treeWidget->update();
    }
}

void ProductManagerForm::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->treeWidget->mapToGlobal(pos);
    menu->exec(globalPos);
}

void ProductManagerForm::on_addPushButton_clicked()         // Add버튼 클릭 시
{
    QString productName, price, stock;
    int id = makeId( );
    productName = ui->nameLineEdit->text();
    price = ui->PricelineEdit->text();
    stock = ui->quantitylineEdit->text();
    if(productName.length()) {
        ProductItem* c = new ProductItem(id, productName, price, stock);
        productList.insert(id, c);
        ui->treeWidget->addTopLevelItem(c);

        emit sendProductInfo(id, productName);
    }
}

void ProductManagerForm::on_modifyPushButton_clicked()          // Modify 버튼 클릭 시
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();      // 트리위젯의 현재아이템을 item 변수에 저장
    if(item != nullptr) {                                  // item이 존재할 경우
        int key = item->text(0).toInt();                   // item의 0번째 문자열을 int형으로 key에 저장
        ProductItem* c = productList[key];                 // c객체포인터에 현재 선택된 아이템의 productList 저장
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

void ProductManagerForm::on_searchPushButton_clicked()          // Search버튼 클릭 시
{
    ui->searchTreeWidget->clear();
//    for(int i = 0; i < ui->treeWidget->columnCount(); i++)
    int i = ui->searchComboBox->currentIndex();                 // searchComboBox의 현재 index를 i에 저장
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains
                   : Qt::MatchCaseSensitive;
    {
        auto items = ui->treeWidget->findItems(ui->searchLineEdit->text(), flag, i);    // finditem함수 ->지정된 열에서 지정된 플래그를 사용하여 지정된 텍스트와 일치하는 항목 목록을 반환
                                                        // 리스트 항목을 items 변수에 저장

        foreach(auto i, items) {
            ProductItem* c = static_cast<ProductItem*>(i);
            int id = c->id();
            QString productName = c->getProductName();
            QString price = c->getPrice();
            QString stock = c->getStock();
            ProductItem* item = new ProductItem(id, productName, price, stock);
            ui->searchTreeWidget->addTopLevelItem(item);
        }
    }
}




void ProductManagerForm::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)   // 트리위젯의 아이템 클릭 시
{
    Q_UNUSED(column);
    ui->PidLineEdit->setText(item->text(0));
    ui->nameLineEdit->setText(item->text(1));
    ui->PricelineEdit->setText(item->text(2));
    ui->quantitylineEdit->setText(item->text(3));

}

void ProductManagerForm::loadData()     // Product 정보 불러오기
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

void ProductManagerForm::productPIDSended(int id)       // Product ID를 통해 Product 정보를 불러옴
{

    ProductItem *p =productList[id];
    QString productname = p->getProductName();
    QString price = p->getPrice();
    QString stock = p->getStock();

    qDebug() << productname;
    qDebug() << price;

    emit sendProductInform(productname,price,stock);
}

