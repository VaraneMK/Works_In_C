#ifndef PIXEL_H
#define PIXEL_H
#include "color.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>


class pixel:public color,public tochka
{
public:
    pixel();

   void draw(QImage &im);//рисование
};

#endif // PIXEL_H
