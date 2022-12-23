#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    Action = 0;
     xAngle = yAngle = zAngle = 0.0;

    setWindowTitle("OpenGL Modelign");
    resize(600, 600);
}

Widget::~Widget()
{
}

void Widget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void Widget::paintGL()
{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glutWireTeapot(0.2);

//    glFlush();

        glClear(GL_COLOR_BUFFER_BIT);

        glPushMatrix();
#if 0
//        glTranslatef(0.0, 0.0, 0.0);
        glRotatef(xAngle, 1.0, 1.0, 0.0);
        glScalef(2.0, 1.0, 1.0);
        glutWireTeapot(0.2);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.4, 0.0, 0.0);
        glRotatef(yAngle, 0.0, 1.0, 1.0);
        glScalef(1.0, 2.0, 1.0);
        glutWireTeapot(0.2);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0, 0.4, 0.0);
        glRotatef(zAngle, 1.0, 0.0, 1.0);
        glScalef(1.0, 1.0, 2.0);
        glutWireTeapot(0.2);
        glPopMatrix();
#else

        glPushMatrix();
            glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_TRIANGLES);
            glVertex3f(0.7, 0.8, 0.0);
            glVertex3f(0.0, 0.6, 0.0);
            glVertex3f(0.2, 0.2, 0.0);
            glScalef(1.0, 1.0, 1.0);
            glEnd();
        glPopMatrix();

        glPushMatrix();
            glRotatef(xAngle, 1.0, 1.0, 0.0);
            glColor3f(1.0, 1.0, 0.0);
            glBegin(GL_TRIANGLES);
            glVertex3f(0.7, 0.8, 1.0);
            glVertex3f(0.0, 0.6, 1.0);
            glVertex3f(0.2, 0.2, 1.0);
            glEnd();
        glPopMatrix();

#endif
        glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();                               //여기서 무언가 한다 ㅡ,
    glColor3f(1.0, 1.0, 1.0);

    switch(event->key()) {
    case Qt::Key_1:
        xAngle += 3;
        break;
    case Qt::Key_2:
        yAngle++;
        break;
    case Qt::Key_3:
        zAngle++;
        break;
    case Qt::Key_4:
        xAngle--;
        break;
    case Qt::Key_5:
        yAngle--;
        break;
    case Qt::Key_6:
        zAngle--;
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

//void Widget::paintGL()
//{
//    glClear(GL_COLOR_BUFFER_BIT);

//    glutWireTeapot(0.2);

//    glTranslatef(0.6, 0.0, 0.0);
//    glutWireTeapot(0.2);

//    glFlush();
//}

//void Widget::paintGL()
//{
//    glClear(GL_COLOR_BUFFER_BIT);

//    glPushMatrix();
//    glutWireTeapot(0.2);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(0.6, 0.0, 0.0);
//    glutWireTeapot(0.2);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(0.0, 0.6, 0.0);
//    glutWireTeapot(0.2);
//    glPopMatrix();

//    glFlush();
//}
