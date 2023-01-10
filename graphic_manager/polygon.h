#ifndef POLYGON_H
#define POLYGON_H
#include "my_color.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>
#include <vector>
#include "my_pen.h"
#include "my_brush.h"
#include "primitive.h"

class polygon:public Primitive,public my_color,public tochka
{   
public:

    polygon();
    void draw(QImage *im) override;//рисование
    my_pen gran;
    my_brush zal;
    std::vector<tochka> points;
};

#endif // POLYGON_H
