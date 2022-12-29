#include "mainwindow.h"
#include "saveurls.h"

#include <QtWidgets>
#include <QDomDocument>
#include <QDomNodeList>
//#include <QSettings>
//#include <QStandardItemModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QToolBar *toolbar = addToolBar(tr("Open"));
    /* RSS 피드를 열기 위한 콤보박스 */
    combo = new QComboBox;
    ListView *lv = new ListView;
    combo->setView(lv);
    combo->setEditable(true);
    combo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    connect(combo, SIGNAL(activated(int)), SLOT(openRssFeed( )));
    toolbar->addWidget(combo);

    /* RSS 피드 버튼을 위한 액션 */
    QAction *act = new QAction(tr("Open RSS Feed"), this);
    act->setIcon(style( )->standardIcon(QStyle::SP_BrowserReload));
    connect(act, SIGNAL(triggered( )), SLOT(openRssFeed( )));
    toolbar->addAction(act);


    /* 저장된 RSS 데이터 표시 */
    QSettings settings;
    int size = settings.beginReadArray("rssFeeds");
    for (int i = 0; i < size; i++) {
        settings.setArrayIndex(i);
        QString url = settings.value("url").toString( );
        combo->addItem(url);
    }

    settings.endArray( );
    /* 콤보박스가 비어있는 경우의 기본값 설정 */
    if (size == 0)
        combo->addItem("http://news.google.co.kr/news?cf=all&hl=ko&output=rss");

    /* 네트워크 매니저를 위한 설정 */
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            SLOT(replyFinished(QNetworkReply*)));

    /* 기본 RSS 피드 사이트 등록 */
    combo->addItem("http://news.google.co.kr/news?cf=all&hl=ko&output=rss");

    /* 동적 라이브러리의 사용 */
    QLibrary lib("SaveUrls");
    if(!lib.isLoaded())lib.load();
    SaveUrls*saveUrl=(SaveUrls*)lib.resolve("SaveUrls");
    QStringList urlList = saveUrl->load();
    for(int i=0; i<urlList.count();i++)
        combo->addItem(urlList.at(i));
    if(lib.isLoaded())lib.unload();

    /* 콤보박스가 비어있는경우의 기본값 설정 */
    if(urlList.count()==0)
        combo->addItem("http://rss.joins.com/joins_news_list.xml");

    toolbar->addAction(act);

    /* RSS 목록이 표시될 QListView 위젯 */
    tv = new QListView;
    connect(tv, SIGNAL(doubleClicked(QModelIndex)),SLOT(listViewDoubleClicked(QModelIndex)));
    model = new QStandardItemModel(0,1,this);
    tv->setModel(model);



    /*RSS 피드 다운로드와 웹 페이지 표시를 위한 프로그래스바 */
    progress = new QProgressBar(this);
    statusBar()->addPermanentWidget(progress);

    /* 웹 기반의 내용 표시 */
    wv = new QWebEngineView(this);
    wv->load(QUrl("about:blank"));
    connect(wv, SIGNAL(loadProgress(int)), progress, SLOT(setValue(int)));

    /* 중앙 위젯 설정 */
    QSplitter*splitter = new QSplitter;
    splitter->addWidget(tv);
    splitter->addWidget(wv);
    this->setCentralWidget(splitter);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), SLOT(replyFinished(QNetworkReply*)));



}

MainWindow::~MainWindow()
{

    /* RSS 피드 리스트 저장하기 */
    //    QSettings settings;
    //    settings.beginWriteArray("rssFeeds");
    //    settings.remove("");
    //    for (int i = 0; i < combo->count( ); i++) {
    //        settings.setArrayIndex(i);
    //        settings.setValue("url", combo->itemText(i));
    //    }
    //    settings.endArray( );
    QLibrary lib("SaveUrls");
    if(!lib.isLoaded())lib.load();
    SaveUrls* saveUrl=(SaveUrls*)lib.resolve("SaveUrls");
    QStringList urlList;
    for(int i=0; i<combo->count(); i++)
        urlList.append(combo->itemText(i));
    saveUrl->save(urlList);
    if(lib.isLoaded())lib.unload();
}

void MainWindow::openRssFeed( )
{
    /* 콤보박스에서 동일한 항목이 있는지 검사 */
    int i = combo->findText(combo->currentText( ));
    if (i != -1) {
        combo->setCurrentIndex(i);
    } else {
        combo->addItem(combo->currentText( ));
        combo->setCurrentIndex(combo->count( ) - 1);
    }

    /*  RSS 사이트 접속 */
    manager->get(QNetworkRequest(QUrl(combo->currentText( ))));

    QNetworkReply*reply=manager->get(QNetworkRequest(QUrl(combo->currentText())));
    connect(reply, SIGNAL(downloadProgress(qint64, qint64)),SLOT(downloadProgress(qint64, qint64)));
}

void MainWindow::replyFinished(QNetworkReply *netReply)
{
    QString str(netReply->readAll( ));
    qDebug("%s", qPrintable(str));

    /* 리다이렉트가 되면 다시 연결 */
    QVariant vt = netReply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if(!vt.isNull()){
        qDebug()<<"Redirected to:"<<vt.toUrl().toString();
        QNetworkReply* reply = manager->get(QNetworkRequest(vt.toUrl()));
        connect(reply,SIGNAL(downloadProgress(qint64,qint64)),SLOT(downloadProgress(qint64,qint64)));
    }else{
        QDomDocument doc;
        QString error;
        if(!doc.setContent(str,false,&error)){
            wv->setHtml(QString("<h1>Error</h1>")+error);
        }else{
            QDomElement docElem = doc.documentElement();
            QDomNodeList nodeList = docElem.elementsByTagName("item");

            model->clear();
            model->insertColumn(0);
            for(int i =0; i<nodeList.length(); i++){
                QDomNode node =nodeList.item(i);
                QDomElement e = node.toElement();
                QString strTitle = e.elementsByTagName("title").item(0).firstChild().nodeValue();
                QString strLink= e.elementsByTagName("link").item(0).firstChild().nodeValue();
                QString strDescription = e.elementsByTagName("description").item(0).firstChild().nodeValue();

                QString strToolTip = "<b>"+strTitle  + "</b"+"<br/><br/>"+strDescription + "<br/><br />" +strLink;

                model->insertRows(model->rowCount(),1);
                QModelIndex index = model->index(model->rowCount() -1,0);
                model->setData(index,strTitle,Qt::DisplayRole);
                model->setData(index,style()->standardIcon(QStyle::SP_FileIcon),Qt::DecorationRole);
                model->setData(index,strToolTip,Qt::ToolTipRole);
                model->setData(index,strLink,Qt::UserRole);
                model->itemFromIndex(index)->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

            }
        }
    }
}

/* QListView에서 삭제 키 사용 설정 */
void ListView::keyPressEvent(QKeyEvent *event)
{
    if (event->key( ) == Qt::Key_Delete) {
        event->accept( );
        QModelIndexList l = selectedIndexes( );
        if (l.length( ) > 0) {
            model( )->removeRow(l.at(0).row( ), l.at(0).parent( ));
        }
    } else {
        QListView::keyPressEvent(event);
    }
}

/* QListView를 더블 클릭할 때 호출 */
void MainWindow::listViewDoubleClicked(const QModelIndex &index)
{
    /* 웹뷰에 내용 표시 */

    qDebug("listViewDoubleClicked");
    QString strLink = index.data(Qt::UserRole).toString();
    wv->load(QUrl(strLink));
}

void MainWindow::downloadProgress(qint64 bytes, qint64 bytesTotal)
{
    if(bytesTotal==-1){
        /*진행 관련 정보 설정 */
        progress->setMinimum(0);
        progress->setMaximum(0);
    }else{
        progress->setMaximum(100);
        int percent = bytes*100/bytesTotal;
        progress->setValue(percent);


    }

}


