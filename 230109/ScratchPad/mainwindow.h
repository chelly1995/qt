#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ScratchPad;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ScratchPad *m_scratchPad;

private slots:
    void on_actionSave_triggered();

    void on_actionColor_triggered();


private:
    Ui::MainWindow *ui;
    QColor paint_color;
};

#endif // MAINWINDOW_H
