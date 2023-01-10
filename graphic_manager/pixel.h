#ifndef PIXEL_H
#define PIXEL_H
#include "my_color.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>
#include "primitive.h"
#include "my_pen.h"


class pixel:public Primitive,public tochka,public my_pen
{
public:
    pixel();

   void draw(QImage *im) override;//рисование
};

#endif // PIXEL_H
