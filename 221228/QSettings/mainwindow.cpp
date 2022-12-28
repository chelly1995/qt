#include "mainwindow.h"

#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->setCentralWidget(splitter);

    /*  저장된 RSS 데이터 표시 */
    QSettings settings;
    int size = settings.beginReadArray("rssFeeds");

    for(int i=0; i<size; i++){
        settings.setArrayIndex(i);
        QString url = settings.value("url").toString();
        combo->addItem(url);

    }

    settings.endArray();
    /* 콤보박스가 비어있는 경우의 기본값 설정*/

    if(size == 0)
        combo->addItem("http://rss.joins.com/joins_news_list.xml");

    /* 네트워크 매니저를 위한 설정 */
    manager = new QNetworkAccessManager(this);
}

MainWindow::~MainWindow()
{
    /* RSS 피드 리스트 저장하기 */
    QSettings settings;
    settings.beginWriteArray("rssFeeds");
    settings.remove("");
    for(int i=0; i<combo->count();i++){
        settings.setArrayIndex(i);
        settings.setValue("url",combo->itemText(i));
    }
    settings.endArray();
}

void MainWindow::openRssFeed()
{
    /* 콤보박스에서 동일한 항목이 있는지 검사 */
    int i = combo->findText(combo->currentText());
    if(i!=-1){
        combo->setCurrentIndex(i);

    }else{
        combo


    }
}
