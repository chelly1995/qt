/********************************************************************************
** Form generated from reading UI file 'shopmanagerform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPMANAGERFORM_H
#define UI_SHOPMANAGERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShopManagerForm
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QTreeWidget *treeWidget;
    QToolBox *toolBox;
    QWidget *inputPage;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *sidLabel;
    QLineEdit *sidLineEdit;
    QLabel *clientnameLabel;
    QComboBox *ClientnameComboBox;
    QLabel *ProductNameLabel;
    QLabel *quantityLabel;
    QLineEdit *quantityLineEdit;
    QLabel *PriceLabel;
    QLineEdit *priceLineEdit;
    QLabel *totalLabel;
    QLineEdit *totalLineEdit;
    QComboBox *ProductnameComboBox;
    QVBoxLayout *verticalLayout;
    QTreeWidget *clienttreeWidget;
    QTreeWidget *producttreeWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addPushButton;
    QPushButton *modifyPushButton;
    QWidget *searchPage;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QTreeWidget *searchTreeWidget;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *searchComboBox;
    QLineEdit *searchLineEdit;
    QPushButton *searchPushButton;

    void setupUi(QWidget *ShopManagerForm)
    {
        if (ShopManagerForm->objectName().isEmpty())
            ShopManagerForm->setObjectName(QString::fromUtf8("ShopManagerForm"));
        ShopManagerForm->resize(701, 451);
        gridLayout = new QGridLayout(ShopManagerForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(ShopManagerForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        treeWidget = new QTreeWidget(splitter);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        splitter->addWidget(treeWidget);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        inputPage = new QWidget();
        inputPage->setObjectName(QString::fromUtf8("inputPage"));
        inputPage->setGeometry(QRect(0, 0, 352, 391));
        verticalLayout_2 = new QVBoxLayout(inputPage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        sidLabel = new QLabel(inputPage);
        sidLabel->setObjectName(QString::fromUtf8("sidLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, sidLabel);

        sidLineEdit = new QLineEdit(inputPage);
        sidLineEdit->setObjectName(QString::fromUtf8("sidLineEdit"));
        sidLineEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, sidLineEdit);

        clientnameLabel = new QLabel(inputPage);
        clientnameLabel->setObjectName(QString::fromUtf8("clientnameLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, clientnameLabel);

        ClientnameComboBox = new QComboBox(inputPage);
        ClientnameComboBox->setObjectName(QString::fromUtf8("ClientnameComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ClientnameComboBox);

        ProductNameLabel = new QLabel(inputPage);
        ProductNameLabel->setObjectName(QString::fromUtf8("ProductNameLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, ProductNameLabel);

        quantityLabel = new QLabel(inputPage);
        quantityLabel->setObjectName(QString::fromUtf8("quantityLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, quantityLabel);

        quantityLineEdit = new QLineEdit(inputPage);
        quantityLineEdit->setObjectName(QString::fromUtf8("quantityLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, quantityLineEdit);

        PriceLabel = new QLabel(inputPage);
        PriceLabel->setObjectName(QString::fromUtf8("PriceLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, PriceLabel);

        priceLineEdit = new QLineEdit(inputPage);
        priceLineEdit->setObjectName(QString::fromUtf8("priceLineEdit"));
        priceLineEdit->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, priceLineEdit);

        totalLabel = new QLabel(inputPage);
        totalLabel->setObjectName(QString::fromUtf8("totalLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, totalLabel);

        totalLineEdit = new QLineEdit(inputPage);
        totalLineEdit->setObjectName(QString::fromUtf8("totalLineEdit"));
        totalLineEdit->setReadOnly(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, totalLineEdit);

        ProductnameComboBox = new QComboBox(inputPage);
        ProductnameComboBox->setObjectName(QString::fromUtf8("ProductnameComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ProductnameComboBox);


        verticalLayout_2->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        clienttreeWidget = new QTreeWidget(inputPage);
        clienttreeWidget->setObjectName(QString::fromUtf8("clienttreeWidget"));

        verticalLayout->addWidget(clienttreeWidget);

        producttreeWidget = new QTreeWidget(inputPage);
        producttreeWidget->setObjectName(QString::fromUtf8("producttreeWidget"));

        verticalLayout->addWidget(producttreeWidget);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addPushButton = new QPushButton(inputPage);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        horizontalLayout->addWidget(addPushButton);

        modifyPushButton = new QPushButton(inputPage);
        modifyPushButton->setObjectName(QString::fromUtf8("modifyPushButton"));

        horizontalLayout->addWidget(modifyPushButton);


        verticalLayout_2->addLayout(horizontalLayout);

        toolBox->addItem(inputPage, QString::fromUtf8("&Input"));
        searchPage = new QWidget();
        searchPage->setObjectName(QString::fromUtf8("searchPage"));
        searchPage->setGeometry(QRect(0, 0, 352, 391));
        verticalLayout_4 = new QVBoxLayout(searchPage);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        searchTreeWidget = new QTreeWidget(searchPage);
        searchTreeWidget->setObjectName(QString::fromUtf8("searchTreeWidget"));

        verticalLayout_3->addWidget(searchTreeWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        searchComboBox = new QComboBox(searchPage);
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->setObjectName(QString::fromUtf8("searchComboBox"));

        horizontalLayout_2->addWidget(searchComboBox);

        searchLineEdit = new QLineEdit(searchPage);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout_2->addWidget(searchLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        searchPushButton = new QPushButton(searchPage);
        searchPushButton->setObjectName(QString::fromUtf8("searchPushButton"));

        verticalLayout_3->addWidget(searchPushButton);


        verticalLayout_4->addLayout(verticalLayout_3);

        toolBox->addItem(searchPage, QString::fromUtf8("&Search"));
        splitter->addWidget(toolBox);

        gridLayout->addWidget(splitter, 1, 0, 1, 1);

#if QT_CONFIG(shortcut)
        sidLabel->setBuddy(sidLineEdit);
        clientnameLabel->setBuddy(ClientnameComboBox);
        ProductNameLabel->setBuddy(ProductnameComboBox);
        quantityLabel->setBuddy(quantityLineEdit);
        PriceLabel->setBuddy(priceLineEdit);
        totalLabel->setBuddy(totalLineEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(ShopManagerForm);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ShopManagerForm);
    } // setupUi

    void retranslateUi(QWidget *ShopManagerForm)
    {
        ShopManagerForm->setWindowTitle(QCoreApplication::translate("ShopManagerForm", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("ShopManagerForm", "Total", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("ShopManagerForm", "Quantity", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("ShopManagerForm", "Price", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ShopManagerForm", "ProductName", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ShopManagerForm", "ClientName", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ShopManagerForm", "SID", nullptr));
        sidLabel->setText(QCoreApplication::translate("ShopManagerForm", "S&ID", nullptr));
        clientnameLabel->setText(QCoreApplication::translate("ShopManagerForm", "&ClientName", nullptr));
        ProductNameLabel->setText(QCoreApplication::translate("ShopManagerForm", "&ProductName", nullptr));
        quantityLabel->setText(QCoreApplication::translate("ShopManagerForm", "&Quantity", nullptr));
        PriceLabel->setText(QCoreApplication::translate("ShopManagerForm", "&Price", nullptr));
        totalLabel->setText(QCoreApplication::translate("ShopManagerForm", "&Total", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = clienttreeWidget->headerItem();
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("ShopManagerForm", "Address", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("ShopManagerForm", "PhoneNumber", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("ShopManagerForm", "ClinetName", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = producttreeWidget->headerItem();
        ___qtreewidgetitem2->setText(2, QCoreApplication::translate("ShopManagerForm", "Stock", nullptr));
        ___qtreewidgetitem2->setText(1, QCoreApplication::translate("ShopManagerForm", "Price", nullptr));
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("ShopManagerForm", "ProductName", nullptr));
        addPushButton->setText(QCoreApplication::translate("ShopManagerForm", "&Add", nullptr));
        modifyPushButton->setText(QCoreApplication::translate("ShopManagerForm", "&Modify", nullptr));
        toolBox->setItemText(toolBox->indexOf(inputPage), QCoreApplication::translate("ShopManagerForm", "&Input", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = searchTreeWidget->headerItem();
        ___qtreewidgetitem3->setText(4, QCoreApplication::translate("ShopManagerForm", "Quantity", nullptr));
        ___qtreewidgetitem3->setText(3, QCoreApplication::translate("ShopManagerForm", "Price", nullptr));
        ___qtreewidgetitem3->setText(2, QCoreApplication::translate("ShopManagerForm", "ProductName", nullptr));
        ___qtreewidgetitem3->setText(1, QCoreApplication::translate("ShopManagerForm", "ClientName", nullptr));
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("ShopManagerForm", "SID", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("ShopManagerForm", "ID", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("ShopManagerForm", "ClientName", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("ShopManagerForm", "ProductName", nullptr));
        searchComboBox->setItemText(3, QCoreApplication::translate("ShopManagerForm", "Price", nullptr));
        searchComboBox->setItemText(4, QCoreApplication::translate("ShopManagerForm", "Quantity", nullptr));

        searchPushButton->setText(QCoreApplication::translate("ShopManagerForm", "&Search", nullptr));
        toolBox->setItemText(toolBox->indexOf(searchPage), QCoreApplication::translate("ShopManagerForm", "&Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShopManagerForm: public Ui_ShopManagerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPMANAGERFORM_H
