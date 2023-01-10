#include "ellipse.h"

ellipse::ellipse()
{

}



void ellipse::draw(QImage *im)
{
    QPainter painter(im);
    QColor color;
    int red,green,blue,alpha;
    //========================================================================================================================установка карандаша
    gran.GetColor(red,green,blue,alpha);//считываем цвет
    alpha=255;
    color.setRgb(red,green,blue,alpha);//устанавливаем цвет
    QPen pen;
    pen.setWidth(5);
    pen.setColor(color);
    pen.setStyle(Qt::PenStyle(gran.GetStyle()));
    pen.setWidth(gran.GetW());//устанавливаем ширину
    painter.setPen(pen);
    //========================================================================================================================установка кисти
    zal.GetColor(red,green,blue,alpha);
    alpha=255;
    color.setRgb(red,green,blue,alpha);
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::BrushStyle(zal.GetStyle()));
    painter.setBrush(brush);
    //========================================================================================================================
    int x,y,radius1,radius2;
    x=center.GetX();
    y=center.GetY();
    QPoint center;
    center.setX(x);
    center.setY(y);
    radius1=GetRadius1();
    radius2=GetRadius2();
    painter.drawEllipse(center,radius1,radius2);//рисуем эллипс

}

void ellipse::SetRadius1(int new_r)//установка радиуса1
{
    radius1=new_r;
}
int ellipse::GetRadius1(void)//возвращение значениия радиуса1
{
    return(radius1);
}

void ellipse::SetRadius2(int new_r)//установка радиуса1
{
    radius2=new_r;
}
int ellipse::GetRadius2(void)//возвращение значения радиуса2
{
    return(radius2);
}
