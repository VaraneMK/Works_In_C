#include "pixel.h"

pixel::pixel()
{

}

void pixel::draw(QImage *im)
{
    QPainter painter(im);
    QColor color;

    color.setRgb(red,green,blue,alpha);

    QPen pen;
    pen.setWidth(GetW());//установка ширину
    pen.setColor(color);//установка цвета
    painter.setPen(pen);//установка карандаша
    painter.drawPoint(x,y);//рисуем точку
}
