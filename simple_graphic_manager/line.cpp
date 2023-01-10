#include "line.h"

line::line()
{

}

void line::draw(QImage &im)
{
    QPainter painter(&im);
    QColor color;
    color.setRgb(red,green,blue,alpha);
    QPen pen;
    int width,style;
    //========================================================================================================================
    width=GetWidth();
    style=GetStyle();
    //========================================================================================================================
    pen.setStyle(Qt::PenStyle(style));
    pen.setWidth(width);
    pen.setColor(color);
    painter.setPen(pen);
    //========================================================================================================================
    int x1,y1,x2,y2;
    x1=start.GetX();
    y1=start.GetY();
    x2=end.GetX();
    y2=end.GetY();

    painter.drawLine(x1,y1,x2,y2);//рисуем линию

    // painter.drawEllipse(x-5,y-5,10,10);

}
