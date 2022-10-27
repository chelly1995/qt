#include "clientmanagerform.h"
#include "ui_clientmanagerform.h"
#include "clientitem.h"

#include <QFile>
#include <QMenu>

ClientManagerForm::ClientManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientManagerForm)
{
    ui->setupUi(this);

    QList<int> sizes;       // client Info 사이즈 조정
    sizes << 640 << 500;
    ui->splitter->setSizes(sizes);

    QAction* removeAction = new QAction(tr("&Remove"));     // Remove 액션 생성
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));     // remove 버튼을 눌렀을 때 아이템 삭제
    menu = new QMenu;
    menu->addAction(removeAction);      // 생성된 메뉴에 removeAction 추가


    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    connect(ui->searchLineEdit, SIGNAL(returnPressed()),
            this, SLOT(on_searchPushButton_clicked()));

}



ClientManagerForm::~ClientManagerForm()     // 고객 정보 저장
{
    delete ui;

    QFile file("clientlist.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (const auto& v : clientList) {
        ClientItem* c = v;
        out << c->id() << ", " << c->getName() << ", ";
        out << c->getPhoneNumber() << ", ";
        out << c->getAddress() << "\n";
    }
    file.close( );
}




int ClientManagerForm::makeId( )    // client ID 생성
{
    if(clientList.size( ) == 0) {   // clientList의 size가 0인 경우 100 반환
        return 100;
    } else {
        auto id = clientList.lastKey(); // clientList의 size가 0이 아닌 경우 clientList의 마지막key값을 id에 저장
        return ++id;                    // id값을 하나씩 증가
    }
}




void ClientManagerForm::removeItem()    // 아이템 삭제
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();  // treeWidget의 현재아이템을 item 변수에 저장
    if(item != nullptr) {   // item 값이 존재할 경우
        clientList.remove(item->text(0).toInt());
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item));
        ui->treeWidget->update();
    }
}



void ClientManagerForm::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->treeWidget->mapToGlobal(pos);
    menu->exec(globalPos);
}



void ClientManagerForm::on_addPushButton_clicked()      // add 버튼 클릭 시
{
    QString name, number, address;
    int id = makeId( );
    name = ui->nameLineEdit->text();
    number = ui->phoneNumberLineEdit->text();
    address = ui->addressLineEdit->text();
    if(name.length()) {
        ClientItem* c = new ClientItem(id, name, number, address);
        clientList.insert(id, c);
        ui->treeWidget->addTopLevelItem(c); // c 객체의 값을 위젯의 탑 레벨에 추가 시킴

        emit sendClientInfo(id, name);  // clientInfo에서 아이템을 추가했을 때 client id, name emit
    }
}


void ClientManagerForm::on_modifyPushButton_clicked()       // Modify 버튼 클릭 시
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();  // treeWidget의 currentItem을 item에 저장
    if(item != nullptr) {       // item이 존재할 경우
        int key = item->text(0).toInt();    // item의 첫번째 칼럼 int형으로 형변환하여 key 변수에 저장
        ClientItem* c = clientList[key];    // ClientItem 클래스 객체 c에 QMap 형태의 clientList 값 지정
        QString name, number, address;      // name, numbeer, address 문자열 변수 선언
        name = ui->nameLineEdit->text();    // name에 nameLineEdit의 문자열 저장
        number = ui->phoneNumberLineEdit->text();   // number에 phoneNumberLineEdit의 문자열 저장
        address = ui->addressLineEdit->text();      // address에 addressLineEdit의 문자열 저장
        c->setName(name);
        c->setPhoneNumber(number);
        c->setAddress(address);
        clientList[key] = c;
    }
}



void ClientManagerForm::on_searchPushButton_clicked()           // search 버튼 클릭 시
{
    ui->searchTreeWidget->clear();
//    for(int i = 0; i < ui->treeWidget->columnCount(); i++)
    int i = ui->searchComboBox->currentIndex();                 // searchComboBox의 현재 index값을 i에 저장
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains
                   : Qt::MatchCaseSensitive;
    {
        auto items = ui->treeWidget->findItems(ui->searchLineEdit->text(), flag, i);

        foreach(auto i, items) {
            ClientItem* c = static_cast<ClientItem*>(i);
            int id = c->id();
            QString name = c->getName();
            QString number = c->getPhoneNumber();
            QString address = c->getAddress();
            ClientItem* item = new ClientItem(id, name, number, address);
            ui->searchTreeWidget->addTopLevelItem(item);
        }
    }
}


void ClientManagerForm::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)    // treeWidget의 아이템 클릭 시
{
    Q_UNUSED(column);
    ui->idLineEdit->setText(item->text(0));     // idLineEdit에 0번째 아이템을 문자열로 출력
    ui->nameLineEdit->setText(item->text(1));   // idLineEdit에 1번째 아이템을 문자열로 출력
    ui->phoneNumberLineEdit->setText(item->text(2));    // idLineEdit에 2번째 아이템을 문자열로 출력
    ui->addressLineEdit->setText(item->text(3));        // idLineEdit에 3번째 아이템을 문자열로 출력
}


void ClientManagerForm::loadData()          // 소멸자에서 TXT파일로 저장한 정보를 불러오는 함수
{
    QFile file("clientlist.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(", ");
        if(row.size()) {
            int id = row[0].toInt();
            ClientItem* c = new ClientItem(id, row[1], row[2], row[3]);
            ui->treeWidget->addTopLevelItem(c);
            clientList.insert(id, c);

           emit sendClientInfo(id, row[1]); // client id와 name의 값을 통해 client info를 EMIT
        }
    }

    file.close( );

}



void ClientManagerForm::clientCIDSended(int id) // CID를 통해 client정보 전달
{

    ClientItem *c =clientList[id];
    QString name = c->getName();
    QString phonenumber = c->getPhoneNumber();
    QString address = c->getAddress();


    qDebug() << name;
    emit sendClientInform(name,phonenumber,address);    // CID를 통해 client정보(이름, 핸드폰 번호, 주소)를 EMIT
}
