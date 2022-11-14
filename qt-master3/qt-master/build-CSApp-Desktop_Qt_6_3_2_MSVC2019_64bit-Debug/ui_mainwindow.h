/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionChattingClient;
    QAction *actionClientmanager;
    QAction *actionProductmanager;
    QAction *actionShopmanager;
    QWidget *centralwidget;
    QMdiArea *mdiArea;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuManage;
    QMenu *menuChatting;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1258, 932);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../build-CSApp-Desktop_Qt_6_3_2_MSVC2019_64bit-Debug/Quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon);
        actionChattingClient = new QAction(MainWindow);
        actionChattingClient->setObjectName(QString::fromUtf8("actionChattingClient"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../build-CSApp-Desktop_Qt_6_3_2_MSVC2019_64bit-Debug/Chattingclient.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChattingClient->setIcon(icon1);
        actionClientmanager = new QAction(MainWindow);
        actionClientmanager->setObjectName(QString::fromUtf8("actionClientmanager"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../build-CSApp-Desktop_Qt_6_3_2_MSVC2019_64bit-Debug/Client.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClientmanager->setIcon(icon2);
        actionProductmanager = new QAction(MainWindow);
        actionProductmanager->setObjectName(QString::fromUtf8("actionProductmanager"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../build-CSApp-Desktop_Qt_6_3_2_MSVC2019_64bit-Debug/Product.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionProductmanager->setIcon(icon3);
        actionShopmanager = new QAction(MainWindow);
        actionShopmanager->setObjectName(QString::fromUtf8("actionShopmanager"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../build-CSApp-Desktop_Qt_6_3_2_MSVC2019_64bit-Debug/Shop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShopmanager->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setGeometry(QRect(0, 0, 1251, 871));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1258, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuManage = new QMenu(menubar);
        menuManage->setObjectName(QString::fromUtf8("menuManage"));
        menuChatting = new QMenu(menubar);
        menuChatting->setObjectName(QString::fromUtf8("menuChatting"));
        MainWindow->setMenuBar(menubar);

        toolBar->addAction(actionClientmanager);
        toolBar->addAction(actionProductmanager);
        toolBar->addAction(actionShopmanager);
        toolBar->addSeparator();
        toolBar->addAction(actionChattingClient);
        toolBar->addSeparator();
        toolBar->addAction(actionQuit);
        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuManage->menuAction());
        menubar->addAction(menuChatting->menuAction());
        menuFile->addAction(actionQuit);
        menuManage->addAction(actionClientmanager);
        menuManage->addAction(actionProductmanager);
        menuManage->addAction(actionShopmanager);
        menuChatting->addAction(actionChattingClient);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionChattingClient->setText(QCoreApplication::translate("MainWindow", "ChattingClient", nullptr));
        actionClientmanager->setText(QCoreApplication::translate("MainWindow", "Clientmanager", nullptr));
        actionProductmanager->setText(QCoreApplication::translate("MainWindow", "Productmanager", nullptr));
        actionShopmanager->setText(QCoreApplication::translate("MainWindow", "Shopmanager", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuManage->setTitle(QCoreApplication::translate("MainWindow", "Manager", nullptr));
        menuChatting->setTitle(QCoreApplication::translate("MainWindow", "Chatting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
