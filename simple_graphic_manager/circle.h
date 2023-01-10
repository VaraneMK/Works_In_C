#ifndef CIRCLE_H
#define CIRCLE_H
#include "tochka.h"
#include "m_pen.h"
#include "m_brush.h"
#include <QImage>
#include <QPainter>

class circle
{
public:
    circle();
    void SetRadius(int new_r);//установка радиуса
    int GetRadius(void);//вывод радиуса

    void draw(QImage &im);//рисование
    tochka center;
    m_pen gran;
    m_brush zal;
protected:
    int radius;
};

#endif // CIRCLE_H
