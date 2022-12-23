#include "widget.h"

#ifdef __APPLE__
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{

    Action = 0;

    setWindowTitle("OpenGL Viewing");
    resize(600,600);
}

Widget::~Widget()
{
}

void Widget::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0,0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glLoadIdentity();
    //  --------------- glLoadIdentity ---------------

    //    glPushMatrix();
    //    glutWireTeapot(0.2);

    //    glTranslatef(0.6, 0.0, 0.0);
    //    glutWireTeapot(0.2);

    //    glLoadIdentity();
    //    glTranslatef(0.0, 0.6, 0.0);
    //    glutWireTeapot(0.2);

    //    glPopMatrix();

    //  --------------- Push, Pop ---------------

    //    glMatrixMode(GL_MODELVIEW);
    //    glPushMatrix();

    //    glutWireTeapot(0.2);

    //    glPushMatrix();
    //    glTranslatef(0.6, 0.0, 0.0);
    //    glutWireTeapot(0.2);
    //    glPopMatrix();

    //    glTranslatef(0.0,0.6, 0.0);
    //    glutWireTeapot(0.2);

    //    glPopMatrix();

    //  --------------- 확대 / 축소 ---------------

    //        glMatrixMode(GL_MODELVIEW);
    //        glPushMatrix();
    //        glScalef(2.0, 3.0, 1.0);

    //        glutWireTeapot(0.2);

    //        glPopMatrix();

    // ---------------- 뒤집은 주전자 ----------------

    //    glMatrixMode(GL_MODELVIEW);
    //    glPushMatrix();
    //    glScalef(-2.0, 3.0, 1.0);

    //    glutWireTeapot(0.2);

    //    glPopMatrix();

    //    glFlush();


    // ------------------ 주전자 회전 ------------------

    //    glMatrixMode(GL_MODELVIEW);
    //    glPushMatrix();
    //    //glRotatef(45.0,1.0,0.0,0.0);    // x축을 기준으로 45도 회전

    //    //glRotatef(45.0,0.0,1.0,0.0);    // y축을 기준으로 45도 회전

    //    glRotatef(45.0,0.0,0.0,1.0);    // z축을 기준으로 45도 회전

    //    glutWireTeapot(0.4);

    //    glPopMatrix();
    //    glFlush();


    // ------------------- 복합 변환 ------------------

    //    glMatrixMode(GL_MODELVIEW);
    //    glPushMatrix();
    //    //glTranslatef(0.5,0.5,0.0);
    //    //glScalef(1.5,1.5,1.0);

    //    glScalef(1.5,1.5,1.0);
    //    glTranslatef(0.5,0.5,0.0);

    //    glutWireTeapot(0.2);
    //    glPopMatrix();
    //    glFlush();

    // --------------- 복합 변환 (삼각형) ----------------

    //    glMatrixMode(GL_MODELVIEW);
    //    glPushMatrix();

    //    glBegin(GL_TRIANGLES);
    //    glVertex2f(0.5,0.8);
    //    glVertex2f(0.2,0.2);
    //    glVertex2f(0.8,0.2);
    //    glEnd();

    //    glRotatef(45.0,0.0, 0.00, 1.0);

    //    glColor3f(1,1,0);
    //    glBegin(GL_TRIANGLES);
    //    glVertex2f(0.5, 0.8);
    //    glVertex2f(0.2, 0.2);
    //    glVertex2f(0.8, 0.2);
    //    glEnd();

    //    glPopMatrix();
    //    glFlush();

    // ----------------- 복합 변환 ----------------

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5,0.8);
    glVertex2f(0.2,0.2);
    glVertex2f(0.8,0.2);
    glEnd();

    glTranslatef(0.5,0.5,0.0);
    glRotatef(45.0, 0.0,0.0, 1.0);
    glTranslatef(-0.5, -0.5, 0.0);

    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5,0.8);
    glVertex2f(0.2,0.2);
    glVertex2f(0.8,0.2);
    glEnd();

    glPopMatrix();
    glFlush();

}

void Widget::keyPressEvent(QKeyEvent*event)
{

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);


    switch(event->key()){

    case Qt::Key_Z:     // 변환 없음
        break;

    case Qt::Key_1:     // 이동
        break;

    case Qt::Key_2:     // 엉뚱한 위치에 나타나는 이동
        break;

    case Qt::Key_3:     // 단위 행렬로 리셋
        break;

    case Qt::Key_4:
        break;

    case Qt::Key_5:
        break;

    case Qt::Key_6:
        break;

    case Qt::Key_7:
        break;

    case Qt::Key_8:
        break;

    case Qt::Key_9:
        break;

    case Qt::Key_0:
        break;

    };

    update();

}
