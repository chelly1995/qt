#ifndef QTEDITOR_H
#define QTEDITOR_H
//#include "qtextedit.h"
#include <QMainWindow>
#include<QList>
#include <QSettings>

class QAction;
class QTextEdit;
class QMdiArea;
class QMdiSubWindow;
class QFontComboBox;
class QDoubleSpinBox;
//class QWheelEvent;

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

    // virtual void wheelEvent(QWheelEvent* event);

private:
    //  QTextEdit *textedit;
    QMdiArea*mdiArea;
    QList<QAction*> actions;
    QTextEdit* prevTextEdit = nullptr;
    QFontComboBox*fontComboBox;
    QDoubleSpinBox*sizeSPinBox;
    QHash<QAction*,QWidget*> windowHash;
    QMenu* windowMenu;
    QCloseEvent* event;
    bool eventFilter(QObject *obj,QEvent*event);
    //bool eventFilter1(QObject *obj,QEvent*event);

public slots:
    void connectWindow(QMdiSubWindow*window);
    //void menuEidt();
    void newFile();
    void about();
    // void cutFile();
    void alignText();
    void help();
    void setFontWidget();
    void saveAsFile();
    void saveFile();
    void openFile();
    void setColor();
    void setFont();
    void print();
    void selectWindow();
    void closeWindow();
    void writeSettings();
    void readSettings();
    void closeEvent();

    //    void undoText();
    //    void redoText();
    //    void cutText();
    //    void copyText();
    //    void zoomInText();
    //    void zoomOutText();
    //    void pasteText();
    void fontComboBoxText(QFont);
    void sizeSPinBoxText(double);
    QAction *makeAction(QString ,QString ,QString shortCut,QString toolTip,QObject*recv,const char*slot);
};
#endif // QTEDITOR_H
