#include "my_brush.h"

my_brush::my_brush()//конструктор
{
    my_style=0;
}


void my_brush::SetStyle(int st)//установка стиля
{
    my_style=st;
}

int my_brush::GetStyle()//возвращение значения стиля
{
    return(my_style);
}
