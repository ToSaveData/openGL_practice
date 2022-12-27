#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("OpenGL Pixelmap");
    resize(600,600);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 0.0);

}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#if 1
    GLubyte data[32*32*3];

    for(int y=0;y<32;y++){
        for(int x=0;x<32;x++){
        data[32*3*y+x*3+0] = 0xff;
        data[32*3*y+x*3+1] = 0xff;
        data[32*3*y+x*3+2] = 0x00;
        }
    }

    glClear(GL_COLOR_BUFFER_BIT);

    glRasterPos2f(0.0,0.0);
    glDrawPixels(32,32,GL_RGB, GL_UNSIGNED_BYTE, data);
    glFlush();
#else
    GLubyte *data;

    QImage *image = new QImage("mongus24.bmp");
    data = image->bits();


    if(data != NULL){
        glRasterPos2f(-0.5, -0.5);
        glDrawPixels(image->width(), image->height(),
                     GL_BGRA, GL_UNSIGNED_BYTE, data);
    }
    glFlush();
#endif
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}
