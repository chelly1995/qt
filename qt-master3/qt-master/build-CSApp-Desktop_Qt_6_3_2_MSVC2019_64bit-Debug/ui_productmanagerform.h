/********************************************************************************
** Form generated from reading UI file 'productmanagerform.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTMANAGERFORM_H
#define UI_PRODUCTMANAGERFORM_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductManagerForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter;
    QToolBox *toolBox;
    QWidget *inputPage;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *PidLabel;
    QLineEdit *PidLineEdit;
    QLabel *ProductNameLabel;
    QLineEdit *nameLineEdit;
    QLabel *priceLabel;
    QLineEdit *PriceLineEdit;
    QLabel *stockLabel;
    QLineEdit *stockLineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *addPushButton;
    QPushButton *modifyPushButton;
    QWidget *searchPage;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QTableView *searchTableView;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *searchComboBox;
    QLineEdit *searchLineEdit;
    QPushButton *searchPushButton;
    QTableView *producttableView;

    void setupUi(QWidget *ProductManagerForm)
    {
        if (ProductManagerForm->objectName().isEmpty())
            ProductManagerForm->setObjectName(QString::fromUtf8("ProductManagerForm"));
        ProductManagerForm->resize(692, 441);
        gridLayout = new QGridLayout(ProductManagerForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        splitter = new QSplitter(ProductManagerForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setMouseTracking(false);
        toolBox->setAcceptDrops(false);
        inputPage = new QWidget();
        inputPage->setObjectName(QString::fromUtf8("inputPage"));
        inputPage->setGeometry(QRect(0, 0, 336, 379));
        verticalLayout_3 = new QVBoxLayout(inputPage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        PidLabel = new QLabel(inputPage);
        PidLabel->setObjectName(QString::fromUtf8("PidLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, PidLabel);

        PidLineEdit = new QLineEdit(inputPage);
        PidLineEdit->setObjectName(QString::fromUtf8("PidLineEdit"));
        PidLineEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, PidLineEdit);

        ProductNameLabel = new QLabel(inputPage);
        ProductNameLabel->setObjectName(QString::fromUtf8("ProductNameLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, ProductNameLabel);

        nameLineEdit = new QLineEdit(inputPage);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nameLineEdit);

        priceLabel = new QLabel(inputPage);
        priceLabel->setObjectName(QString::fromUtf8("priceLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, priceLabel);

        PriceLineEdit = new QLineEdit(inputPage);
        PriceLineEdit->setObjectName(QString::fromUtf8("PriceLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, PriceLineEdit);

        stockLabel = new QLabel(inputPage);
        stockLabel->setObjectName(QString::fromUtf8("stockLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, stockLabel);

        stockLineEdit = new QLineEdit(inputPage);
        stockLineEdit->setObjectName(QString::fromUtf8("stockLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, stockLineEdit);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 138, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addPushButton = new QPushButton(inputPage);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        horizontalLayout->addWidget(addPushButton);

        modifyPushButton = new QPushButton(inputPage);
        modifyPushButton->setObjectName(QString::fromUtf8("modifyPushButton"));

        horizontalLayout->addWidget(modifyPushButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        toolBox->addItem(inputPage, QString::fromUtf8("&Input"));
        searchPage = new QWidget();
        searchPage->setObjectName(QString::fromUtf8("searchPage"));
        searchPage->setGeometry(QRect(0, 0, 336, 379));
        verticalLayout_4 = new QVBoxLayout(searchPage);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        searchTableView = new QTableView(searchPage);
        searchTableView->setObjectName(QString::fromUtf8("searchTableView"));
        searchTableView->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(searchTableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        searchComboBox = new QComboBox(searchPage);
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->addItem(QString());
        searchComboBox->setObjectName(QString::fromUtf8("searchComboBox"));

        horizontalLayout_2->addWidget(searchComboBox);

        searchLineEdit = new QLineEdit(searchPage);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout_2->addWidget(searchLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        searchPushButton = new QPushButton(searchPage);
        searchPushButton->setObjectName(QString::fromUtf8("searchPushButton"));

        verticalLayout_2->addWidget(searchPushButton);


        verticalLayout_4->addLayout(verticalLayout_2);

        toolBox->addItem(searchPage, QString::fromUtf8("&Search"));
        splitter->addWidget(toolBox);

        horizontalLayout_3->addWidget(splitter);


        gridLayout->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        producttableView = new QTableView(ProductManagerForm);
        producttableView->setObjectName(QString::fromUtf8("producttableView"));
        producttableView->verticalHeader()->setVisible(false);

        gridLayout->addWidget(producttableView, 0, 0, 1, 1);

#if QT_CONFIG(shortcut)
        PidLabel->setBuddy(PidLineEdit);
        ProductNameLabel->setBuddy(nameLineEdit);
        priceLabel->setBuddy(PriceLineEdit);
        stockLabel->setBuddy(stockLineEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(ProductManagerForm);

        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ProductManagerForm);
    } // setupUi

    void retranslateUi(QWidget *ProductManagerForm)
    {
        ProductManagerForm->setWindowTitle(QCoreApplication::translate("ProductManagerForm", "Form", nullptr));
        PidLabel->setText(QCoreApplication::translate("ProductManagerForm", "I&D", nullptr));
        ProductNameLabel->setText(QCoreApplication::translate("ProductManagerForm", "&ProductName", nullptr));
        priceLabel->setText(QCoreApplication::translate("ProductManagerForm", "&Price", nullptr));
        stockLabel->setText(QCoreApplication::translate("ProductManagerForm", "&Stock", nullptr));
        addPushButton->setText(QCoreApplication::translate("ProductManagerForm", "&Add", nullptr));
        modifyPushButton->setText(QCoreApplication::translate("ProductManagerForm", "&Modify", nullptr));
        toolBox->setItemText(toolBox->indexOf(inputPage), QCoreApplication::translate("ProductManagerForm", "&Input", nullptr));
        searchComboBox->setItemText(0, QCoreApplication::translate("ProductManagerForm", "ID", nullptr));
        searchComboBox->setItemText(1, QCoreApplication::translate("ProductManagerForm", "Product Name", nullptr));
        searchComboBox->setItemText(2, QCoreApplication::translate("ProductManagerForm", "Price", nullptr));
        searchComboBox->setItemText(3, QCoreApplication::translate("ProductManagerForm", "Stock", nullptr));

        searchPushButton->setText(QCoreApplication::translate("ProductManagerForm", "S&each", nullptr));
        toolBox->setItemText(toolBox->indexOf(searchPage), QCoreApplication::translate("ProductManagerForm", "&Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductManagerForm: public Ui_ProductManagerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTMANAGERFORM_H
