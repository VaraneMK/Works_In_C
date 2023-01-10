#include "circle.h"

circle::circle()
{

}

void circle::draw(QImage *im)
{
    QPainter painter(im);
    QColor color;
    int red,green,blue,alpha;
    //========================================================================================================================
    gran.GetColor(red,green,blue,alpha);//считываем цвет
    alpha=255;
    color.setRgb(red,green,blue,alpha);//устанавливаем цвет
    QPen pen;
    pen.setWidth(5);
    pen.setColor(color);
    pen.setStyle(Qt::PenStyle(gran.GetStyle()));
    pen.setWidth(gran.GetW());//устанавливаем ширину
    painter.setPen(pen);//установка карандаша
    //========================================================================================================================установка карандаша
    zal.GetColor(red,green,blue,alpha);
    alpha=255;
    color.setRgb(red,green,blue,alpha);
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::BrushStyle(zal.GetStyle()));
    painter.setBrush(brush);
    //========================================================================================================================установка кисти
    int x,y,radius;
    x=center.GetX();
    y=center.GetY();
    QPoint center;
    center.setX(x);
    center.setY(y);
    radius=GetRadius();
    painter.drawEllipse(center,radius,radius);//рисуем круг

}

void circle::SetRadius(int new_r)//установка радиуса
{
    radius=new_r;
}
int circle::GetRadius(void)//возвращение значения
{
    return(radius);
}
