#ifndef POLYGON_H
#define POLYGON_H
#include "color.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>
#include <vector>
#include "m_pen.h"
#include "m_brush.h"

class polygon:public color,public tochka
{   
public:

    polygon();
    void draw(QImage &im, std::vector<tochka> points);//рисование
    m_pen gran;
    m_brush zal;
};

#endif // POLYGON_H
