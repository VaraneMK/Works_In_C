#include "polygon.h"
#include "dialog.h"


polygon::polygon()//конструктор
{
    _pen = new my_pen();
    _brush = new my_brush();
    _points = new std::vector<tochka>(3);
}
/*polygon::polygon(int count)
{
    pol=new tochka[count];
}
*/
void polygon::draw(QImage *im)//функция рисования
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
    pen.setWidth(gran.GetW());//устнавливаем ширину
    pen.setStyle(Qt::PenStyle(gran.GetStyle()));
    painter.setPen(pen);
    //========================================================================================================================
    zal.GetColor(red,green,blue,alpha);
    alpha=255;
    color.setRgb(red,green,blue,alpha);
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::BrushStyle(zal.GetStyle()));
    painter.setBrush(brush);


    QPoint *polygon=new QPoint[_points->size()];
    for (int i=0;i < _points->size();i++)//переносим значения всех точек
    {
        polygon[i].setX((*_points)[i].GetX());//X
        polygon[i].setY((*_points)[i].GetY());//Y
    }
    painter.drawPolygon(polygon,_points->size(),Qt::OddEvenFill);//рисуем многоугольник

    delete[] polygon;
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
