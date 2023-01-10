#include "my_widget.h"

My_widget::My_widget(QWidget *parent) :
    QWidget(parent)
{
    im=QImage(675,700,QImage::Format_ARGB32_Premultiplied);
}



void My_widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

//    QBrush brush;
//    brush.setColor(Qt::blue);
//    brush.setStyle(Qt::SolidPattern);

//    painter.setBrush(brush);

//    QPen pen;//создали карандаш
//    pen.setColor(Qt::red);//цвето
//    pen.setWidth(3);//толщина

//    painter.setPen(pen);//вручили карандаш художнику

//    painter.drawEllipse(30,30,50,50);

    painter.drawImage(0,0,im);
}
