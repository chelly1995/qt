#ifndef SAVEURLS_H
#define SAVEURLS_H

#include "SaveUrls_global.h"
#include <QStringList>

//class QStringList;

class SAVEURLS_EXPORT SaveUrls
{
public:
    SaveUrls();

    void save(QStringList);
    QStringList load();


};

#endif // SAVEURLS_H
