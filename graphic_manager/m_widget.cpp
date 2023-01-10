#include "m_widget.h"

m_widget::m_widget(QWidget *parent) : QWidget(parent)
{
    im_created=false;

}

void m_widget::paintEvent(QPaintEvent *)
{
    if(im_created)
    {
        QPainter painter(this);
        painter.drawImage(0,0,im);//рисуем изображение
    }
}

void m_widget::create_im(int size_x,int size_y)
{
    im=QImage(size_x,size_y,QImage::Format_ARGB32_Premultiplied);//создаем изображение
    im_created=true;
}
