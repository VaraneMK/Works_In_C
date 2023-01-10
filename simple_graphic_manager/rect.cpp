#include "rect.h"

rect::rect()
{

}
void rect::draw(QImage &im)
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
    //========================================================================================================================
    int x,y,weight,height;
    x=point.GetX();
    y=point.GetY();
    weight=GetWeight();
    height=GetHeight();

    painter.drawRect(x,y,weight,height);//рисуем прямоугольник

}


void rect::SetWeight(int new_w)
{
    value_weight=new_w;
}

void rect::SetHeight(int new_h)
{
    value_height=new_h;
}

int rect::GetHeight(void)
{
    return(value_height);
}

int rect::GetWeight(void)
{
    return(value_weight);
}
