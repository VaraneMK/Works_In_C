#include "arc.h"

Arc::Arc()
{

}


void Arc::draw(QImage &im)
{
    QPainter painter(&im);
    QColor color;
    color.setRgb(red,green,blue,alpha);
    //========================================================================================================================
    QPen pen;
    pen.setColor(color);
    int style=GetStyle();
    int width=GetWidth();
    pen.setWidth(width);
    pen.setStyle(Qt::PenStyle(style));
    painter.setPen(pen);
    //========================================================================================================================
    int x,y,radius1,radius2,startAngle,spanAngle;
    x=begin.GetX();
    y=begin.GetY();
    radius1=GetRadius1();
    radius2=GetRadius2();
    startAngle=GetStartAngle()*16;
    spanAngle=GetSpanAngle()*16;
    painter.drawArc(x-radius1,y-radius2,2*radius1,2*radius2,startAngle,spanAngle);//рисуем дугу


}

void Arc::SetRadius1(int new_w)
{
    value_r1=new_w;
}

void Arc::SetRadius2(int new_h)
{
    value_r2=new_h;
}

int Arc::GetRadius2(void)
{
    return(value_r2);
}

int Arc::GetRadius1(void)
{
    return(value_r1);
}

void Arc::SetStartAngle(int new_st)
{
    value_st=new_st;
}
int Arc::GetStartAngle(void)
{
    return(value_st);
}
void Arc::SetSpanAngle(int new_sp)
{
    value_sp=new_sp;
}
int Arc::GetSpanAngle(void)
{
    return(value_sp);
}
