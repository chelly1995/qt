#include <QtGui>
#include <QtWidgets>
#include <QDomDocument>


#include "domreader.h"

DOMReader::DOMReader(QWidget *parent)
    : QWidget(parent)
{
    QStringList labels;
    labels << tr("Name") << tr("Telephone No.");
    QTreeWidget*treeWidget = new QTreeWidget(this);
    treeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);
    treeWidget->setHeaderLabels(labels);

    QFile file("Sample.xml");
    QDomDocument domDocument;
    domDocument.setContent(&file);
    QDomElement docElem = domDocument.documentElement();
    qDebug("%s",qPrintable(docElem.tagName()));

    QDomNode node = docElem.firstChild();
    while(!node.isNull()){

        QDomElement element = node.toElement();
        if(!element.isNull()){
            if(element.tagName()=="PhoneNumber"){
                QTreeWidgetItem*item=new QTreeWidgetItem(treeWidget);
                item->setText(0, element.attribute("Name"));
                item->setText(1, element.attribute("TelNo"));

            }
        }

        node =  node.nextSibling();
    }
}

DOMReader::~DOMReader()
{
}

