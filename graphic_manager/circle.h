#ifndef CIRCLE_H
#define CIRCLE_H
#include "tochka.h"
#include "my_pen.h"
#include "my_brush.h"
#include <QImage>
#include <QPainter>
#include "primitive.h"

class circle:public Primitive
{
public:
    circle();
    void SetRadius(int new_r);//установка радиуса
    int GetRadius(void);//вывод радиуса

    void draw(QImage *im) override;//рисование
    tochka center;
    my_pen gran;
    my_brush zal;
protected:
    int radius;
};

#endif // CIRCLE_H
