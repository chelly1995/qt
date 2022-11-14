#ifndef CLIENTLOGTHREAD_H
#define CLIENTLOGTHREAD_H

#include <QThread>
#include <QList>

class QTreeWidgetItem;

class ClientLogThread : public QThread
{
public:
    explicit ClientLogThread(QObject *parent = nullptr);


private:
    void run();

//    QList<QTreeWidgetItem*> itemList;

    QList<QString> itemList;
    QString filename;

signals:
    void send(int data);

public slots:
    void appendData(QString);
    void saveData();




};

#endif // CLIENTLOGTHREAD_H
