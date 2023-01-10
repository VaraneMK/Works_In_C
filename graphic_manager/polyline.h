#ifndef POLYLINE_H
#define POLYLINE_H
#include "my_color.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>
#include <vector>
#include "my_pen.h"
#include "my_brush.h"
#include "primitive.h"


class polyline:public Primitive,public my_color,public tochka
{
public:
    polyline();

    void draw(QImage *im) override;//рисование
    my_pen gran;
    std::vector<tochka> points;
};

#endif // POLYLINE_H
