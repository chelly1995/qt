#ifndef DOMREADER_H
#define DOMREADER_H

#include <QWidget>

class DOMReader : public QWidget
{
    Q_OBJECT

public:
    DOMReader(QWidget *parent = nullptr);
    ~DOMReader();
};
#endif // DOMREADER_H
