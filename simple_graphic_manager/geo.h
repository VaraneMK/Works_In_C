#ifndef GEO_H
#define GEO_H
#include "color.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>
#include <vector>
#include "m_pen.h"
#include "m_brush.h"


class geo:public tochka,public color
{
public:
    geo();

    void draw(QImage &im, std::vector<tochka> points);//рисование
    m_pen gran;
    m_brush zal;
};

#endif // GEO_H
