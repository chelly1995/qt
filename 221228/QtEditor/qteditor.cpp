#include "qteditor.h"
#include<QTextEdit>
#include<QMenuBar>
#include<QAction>
#include<QApplication>
#include<QToolBar>
#include<QFontComboBox>
#include<QDoubleSpinBox>
#include<QLabel>
#include<QStatusBar>
#include<QDockWidget>
#include<QMdiArea>
#include<QMdiSubWindow>
#include<QMessageBox>
#include<QFileDialog>
#include<QDebug>
#include<QColorDialog>
#include<QFontDialog>
#include<QWheelEvent>
#include<QPrinter>
#include<QPrintDialog>
#include<QHash>



QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent){
    mdiArea =new QMdiArea(this);
    setCentralWidget(mdiArea);


    //    QTextEdit *textedit =new QTextEdit(this);
    //  mdiArea->addSubWindow(textedit);


    QAction *quitAct= makeAction(":/images/quit.png", "&Quit","Ctrl+Q",tr("quit"),qApp,SLOT(quit()));
    QAction *newAct= makeAction(":/images/new.png", "&New","Ctrl+N",tr("make new file"),this,SLOT(newFile()));
    QAction *openAct= makeAction(":/images/open.jpg","&Open","Ctrl+O",tr("open file"),this,SLOT(openFile()));
    QAction *saveAct= makeAction(":/images/save.png","&Save","Ctrl+S",tr("save file"),this,SLOT(saveFile()));
    QAction *saveasAct= makeAction(":/images/saveas.png","Sa&ve as","Ctrl+V",tr("save as file"),this,SLOT(saveAsFile()));
    QAction *printAct= makeAction(":/images/print.jpg","&Print","Ctrl+P",tr("print file"),this,SLOT(print()));
    //람다를 활용하면 SLOT함수를 줄일수 있다.


    QAction *undoAct= makeAction(":/images/undo.jpg","&Undo","Ctrl+U",tr("undo text"),this,SLOT(connectWindow(QMdiSubWindow*)));
    QAction *redoAct= makeAction(":/images/redo.jpg","&Redo","Ctrl+R",tr("redo text"),this,SLOT(connectWindow(QMdiSubWindow*)));
    QAction *copyAct= makeAction(":/images/copy.png","&Copy","Ctrl+C",tr("copy text"),this,SLOT(connectWindow(QMdiSubWindow*)));
    QAction *cutAct= makeAction(":/images/cut.png","&Cut","Ctrl+X",tr("cut text"),this,SLOT(connectWindow(QMdiSubWindow*)));
    QAction *pasteAct= makeAction(":/images/paste.png","&Paste","Ctrl+V",tr("paste text"),this,SLOT(connectWindow(QMdiSubWindow*)));
    QAction *zoomInAct= makeAction(":/images/zoomIn.png","&ZoomIn","Ctrl+1",tr("zoomIn text"),this,SLOT(connectWindow(QMdiSubWindow*)));
    QAction *zoomOutAct= makeAction(":/images/zoomOut.png","&ZoomOut","Ctrl+2",tr("zoomOut text"),this,SLOT(connectWindow(QMdiSubWindow*)));


    QAction *fontAct= makeAction(":/images/font.png","&Font","",tr("font format"),this,SLOT(setFont()));
    QAction *colorAct= makeAction(":/images/color.png","&Color","",tr("color format"),this,SLOT(setColor()));


    // QAction *alignCenterAct =new QAction("&Center",this);
    // connect(alignCenterAct,SIGNAL(triggered()),this,SLOT(alignText()));
    QAction *alignCenterAct= makeAction(":/images/alignCenter.png","&Center","", tr("center format"),this,SLOT(alignText()));
    QAction *alignRightAct= makeAction(":/images/alignRight.png","&Right","",tr("right format"),this,SLOT(alignText()));
    QAction *alignLeftAct= makeAction(":/images/alignLeft.png","&Left","",tr("left format"),this,SLOT(alignText()));
    QAction *alignJustifyAct= makeAction(":/images/alignJustify.png","&Justify","",tr("left format"),this,SLOT(alignText()));
    QAction* helpAct = makeAction(":/images/help.png","&Help","",tr("help menu"),this,SLOT(help()));
    QAction* helpasAct = makeAction(":/images/helpas.png","&Help As","",tr("help menu"),qApp,SLOT(aboutQt()));

    QAction* cascadeAct = makeAction(":/images/cascade.jpg","&Casecade","",tr("casecade"),mdiArea,SLOT(cascadeSubWindows()));
    QAction* tileAct = makeAction(":/images/tile.png","&Tile","",tr("tile"),mdiArea,SLOT(tileSubWindows()));
    QAction* prevAct = makeAction(":/images/prev.png","&Prev","",tr("prev"),mdiArea,SLOT(activatePreviousSubWindow()));
    QAction* nextAct = makeAction(":/images/next.png","&Next","",tr("next"),mdiArea,SLOT(activateNextSubWindow()));
    QAction* closeAct = makeAction(":/images/close.png","&Close","",tr("close"),mdiArea,SLOT(closeActiveSubWindow()));
    QAction* closeAllAct = makeAction(":/images/closeAll.jpg","&closeAll","",tr("closeAll"),mdiArea,SLOT(closeAllSubWindows()));


    QLabel *label = new QLabel("Dock Widget",this);


    QDockWidget *dock =new QDockWidget("Dock Widget",this);

    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea,dock);
    dock->setWidget(label);


    fontComboBox =new QFontComboBox(this);        //font
    connect(fontComboBox,SIGNAL(currentFontChanged(QFont)),this,SLOT(fontComboBoxText(QFont)));
    sizeSPinBox =new QDoubleSpinBox(this);       //font size
    connect(sizeSPinBox,SIGNAL(valueChanged(double)),this,SLOT(sizeSPinBoxText(double)));

    QMenu *fileMenu = menuBar()->addMenu("&file");
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveasAct);
    fileMenu->addAction(printAct);
    fileMenu->addAction(quitAct);


    QMenu *textMenu = menuBar()->addMenu("&Text");
    textMenu->addAction(undoAct);
    textMenu->addAction(redoAct);
    textMenu->addSeparator();
    textMenu->addAction(copyAct);
    textMenu->addAction(cutAct);
    textMenu->addAction(pasteAct);
    textMenu->addSeparator();
    textMenu->addAction(zoomInAct);
    textMenu->addAction(zoomOutAct);
    textMenu->addAction(quitAct);

    QMenu *formatMenu = menuBar()->addMenu("&format");
    formatMenu->addAction(fontAct);
    formatMenu->addAction(colorAct);

    QMenu *alignMenu = formatMenu->addMenu("&Align");
    alignMenu->addAction(alignCenterAct);
    alignMenu->addAction(alignRightAct);
    alignMenu->addAction(alignLeftAct);
    alignMenu->addAction(alignJustifyAct);




    QToolBar * fileToolBar = addToolBar("&File");
    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    fileToolBar->addAction(newAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(openAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(saveAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(saveasAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(quitAct);

    windowMenu = menuBar()->addMenu("&Window");       //끄면 다시 키기 힘들기때문에 만들어줌
    windowMenu ->addAction(cascadeAct);
    windowMenu ->addAction(tileAct);
    windowMenu ->addAction(prevAct);
    windowMenu ->addAction(nextAct);
    windowMenu->addSeparator();
    windowMenu ->addAction(closeAct);
    windowMenu ->addAction(closeAllAct);
    windowMenu->addSeparator();
    windowMenu->addAction(fileToolBar->toggleViewAction());
    windowMenu->addAction(dock->toggleViewAction());
    windowMenu->addSeparator();

    QMenu *help = menuBar()->addMenu("&Help");
    help->addAction(helpAct);
    help->addAction(helpasAct);


    addToolBarBreak();          //다음 툴바는 아랫 줄로 위치


    QToolBar*formatToolbar = addToolBar("&Format");

    formatToolbar->addWidget(fontComboBox);
    formatToolbar->addSeparator();
    formatToolbar->addWidget(sizeSPinBox);

    QStatusBar*statusbar =statusBar();      //무조건 아래쪽 배치    상태바
    QLabel*statusLabel =new QLabel("Qt Editor",statusbar);      //
    statusLabel->setObjectName("StatusLabel");
    statusbar->addPermanentWidget(statusLabel);
    statusbar->showMessage("started",1500);

    actions.append(undoAct);
    actions.append(redoAct);
    actions.append(cutAct);
    actions.append(copyAct);
    actions.append(pasteAct);
    actions.append(zoomInAct);
    actions.append(zoomOutAct);
    connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
            SLOT(connectWindow(QMdiSubWindow*)));


    newFile();



}
//========================================= help ======================================================
void QtEditor::help()
{
    QMessageBox::StandardButton s = QMessageBox::question(this,"QMessageBox::showQuestion()","Qusetion Message",QMessageBox::Yes |QMessageBox::No |QMessageBox::Cancel);
    if(s==QMessageBox::Yes)
        about();
}


//========================================= help as ====================================================
void QtEditor::about()
{
    QMessageBox::information(this,tr("QtEditor"),tr("copyright by valentis"));
}

//=========================================makeAction ====================================================
QAction *QtEditor::makeAction(QString icon,QString name,QString shortCut,QString toolTip,QObject*recv,const char*slot)
{


    QAction *act =new QAction(name, this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    act->setShortcut(shortCut);
    act->setStatusTip(toolTip);     //상태바에 나타난다
    connect(act,SIGNAL(triggered()),recv,slot);
    //connect(act,signal,recv,slot);
    return act;
}
//========================================= new file ====================================================
void QtEditor::newFile()
{
    qDebug("Make New File");
    QAction * windowAct= new QAction("New File",this);

    windowMenu->addAction(windowAct);

    QTextEdit*textedit =new QTextEdit;
    connect(textedit,SIGNAL(destroyed(QObject*)),windowAct,SLOT(deleteLater()));
    textedit->setFontPointSize(11);
    mdiArea->addSubWindow(textedit);
    textedit->show();
    connect(textedit,SIGNAL(destroyed(QObject*)),this,SLOT(closeWindow()));
    connect(textedit,SIGNAL(cursorPositionChanged()),SLOT(setFontWidget()));
    windowHash[windowAct]=textedit;
    connect(windowAct,SIGNAL(triggered()),SLOT(selectWindow()));
    textedit->installEventFilter(this);

}

void QtEditor::selectWindow()
{
    QTextEdit*textedit = (QTextEdit*)windowHash[(QAction*)sender()];
    textedit ->setFocus();
}
//=========================================정렬 ====================================================
void QtEditor::alignText()
{
    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
    if(subWindow == nullptr)
        return;
    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());

    QAction*action =qobject_cast<QAction*>(sender());       //sender의 반환값이 object이므로 형변환을 한다.
    // if(action->text()=="&Center")                            //text안에 있는 Center라는 문자만 부른다.
    //     textedit->setAlignment(Qt::AlignCenter);
    if(action->text().contains("Center", Qt::CaseSensitive)){       //contains는 문자열에 포함되어있는 모든 문자를 부른다.
        textedit->setAlignment(Qt::AlignHCenter);
    }
    else if(action->text().contains("Right")){
        textedit->setAlignment(Qt::AlignRight);
    }
    else if(action->text().contains("left", Qt::CaseInsensitive)){
        textedit->setAlignment(Qt::AlignLeft);
    }
    else if(action->text().contains("Justify", Qt::CaseInsensitive)){
        textedit->setAlignment(Qt::AlignJustify);
    }
}
// ====================================방법 1============================================
//void QtEditor::menuEidt()
//{
//    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
//    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());

//    QAction * action = qobject_cast <QAction*>(sender());

//    if(action->text()=="&Undo")
//        textedit->undo();
//    else if(action->text()=="&Redo")
//        textedit->redo();
//    else if(action->text()=="&Cut")
//        textedit->cut();
//    else if(action->text()=="&Copy")
//        textedit->copy();
//    else if(action->text()=="&Paste")
//        textedit->paste();
//    else if(action->text()=="&ZoomIn")
//        textedit->zoomIn();
//    else if(action->text()=="&ZoomOut")
//        textedit->zoomOut();
//}
// ====================================방법 2(유지보수가 편하다)============================================
//void QtEditor::connectWindow(QMdiSubWindow*window)
//{
//    QTextEdit*textEdit =qobject_cast <QTextEdit*>(window->widget());
//    if(prevTextEdit != nullptr)
//    {
//        Q_FOREACH(QAction*action,actions)
//            action->disconnect(prevTextEdit);
//    }
//    prevTextEdit = textEdit;

//    const char *methods[7] = {
//        SLOT(undo( )), SLOT(redo( )), SLOT(copy( )), SLOT(cut( )),
//        SLOT(paste( )), SLOT(zoomIn( )), SLOT(zoomOut( ))
//    };
//    int cnt = 0;
//    Q_FOREACH(QAction *action, actions) {
//        connect(action, SIGNAL(triggered()), textEdit, methods[cnt++]);
//    }
//}
void QtEditor::connectWindow(QMdiSubWindow* window)
{
    if(window == nullptr) {
        prevTextEdit = nullptr;
        return;
    }
    QTextEdit *textEdit = qobject_cast<QTextEdit*>(window->widget( ));
    if(prevTextEdit != nullptr)
    {
        Q_FOREACH(QAction *action, actions)      /* 모든 QAction에 연결된 슬롯 해제 */
            action->disconnect(prevTextEdit);
    }
    prevTextEdit = textEdit;         /* 현재 객체를 다음 처리를 위해 저장 */

    // 슬롯들을 위한 배열
    const char *methods[7] = {
        SLOT(undo( )), SLOT(redo( )), SLOT(copy( )), SLOT(cut( )),
        SLOT(paste( )), SLOT(zoomIn( )), SLOT(zoomOut( ))
    };

    /* QAction에 현재 선택된 객체의 슬롯을 연결 */
    int cnt = 0;
    Q_FOREACH(QAction *action, actions) {
        connect(action, SIGNAL(triggered()), textEdit, methods[cnt++]);

    }
}
//========================================= font ====================================================

void QtEditor::fontComboBoxText(QFont Font)
{
    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
    if(subWindow == nullptr)
        return;
    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());

    textedit->setCurrentFont(Font);
}
//========================================= font size ====================================================
void QtEditor::sizeSPinBoxText(double qreal)
{
    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
    if(subWindow == nullptr)
        return;
    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());

    textedit->setFontPointSize(qreal);
}

void QtEditor:: setFontWidget()
{
    //qDebug("1");
    QTextEdit *textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QFont font = textedit->currentFont();
    fontComboBox ->setCurrentFont(font);
    sizeSPinBox->setValue(font.pointSizeF());
}

void QtEditor::openFile()
{
    QString filename = QFileDialog::getOpenFileName(this,"Select file to open",
                                                    ".","Text File(*.text *.txt *.html *.htm *.c *.cpp *.h)");
    qDebug()<<filename;

    QFileInfo fileInfo (filename);
    if(fileInfo.isReadable())
    {
        QFile *file = new QFile(filename);
        file->open(QIODevice::ReadOnly|QIODevice::Truncate);
        QByteArray msg =file->readAll();
        file->close();
        delete file;


        //QTextEdit*textedit =new QTextEdit(this);
        //        textedit->setWindowTitle(filename);
        //        textedit->setHtml(msg);
        //        mdiArea->addSubWindow(textedit);
        //        textedit->show();
        newFile();
        QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
        textedit->setWindowTitle(filename);
        windowHash.key(textedit)->setText(filename);
        if(fileInfo.suffix() == "htm" || fileInfo.suffix() == "html")
            textedit->setHtml(msg);
        else
            textedit->setPlainText(msg);         //서식 없는 문자열일 때
    }
    else
    {
        QMessageBox::warning(this,"Error","can't Read this file",QMessageBox::Ok);
    }
}

void QtEditor::saveFile()
{

    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
    if(subWindow == nullptr)
        return;
    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
    QString filename =textedit->windowTitle();

    if(!filename.length()){
        filename =QFileDialog::getSaveFileName(this,"Select file to save",
                                               ".","Text File(*.text *.txt *.html *.htm *.c *.cpp *.h)");
        textedit->setWindowTitle(filename);
    }
    QFile*file=new QFile(filename);
    file->open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
    QFileInfo fileInfo(filename);
    if(fileInfo.isWritable())
    {
        //        OByteArray msg;
        //        msg.append(textedit->toHtml());
        //        file->wirte(msg);
        QByteArray msg;
        if(fileInfo.suffix() == "htm" || fileInfo.suffix() == "html")
        {
            msg = textedit->toHtml( ).toUtf8( );
        }
        else
        {
            msg = textedit->toPlainText().toUtf8();
        }
        file->write(msg);
    }
    else
    {
        QMessageBox::warning(this,"Error","can't Save this file",QMessageBox::Ok);
    }
    qDebug()<<filename;
    windowHash.key(textedit)->setText(filename);
    file->close();
    delete file;


}
void QtEditor::saveAsFile()
{
    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
    if(subWindow == nullptr)
        return;
    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
    QString filename = QFileDialog::getSaveFileName(this,"Select file to save as",
                                                    ".","Text File(*.text *.txt *.html *.htm *.c *.cpp *.h)");
    textedit->setWindowTitle(filename);
    QFile*file =new QFile(filename);
    qDebug()<<filename;
    file->open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
    QFileInfo fileInfo(filename);
    if(fileInfo.isWritable())
    {
        //        OByteArray msg;
        //        msg.append(textedit->toHtml());
        //        file->wirte(msg);
        // QString을 QByteArray로 변환
        QByteArray msg;
        if(fileInfo.suffix() == "htm" || fileInfo.suffix() == "html")
        {
            msg = textedit->toHtml( ).toUtf8( );
        }
        else
        {
            msg = textedit->toPlainText().toUtf8();
        }
        file->write(msg);
    }
    else
    {
        QMessageBox::warning(this,"Error","can't Save this file",QMessageBox::Ok);
    }
    qDebug()<<filename;
    windowHash.key(textedit)->setText(filename);
    file->close();
    delete file;
}
void QtEditor::setColor()
{
    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
    if(subWindow == nullptr)
        return;
    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
    QColor color =QColorDialog::getColor(textedit->textColor(),this);
    if(color.isValid())textedit->setTextColor(color);
}
void QtEditor::setFont()
{
    bool ok;
    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
    if(subWindow == nullptr)
        return;
    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
    QFont font =QFontDialog::getFont(&ok,textedit->currentFont(),this);
    if(ok)textedit->setCurrentFont(font);

}
void QtEditor::print()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setFullPage(true);
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec()==QDialog::Accepted)
    {
        QTextEdit*textedit =(QTextEdit*)mdiArea->currentSubWindow()->widget();
        textedit->print(&printer);
    }
}

void QtEditor::closeWindow()
{
    QTextEdit*textedit =(QTextEdit*)sender();
    windowMenu->removeAction(windowHash.key(textedit));
    windowHash.remove(windowHash.key(textedit));
}

bool QtEditor::eventFilter(QObject *obj,QEvent*event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent =static_cast<QKeyEvent*>(event);
        qDebug("Key press %d",keyEvent->key());
        return false;
    }else{
        return QObject::eventFilter(obj,event);
    }
}
//==================================================마우스 이벤트 시도(실패)========================================
//bool QtEditor::eventFilter1(QObject *obj,QEvent*event)
//{
//    if(event->type() == QEvent::MouseButtonPress)
//    {
//       // QMouseEvent *mouseEvent =static_cast<QMouseEvent*>(event);
//        qDebug("Key press %d");
//        return true;
//    }else{
//        return QObject::eventFilter(obj,event);
//    }
//}

//void QtEditor::wheelEvent(QWheelEvent *event)
//{
//   QTextEdit*textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
//   QPoint numDegrees  = event->angleDelta();
//   if(numDegrees.y() <= 0)
//   {
//       textedit->setFontPointSize();
//    }
//}


QtEditor::~QtEditor()
{
}

//void QtEditor::undoText()
//{
//    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
//    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());

//     textedit->undo();

//}
//void QtEditor::redoText()
//{
//    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
//    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());

//     textedit->redo();

//}
//void QtEditor::cutText()
//{
//    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
//    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());

//     textedit->cut();

//}
//void QtEditor::copyText()
//{
//    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
//    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());

//     textedit->copy();

//}
//void QtEditor::pasteText()
//{
//    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
//    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());

//     textedit->paste();

//}
//void QtEditor::zoomInText()
//{
//    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
//    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());

//     textedit->zoomIn();

//}
//void QtEditor::zoomOutText()
//{
//    QMdiSubWindow*subWindow =mdiArea->currentSubWindow();
//    QTextEdit*textedit = dynamic_cast<QTextEdit*>(subWindow->widget());

//     textedit->zoomOut();
//}
