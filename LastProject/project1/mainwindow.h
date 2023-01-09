<<<<<<< HEAD
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QDebug>
#include <QMenu>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void circle();
    void triangle();
    void rectangle();

private slots:
        void on_LoadButton_clicked();

private:

    QMenu* shapemenu;
    QMenu* sharpeningmenu;

    QAction* circleAction;
    QAction* triangleAction;
    QAction* rectangleAction;


    QString mResourceDir;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
=======
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QDebug>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:


private slots:
       // void LoadPushButton_clicked();
        //void on_imageLoad_clicked();

        void on_LoadButton_clicked();

private:

    QMenu* shapemenu;
    QMenu* sharpeningmenu;

    QString mResourceDir;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
>>>>>>> f905857853186c7457fc043aad79a03cdbaf0cc4
