#include "clientmanagerform.h"
#include "ui_clientmanagerform.h"
#include "clientitem.h"

#include <QFile>
#include <QMenu>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QSqlRecord>


ClientManagerForm::ClientManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientManagerForm)
{
    ui->setupUi(this);

    QList<int> sizes;    // ClientManagerForm 창 크기 조정
    sizes << 640 << 500;
    ui->splitter->setSizes(sizes);

    QAction* removeAction = new QAction(tr("&Remove"));     // REMOVE 액션 생성
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));     // REMOVE 버튼을 눌렀을 때 아이템 삭제하는 시그널과 슬롯함수 CONNECT
    menu = new QMenu;
    menu->addAction(removeAction);      // 생성된 메뉴에 removeAction 추가

    ui->clienttableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->clienttableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    connect(ui->searchLineEdit, SIGNAL(returnPressed()),
            this, SLOT(on_searchPushButton_clicked()));

    searchqueryModel = new QStandardItemModel(0, 4);                // SEARCH 쿼리 모델 생성 및 HEADER 이름 설정
    searchqueryModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    searchqueryModel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    searchqueryModel->setHeaderData(2, Qt::Horizontal, tr("Phone Number"));
    searchqueryModel->setHeaderData(3, Qt::Horizontal, tr("Address"));
    ui->searchTableView->setModel(searchqueryModel);
}



ClientManagerForm::~ClientManagerForm()             // 데이터베이스 저장
{
    delete ui;
    QSqlDatabase db = QSqlDatabase::database("clientConnection");
    if(db.isOpen()) {
        clientqueryModel->submitAll();
        db.close();
        QSqlDatabase::removeDatabase("clientConnection");
    }
}

int ClientManagerForm::makeId( )    // Client ID 생성
{
    if(clientqueryModel->rowCount() == 0) {
        return 100;
    } else {
        auto id = clientqueryModel->data(clientqueryModel->index(clientqueryModel->rowCount()-1,0)).toInt(); // clientList의 size가 0이 아닌 경우 clientList의 마지막key값을 id에 저장
        return ++id;
    }
}

void ClientManagerForm::removeItem()    // 아이템 삭제
{

    QModelIndex index=ui->clienttableView->currentIndex();

    if(index.isValid()){
        clientqueryModel->removeRow(index.row());
        clientqueryModel->select();
        ui->clienttableView->resizeColumnsToContents();

    }
}

void ClientManagerForm::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->clienttableView->mapToGlobal(pos);
    if(ui->clienttableView->indexAt(pos).isValid())
        menu->exec(globalPos);

}

void ClientManagerForm::on_searchPushButton_clicked()           // SEARCH 버튼 클릭 시,
{
    searchqueryModel->clear();

    int i = ui->searchComboBox->currentIndex();                 // SEARCH 콤보박스 현재 INDEX 값을 변수 i에 저장
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains
                   : Qt::MatchCaseSensitive;

        QModelIndexList indexes = clientqueryModel->match(clientqueryModel->index(0,i), Qt::EditRole, ui->searchLineEdit->text(),-1,Qt::MatchFlags(flag));

        foreach(auto ix, indexes) {
            //ClientItem* c = static_cast<ClientItem*>(i);
            int id = clientqueryModel->data(ix.siblingAtColumn(0)).toInt();
            QString name = clientqueryModel->data(ix.siblingAtColumn(1)).toString();
            QString number = clientqueryModel->data(ix.siblingAtColumn(2)).toString();
            QString address = clientqueryModel->data(ix.siblingAtColumn(3)).toString();
            QStringList strings;
            strings << QString::number(id) <<name<<number<<address;

            QList<QStandardItem *> items;
            for (int i = 0; i < 4; ++i) {
                items.append(new QStandardItem(strings.at(i)));
            }

            searchqueryModel->appendRow(items);
            searchqueryModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
            searchqueryModel->setHeaderData(1, Qt::Horizontal, tr("Name"));
            searchqueryModel->setHeaderData(2, Qt::Horizontal, tr("Phone Number"));
            searchqueryModel->setHeaderData(3, Qt::Horizontal, tr("Address"));

            ui->searchTableView->resizeColumnsToContents();


    }
}

void ClientManagerForm::on_modifyPushButton_clicked()       // MODIFY 버튼 클릭 시
{
    QModelIndex index = ui->clienttableView->currentIndex();

    if(index.isValid()){
        QString name, number, address;
        int cid = ui->idLineEdit->text().toInt();
        name = ui->nameLineEdit->text();
        number = ui->phoneNumberLineEdit->text();
        address = ui->addressLineEdit->text();


        QSqlQuery query(clientqueryModel->database());
        query.prepare(QString("UPDATE client SET clientname = ?, phonenum = ?, address = ? WHERE cid=?"));
        query.bindValue(0, name);
        query.bindValue(1, number);
        query.bindValue(2, address);
        query.bindValue(3, cid);
        query.exec();


        clientqueryModel->select();
        ui->clienttableView->resizeColumnsToContents();

    }

}

void ClientManagerForm::on_addPushButton_clicked()      // ADD 버튼 클릭 시
{
    QString name, number, address;
    int id = makeId( );
    ui->idLineEdit->setText(QString::number(id));
    name = ui->nameLineEdit->text();
    number = ui->phoneNumberLineEdit->text();
    address = ui->addressLineEdit->text();
    if(name.length()) {
        QSqlQuery query(clientqueryModel->database());
        query.prepare("INSERT INTO client VALUES (?, ?, ?, ?)");
        query.bindValue(0,id);
        query.bindValue(1,name);
        query.bindValue(2,number);
        query.bindValue(3,address);
        query.exec();
        clientqueryModel->select();
        ui->clienttableView->resizeColumnsToContents();

        emit sendClientInfo(id, name);
    }
}


void ClientManagerForm::loadData()                  // 데이터 불러오기
{

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE","clientConnection");
    db.setDatabaseName("client.db");
    if(db.open()){

        QSqlQuery query(db);
        query.exec("CREATE TABLE IF NOT EXISTS client(cid INTEGER Primary Key,""clientname VARCHAR(20) NOT NULL, phonenum VARCHAR(20), address VARCHAR(20));");

        clientqueryModel = new QSqlTableModel(this, db);
        clientqueryModel->setTable("client");
        clientqueryModel->select();
        clientqueryModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        clientqueryModel->setHeaderData(1,Qt::Horizontal, QObject::tr("Client name"));
        clientqueryModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Phone number"));
        clientqueryModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Address"));

        ui->clienttableView->setModel(clientqueryModel);
        ui->clienttableView->resizeColumnsToContents();

    }
    for(int i = 0; i < clientqueryModel->rowCount(); i++) {
        int id = clientqueryModel->data(clientqueryModel->index(i, 0)).toInt();
        QString name = clientqueryModel->data(clientqueryModel->index(i, 1)).toString();
        //clientList.insert(id, clientModel->index(i, 0));
        emit sendClientInfo(id, name);
    }
}


void ClientManagerForm::clientCIDSended(int id) // CID를 통해 Client정보 전달
{

    QModelIndexList indexes = clientqueryModel->match(clientqueryModel->index(0, 0), Qt::EditRole, id, -1, Qt::MatchFlags(Qt::MatchCaseSensitive));
    foreach(auto index, indexes){
        QString name = clientqueryModel->data(index.siblingAtColumn(1)).toString();
        QString phonenumber = clientqueryModel->data(index.siblingAtColumn(2)).toString();
        QString address = clientqueryModel->data(index.siblingAtColumn(3)).toString();

        emit sendClientInform(name,phonenumber,address);
    }
}


void ClientManagerForm::on_clienttableView_clicked(const QModelIndex &index)    // ClientTableView 클릭 시
{
    QString id = clientqueryModel->data(index.siblingAtColumn(0)).toString();
    QString name = clientqueryModel->data(index.siblingAtColumn(1)).toString();
    QString phoneNumber = clientqueryModel->data(index.siblingAtColumn(2)).toString();
    QString address = clientqueryModel->data(index.siblingAtColumn(3)).toString();

    ui->idLineEdit->setText(id);
    ui->nameLineEdit->setText(name);
    ui->phoneNumberLineEdit->setText(phoneNumber);
    ui->addressLineEdit->setText(address);
    ui->toolBox->setCurrentIndex(0);

}

