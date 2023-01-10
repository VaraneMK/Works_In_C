#include "polyline.h"

polyline::polyline()
{

}


void polyline::draw(QImage &im, std::vector<tochka> points)
{
    QPainter painter(&im);
    QColor color;
    int red,green,blue,alpha;
    //========================================================================================================================
    gran.GetRGBA(red,green,blue,alpha);
    alpha=255;
    color.setRgb(red,green,blue,alpha);
    QPen pen;
    pen.setColor(color);
    pen.setWidth(gran.GetWidth());
    pen.setStyle(Qt::PenStyle(gran.GetStyle()));
    painter.setPen(pen);
    //========================================================================================================================

    QPoint polylines[points.size()];
    for (int i=0;i < points.size();i++)
    {
        polylines[i].setX(points[i].GetX());
        polylines[i].setY(points[i].GetY());
    }
    painter.drawPolyline(polylines,points.size());//рисуем ломанную линию
}
