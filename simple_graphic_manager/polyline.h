#ifndef POLYLINE_H
#define POLYLINE_H
#include "color.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>
#include <vector>
#include "m_pen.h"
#include "m_brush.h"


class polyline:public color,public tochka
{
public:
    polyline();

    void draw(QImage &im, std::vector<tochka> points);//рисование
    m_pen gran;
    m_brush zal;
};

#endif // POLYLINE_H
