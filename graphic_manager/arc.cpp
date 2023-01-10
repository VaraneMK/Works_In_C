#include "arc.h"

Arc::Arc()//конструктор
{
 value_r1=0;
 value_r2=0;
 value_st=0;
 value_sp=0;
}


void Arc::draw(QImage *im)
{
    QPainter painter(im);
    QColor color;
    color.setRgb(red,green,blue,alpha);
    //========================================================================================================================установка карандаша
    QPen pen;
    pen.setColor(color);//устанавливаем цвет
    int style=GetStyle();//считываем стиль
    int width=GetW();//считываем ширину
    pen.setWidth(width);//устанавливаем ширину
    pen.setStyle(Qt::PenStyle(style));
    painter.setPen(pen);//устнавливай карандаш
    //========================================================================================================================установка кисти
    int x,y,radius1,radius2,startAngle,spanAngle;
    x=begin.GetX();
    y=begin.GetY();
    radius1=GetRadius1();
    radius2=GetRadius2();
    startAngle=GetStartAngle()*16;
    spanAngle=GetSpanAngle()*16;
    painter.drawArc(x-radius1,y-radius2,2*radius1,2*radius2,startAngle,spanAngle);//рисуем дугу


}

void Arc::SetRadius1(int new_w)//установка радиуса1
{
    value_r1=new_w;
}

void Arc::SetRadius2(int new_h)//установка радиуса2
{
    value_r2=new_h;
}

int Arc::GetRadius2(void)//возвращение значения радиуса2
{
    return(value_r2);
}

int Arc::GetRadius1(void)//возвращение значения радиуса1
{
    return(value_r1);
}

void Arc::SetStartAngle(int new_st)//установка нач.угла
{
    value_st=new_st;
}
int Arc::GetStartAngle(void)//возвращение значения нач.угла
{
    return(value_st);
}
void Arc::SetSpanAngle(int new_sp)//установка угла охвата
{
    value_sp=new_sp;
}
int Arc::GetSpanAngle(void)//возвращение значения угла охвата
{
    return(value_sp);
}
