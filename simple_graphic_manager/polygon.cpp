#include "polygon.h"
#include "dialog.h"


polygon::polygon()
{

}
/*polygon::polygon(int count)
{
    pol=new tochka[count];
}
*/
void polygon::draw(QImage &im, std::vector<tochka> points)
{
    QPainter painter(&im);
    QColor color;

    int red,green,blue,alpha;
    //========================================================================================================================
    gran.GetRGBA(red,green,blue,alpha);
    alpha=255;
    color.setRgb(red,green,blue,alpha);
    QPen pen;
    pen.setWidth(5);
    pen.setColor(color);
    pen.setWidth(gran.GetWidth());
    pen.setStyle(Qt::PenStyle(gran.GetStyle()));
    painter.setPen(pen);
    //========================================================================================================================
    zal.GetRGBA(red,green,blue,alpha);
    alpha=255;
    color.setRgb(red,green,blue,alpha);
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::BrushStyle(zal.GetStyle()));
    painter.setBrush(brush);


    QPoint polygon[points.size()];
    for (int i=0;i < points.size();i++)
    {
        polygon[i].setX(points[i].GetX());
        polygon[i].setY(points[i].GetY());
    }
    painter.drawPolygon(polygon,points.size(),Qt::OddEvenFill);//рисуем многоугольник


}

/*
void polygon::inPolX(int di,int new_x)
{
    this->pol[di].SetX(new_x);
}

void polygon::inPolY(int di,int new_y)
{
    this->pol[di].SetY(new_y);
}

void polygon::setCount(int newCount)
{
    count=newCount;
}
int polygon::getCount()
{
    return count;
}
*/
