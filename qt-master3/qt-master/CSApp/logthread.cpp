#include "logthread.h"

#include <QTreeWidgetItem>
#include <QFile>
#include <QDateTime>


LogThread::LogThread(QObject *parent)
: QThread{parent}
{
    QString format = "yyyyMMdd_hhmmss";
    filename = QString("log_%1.txt").arg(QDateTime::currentDateTime().toString(format));
}


void LogThread::run()
{
    Q_FOREVER {
        serversaveData();
        sleep(60);      // 1분마다 저장
    }
}

void LogThread::appendData(QTreeWidgetItem* item)
{
    itemList.append(item);
}

void LogThread::serversaveData()
{
    qDebug() << 1;
    if(itemList.count() >= 0) {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
            qDebug() << 2;
            return;}
        qDebug() <<3;
        QTextStream out(&file);
        foreach(auto item, itemList) {
            out << item->text(0) << ", ";
            out << item->text(1) << ", ";
            out << item->text(2) << ", ";
            out << item->text(3) << ", ";
            out << item->text(4) << ", ";
            out << item->text(5) << "\n";
            qDebug()<<item;
        }
        file.close();
    }
}
