/********************************************************************************
** Form generated from reading UI file 'clientmanagerform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTMANAGERFORM_H
#define UI_CLIENTMANAGERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientManagerForm
{
public:
    QHBoxLayout *horizontalLayout_2;
    QTableView *clienttableView;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *inputPage;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *idLabel;
    QLineEdit *idLineEdit;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *PhoneNumberLabel;
    QLineEdit *phoneNumberLineEdit;
    QLabel *addressLabel;
    QLineEdit *addressLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *addHorizontalLayout;
    QPushButton *addPushButton;
    QPushButton *modifyPushButton;
    QWidget *searchPage;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *searchTreeWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *searchComboBox;
    QLineEdit *searchLineEdit;
    QPushButton *searchPushButton;

    void setupUi(QWidget *ClientManagerForm)
    {
        if (ClientManagerForm->objectName().isEmpty())
            ClientManagerForm->setObjectName(QString::fromUtf8("ClientManagerForm"));
        ClientManagerForm->resize(660, 419);
        horizontalLayout_2 = new QHBoxLayout(ClientManagerForm);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        clienttableView = new QTableView(ClientManagerForm);
        clienttableView->setObjectName(QString::fromUtf8("clienttableView"));
        clienttableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout_2->addWidget(clienttableView);

        splitter = new QSplitter(ClientManagerForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        inputPage = new QWidget();
        inputPage->setObjectName(QString::fromUtf8("inputPage"));
        inputPage->setGeometry(QRect(0, 0, 322, 359));
        horizontalLayout_4 = new QHBoxLayout(inputPage);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        idLabel = new QLabel(inputPage);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        idLabel->setLineWidth(1);
        idLabel->setTextFormat(Qt::AutoText);

        formLayout->setWidget(0, QFormLayout::LabelRole, idLabel);

        idLineEdit = new QLineEdit(inputPage);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));
        idLineEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, idLineEdit);

        nameLabel = new QLabel(inputPage);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setLineWidth(1);

        formLayout->setWidget(4, QFormLayout::SpanningRole, nameLabel);

        nameLineEdit = new QLineEdit(inputPage);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, nameLineEdit);

        PhoneNumberLabel = new QLabel(inputPage);
        PhoneNumberLabel->setObjectName(QString::fromUtf8("PhoneNumberLabel"));

        formLayout->setWidget(8, QFormLayout::SpanningRole, PhoneNumberLabel);

        phoneNumberLineEdit = new QLineEdit(inputPage);
        phoneNumberLineEdit->setObjectName(QString::fromUtf8("phoneNumberLineEdit"));

        formLayout->setWidget(11, QFormLayout::FieldRole, phoneNumberLineEdit);

        addressLabel = new QLabel(inputPage);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));

        formLayout->setWidget(12, QFormLayout::SpanningRole, addressLabel);

        addressLineEdit = new QLineEdit(inputPage);
        addressLineEdit->setObjectName(QString::fromUtf8("addressLineEdit"));

        formLayout->setWidget(14, QFormLayout::FieldRole, addressLineEdit);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        addHorizontalLayout = new QHBoxLayout();
        addHorizontalLayout->setObjectName(QString::fromUtf8("addHorizontalLayout"));
        addPushButton = new QPushButton(inputPage);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        addHorizontalLayout->addWidget(addPushButton);

        modifyPushButton = new QPushButton(inputPage);
        modifyPushButton->setObjectName(QString::fromUtf8("modifyPushButton"));

        addHorizontalLayout->addWidget(modifyPushButton);


        verticalLayout->addLayout(addHorizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        toolBox->addItem(inputPage, QString::fromUtf8("&Input"));
        searchPage = new QWidget();
        searchPage->setObjectName(QString::fromUtf8("searchPage"));
        searchPage->setGeometry(QRect(0, 0, 322, 359));
        horizontalLayout_3 = new QHBoxLayout(searchPage);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        searchTreeWidget = new QTreeWidget(searchPage);
        searchTreeWidget->setObjectName(QString::fromUtf8("searchTreeWidget"));

        verticalLayout_2->addWidget(searchTreeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        searchComboBox = new QComboBox(searchPage);
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->setObjectName(QString::fromUtf8("searchComboBox"));

        horizontalLayout->addWidget(searchComboBox);

        searchLineEdit = new QLineEdit(searchPage);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout->addWidget(searchLineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        searchPushButton = new QPushButton(searchPage);
        searchPushButton->setObjectName(QString::fromUtf8("searchPushButton"));
        searchPushButton->setToolTipDuration(-1);

        verticalLayout_2->addWidget(searchPushButton);


        horizontalLayout_3->addLayout(verticalLayout_2);

        toolBox->addItem(searchPage, QString::fromUtf8("&Search"));
        splitter->addWidget(toolBox);

        horizontalLayout_2->addWidget(splitter);

#if QT_CONFIG(shortcut)
        idLabel->setBuddy(idLineEdit);
        nameLabel->setBuddy(nameLineEdit);
        PhoneNumberLabel->setBuddy(phoneNumberLineEdit);
        addressLabel->setBuddy(addressLineEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(ClientManagerForm);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientManagerForm);
    } // setupUi

    void retranslateUi(QWidget *ClientManagerForm)
    {
        ClientManagerForm->setWindowTitle(QCoreApplication::translate("ClientManagerForm", "Form", nullptr));
        idLabel->setText(QCoreApplication::translate("ClientManagerForm", "I&D", nullptr));
        nameLabel->setText(QCoreApplication::translate("ClientManagerForm", "&Name", nullptr));
        PhoneNumberLabel->setText(QCoreApplication::translate("ClientManagerForm", "&Phone Number", nullptr));
        addressLabel->setText(QCoreApplication::translate("ClientManagerForm", "&Address", nullptr));
        addPushButton->setText(QCoreApplication::translate("ClientManagerForm", "&Add", nullptr));
        modifyPushButton->setText(QCoreApplication::translate("ClientManagerForm", "&Modify", nullptr));
        toolBox->setItemText(toolBox->indexOf(inputPage), QCoreApplication::translate("ClientManagerForm", "&Input", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = searchTreeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("ClientManagerForm", "Address", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ClientManagerForm", "Phone Number", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ClientManagerForm", "Name", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ClientManagerForm", "ID", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("ClientManagerForm", "ID", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("ClientManagerForm", "Name", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("ClientManagerForm", "Phone Number", nullptr));
        searchComboBox->setItemText(3, QCoreApplication::translate("ClientManagerForm", "Address", nullptr));

        searchPushButton->setText(QCoreApplication::translate("ClientManagerForm", "S&earch", nullptr));
        toolBox->setItemText(toolBox->indexOf(searchPage), QCoreApplication::translate("ClientManagerForm", "&Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientManagerForm: public Ui_ClientManagerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTMANAGERFORM_H
