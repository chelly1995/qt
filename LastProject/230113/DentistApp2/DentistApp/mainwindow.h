#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Layout;
class FMX;

class QSqlQuery;
class QSqlTableModel;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


    Layout *gridLayout;
    FMX *fmx;



    /* 환자 정보 DB */
    void patientLoad();

    /* 툴 버튼 생성 */
    void createToolButton();


    QSqlQuery *patientQuery;
    QSqlTableModel *patientQueryModel;

};
#endif // MAINWINDOW_H
