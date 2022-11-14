#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientmanagerform.h"
#include "productmanagerform.h"
#include "shopmanagerform.h"
#include "chatclient.h"
#include "chatserverform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clientForm = new ClientManagerForm(this);
    clientForm->setWindowTitle(tr("Client Info"));
    connect(clientForm, SIGNAL(destroyed()),
            clientForm, SLOT(deleteLater()));

    ProductManagerForm *productForm = new ProductManagerForm(this);
    productForm->setWindowTitle(tr("Product Info"));

    shopForm = new ShopManagerForm(this);
    shopForm->setWindowTitle(tr("Shopping Info"));

    chatserverForm = new ChatServerForm(this);
    chatserverForm->setWindowTitle(tr("Chat Server"));

    connect(chatserverForm, &QObject::destroyed, this, [&](QObject* obj){ chatserverForm = nullptr; });
    connect(clientForm, &QObject::destroyed, this, [&](QObject* obj){ clientForm = nullptr; });
    connect(shopForm, &QObject::destroyed, this, [&](QObject* obj){ shopForm = nullptr; });

    connect(clientForm, SIGNAL(sendClientInfo(int, QString)),shopForm, SLOT(clientComboboxSended(int, QString))); // client이름과 id를 shopForm의 combobox로 가져오기
    // 텍스트 파일 불러오기

    connect(productForm, SIGNAL(sendProductInfo(int, QString)),shopForm,SLOT(productComboboxSended(int, QString))); // product 이름과 id를 shopForm의 combobox로 가져오기


    connect(shopForm, SIGNAL(CID(int)), clientForm, SLOT(clientCIDSended(int)));  // CID를 통해 데이터 불러오기

    connect(clientForm, SIGNAL(sendClientInform(QString,QString,QString)),shopForm,SLOT(ClientInformSended(QString,QString,QString)));

    connect(shopForm, SIGNAL(sendProductPID(int)), productForm,SLOT(productPIDSended(int))); // PID를 통해 데이터 불러오기

    connect(productForm, SIGNAL(sendProductInform(QString,QString,QString)), shopForm, SLOT(ProductInformSended(QString,QString,QString)));

    connect(clientForm, SIGNAL(sendClientInfo(int,QString)),chatserverForm,SLOT(addClient(int, QString)));  // client이름을 ChatServer로 connect

    shopForm->loadData();

    productForm->loadData();

    clientForm->loadData();

    QMdiSubWindow *cw = ui->mdiArea->addSubWindow(clientForm);
    ui->mdiArea->addSubWindow(productForm);
    ui->mdiArea->addSubWindow(shopForm);
    ui->mdiArea->addSubWindow(chatserverForm);
    ui->mdiArea->setActiveSubWindow(cw);

    ui->toolBar->setIconSize(QSize(35,35));

}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_actionQuit_triggered()
{
    qDebug("Quit");
}




void MainWindow::on_actionChattingClient_triggered()
{
    chatclientForm = new ChatClient();
    chatclientForm->show();
}


void MainWindow::on_actionClientmanager_triggered()
{
    if(clientForm == nullptr){
        clientForm = new ClientManagerForm();
        ui->mdiArea->addSubWindow(clientForm);
        clientForm->show();
        clientForm->loadData();
        clientForm->setWindowTitle(tr("Client Info"));
    }
    clientForm->setFocus();
}


void MainWindow::on_actionProductmanager_triggered()
{
    productForm = new ProductManagerForm();
    productForm->show();
    productForm->loadData();
    productForm->setWindowTitle(tr("Product Info"));

}


void MainWindow::on_actionShopmanager_triggered()
{
    if(shopForm == nullptr) {
        shopForm = new ShopManagerForm();
        ui->mdiArea->addSubWindow(shopForm);
        shopForm->show();
        shopForm->loadData();
        shopForm->setWindowTitle(tr("Shop Info"));
    }
    shopForm->setFocus();

}


void MainWindow::on_actionChattingServer_triggered()
{
    if(chatserverForm == nullptr) {
        chatserverForm = new ChatServerForm(this);
        ui->mdiArea->addSubWindow(chatserverForm);
        chatserverForm->setWindowTitle(tr("Chat Server"));
        chatserverForm->show();
    }
    chatserverForm->setFocus();
}

