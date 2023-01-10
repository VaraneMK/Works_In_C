#ifndef RECT_H
#define RECT_H
#include "m_pen.h"
#include "m_brush.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>

class rect
{
public:
    rect();
    void SetWeight(int new_w);//установка ширины
    void SetHeight(int new_h);//установка высоты
    int GetWeight(void);//вывод ширины
    int GetHeight(void);//вывод высоты

    void draw(QImage &im);//рисование
    m_pen gran;
    m_brush zal;

    tochka point;
protected:
    int value_weight;
    int value_height;

};

#endif // RECT_H
