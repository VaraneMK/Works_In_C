#ifndef RECT_H
#define RECT_H
#include "my_pen.h"
#include "my_brush.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>
#include "primitive.h"

class rect:public Primitive
{
public:
    rect();
    void SetWeight(int new_w);//установка ширины
    void SetHeight(int new_h);//установка высоты
    int GetWeight(void);//вывод ширины
    int GetHeight(void);//вывод высоты

    void draw(QImage *im) override;//рисование
    my_pen gran;
    my_brush zal;
    tochka point;
protected:
    int value_weight;
    int value_height;

};

#endif // RECT_H
