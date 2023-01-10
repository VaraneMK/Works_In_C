#include "polyline.h"

polyline::polyline()//конструктор
{
    _pen = new my_pen();
    _brush = new my_brush();
    _points = new std::vector<tochka>(3);
}


void polyline::draw(QImage *im)
{
    QPainter painter(im);
    QColor color;
    int red,green,blue,alpha;
    //========================================================================================================================
    gran.GetColor(red,green,blue,alpha);//считываем цвет
    alpha=255;
    color.setRgb(red,green,blue,alpha);//устанавливаем цвет
    QPen pen;
    pen.setColor(color);
    pen.setWidth(gran.GetW());//устанавливаем ширину
    pen.setStyle(Qt::PenStyle(gran.GetStyle()));
    painter.setPen(pen);
    //========================================================================================================================
    QPoint *polylines=new QPoint[_points->size()];
    for (int i=0;i < _points->size();i++)//переносим значения всех точек
    {
        polylines[i].setX((*_points)[i].GetX());//X
        polylines[i].setY((*_points)[i].GetY());//Y
    }
    painter.drawPolyline(polylines,_points->size());//рисуем ломанную линию
    delete []polylines;
}
