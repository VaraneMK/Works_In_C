#include "geo.h"

geo::geo()
{

}


void geo::draw(QImage &im, std::vector<tochka> points)
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
    QPainterPath path;

    int cx, cy,old_x = 0;
//    points[0].getXY(cx, cy);
//    path.moveTo(cx, 441-cy);
//    for (int i = 1; i < points.size(); i++)
//    {
//        old_x=old_x+cx;
//        points[i].getXY(cx, cy);
//        path.lineTo(cx+old_x, 441-cy);
//    }

    QPoint polylines[points.size()];
    for (int i=0;i < points.size();i++)
    {
        polylines[i].setX(points[i].GetX());
        polylines[i].setY(300-points[i].GetY());
        old_x+=points[i].GetX();
    }
    painter.drawPolyline(polylines,points.size());//рисуем ломанную линию
    pen.setColor(Qt::black);
    painter.setPen(pen);
    for (int i=0;i < points.size();i++)
    {
         painter.drawText(polylines[i],"("+QString::number(points[i].GetX())+ ";"+QString::number(points[i].GetY())+")");
    }



   // painter.drawPath(path);

}
