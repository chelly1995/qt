#include "clientlogthread.h"

#include <QTreeWidgetItem>
#include <QFile>
#include <QDateTime>

ClientLogThread::ClientLogThread(QObject *parent)
    : QThread{parent}
{
    QString format = "yyyyMMdd_hhmmss";
    filename = QString("clientlog_%1.txt").arg(QDateTime::currentDateTime().toString(format));

}

void ClientLogThread::run()
{
    Q_FOREVER {
        saveData();
        sleep(60);      // 1분마다 저장
    }
}

void ClientLogThread::appendData(QString item)
{
    itemList.append(item);
}

void ClientLogThread::saveData()
{

    if(itemList.count()>0){
        QFile file(filename);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
           return;

        QTextStream out(&file);
        foreach(auto item, itemList){
            qDebug()<<item;
            //            out << item->text(0) << ", ";
            //            out << item->text(1) << ", ";
            //            out << item->text(2) << ", ";
            //            out << item->text(3) << ", ";
            //            out << item->text(4) << ", ";
            //            out << item->text(5) << "\n";
            out << item << "\n";

        }
        itemList.clear();
        file.close();
    }
}
