#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "my_pen.h"
#include "my_brush.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>
#include "primitive.h"

class ellipse:public Primitive
{
public:
    ellipse();

    void SetRadius1(int new_r);//установка радиуса1
    int GetRadius1(void);//вывод радиуса1
    void SetRadius2(int new_r);//установка радиуса2
    int GetRadius2(void);//вывод радиуса2

    void draw(QImage *im) override;//рисование
    my_pen gran;
    my_brush zal;
    tochka center;

protected:
    int radius1;
    int radius2;
};

#endif // ELLIPSE_H
