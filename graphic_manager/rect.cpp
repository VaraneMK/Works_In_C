#include "rect.h"

rect::rect()
{
 value_height=0;
 value_weight=0;
}
void rect::draw(QImage *im)
{
    QPainter painter(im);
    QColor color;
    int red,green,blue,alpha;
    //========================================================================================================================
    gran.GetColor(red,green,blue,alpha);//считываем цвет
    alpha=255;
    color.setRgb(red,green,blue,alpha);//установка цвета
    QPen pen;
    pen.setColor(color);
    pen.setWidth(gran.GetW());//установка ширины
    pen.setStyle(Qt::PenStyle(gran.GetStyle()));//установка стиля
    painter.setPen(pen);
    //========================================================================================================================
    zal.GetColor(red,green,blue,alpha);
    alpha=255;
    color.setRgb(red,green,blue,alpha);
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::BrushStyle(zal.GetStyle()));
    painter.setBrush(brush);
    //========================================================================================================================
    int x,y,weight,height;
    x=point.GetX();
    y=point.GetY();
    weight=GetWeight();
    height=GetHeight();

    painter.drawRect(x,y,weight,height);//рисуем прямоугольник

}


void rect::SetWeight(int new_w)//установка ширины
{
    value_weight=new_w;
}

void rect::SetHeight(int new_h)//установка высоты
{
    value_height=new_h;
}

int rect::GetHeight(void)//возвращение значения высоты
{
    return(value_height);
}

int rect::GetWeight(void)//возвращения значения ширины
{
    return(value_weight);
}
