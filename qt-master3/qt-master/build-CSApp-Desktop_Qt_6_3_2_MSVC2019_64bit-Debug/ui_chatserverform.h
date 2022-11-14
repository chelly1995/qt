/********************************************************************************
** Form generated from reading UI file 'chatserverform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATSERVERFORM_H
#define UI_CHATSERVERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatServerForm
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTreeWidget *clientTreeWidget;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QTreeWidget *messageTreeWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *clearPushButton;
    QPushButton *savePushButton;

    void setupUi(QWidget *ChatServerForm)
    {
        if (ChatServerForm->objectName().isEmpty())
            ChatServerForm->setObjectName(QString::fromUtf8("ChatServerForm"));
        ChatServerForm->resize(634, 436);
        gridLayout = new QGridLayout(ChatServerForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(ChatServerForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        clientTreeWidget = new QTreeWidget(layoutWidget);
        clientTreeWidget->setObjectName(QString::fromUtf8("clientTreeWidget"));

        verticalLayout_2->addWidget(clientTreeWidget);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        messageTreeWidget = new QTreeWidget(layoutWidget1);
        messageTreeWidget->setObjectName(QString::fromUtf8("messageTreeWidget"));

        verticalLayout->addWidget(messageTreeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        clearPushButton = new QPushButton(layoutWidget1);
        clearPushButton->setObjectName(QString::fromUtf8("clearPushButton"));

        horizontalLayout->addWidget(clearPushButton);

        savePushButton = new QPushButton(layoutWidget1);
        savePushButton->setObjectName(QString::fromUtf8("savePushButton"));

        horizontalLayout->addWidget(savePushButton);


        verticalLayout->addLayout(horizontalLayout);

        splitter->addWidget(layoutWidget1);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(ChatServerForm);
        QObject::connect(clearPushButton, &QPushButton::clicked, messageTreeWidget, qOverload<>(&QTreeWidget::clear));

        QMetaObject::connectSlotsByName(ChatServerForm);
    } // setupUi

    void retranslateUi(QWidget *ChatServerForm)
    {
        ChatServerForm->setWindowTitle(QCoreApplication::translate("ChatServerForm", "Form", nullptr));
        label->setText(QCoreApplication::translate("ChatServerForm", "Client List", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = clientTreeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ChatServerForm", "Name", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ChatServerForm", "Status", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = messageTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(5, QCoreApplication::translate("ChatServerForm", "Time", nullptr));
        ___qtreewidgetitem1->setText(4, QCoreApplication::translate("ChatServerForm", "Message", nullptr));
        ___qtreewidgetitem1->setText(3, QCoreApplication::translate("ChatServerForm", "Name", nullptr));
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("ChatServerForm", "ID", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("ChatServerForm", "Port", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("ChatServerForm", "IP", nullptr));
        clearPushButton->setText(QCoreApplication::translate("ChatServerForm", "Clear", nullptr));
        savePushButton->setText(QCoreApplication::translate("ChatServerForm", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatServerForm: public Ui_ChatServerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATSERVERFORM_H
