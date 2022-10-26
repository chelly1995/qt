#ifndef LOGTREAD_H
#define LOGTREAD_H

#include <QThread>
#include <QList>

class QTreeWidgetItem;

class logTread : public QThread
{
    Q_OBJECT
public:
    explicit logTread(QObject *parent = nullptr);

signals:

};

#endif // LOGTREAD_H
