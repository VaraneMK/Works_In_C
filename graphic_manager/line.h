#ifndef LINE_H
#define LINE_H
#include "tochka.h"
#include <QImage>
#include <QPainter>
#include "my_pen.h"
#include "primitive.h"


class line: public Primitive,public my_pen
{
public:
    line();
    void draw(QImage *im) override;//рисование

    tochka start;
    tochka end;
};

#endif // LINE_H
