#include "my_color.h"

my_color::my_color()//конструктор
{
   alpha=255;
   red=0;
   green=0;
   blue=0;

}

bool my_color::SetColor( int r, int g, int b,int al)//Установка цвет
{
    if ((al<0)||(al>255)||(r<0)||(r>255)||(g<0)||(g>255)||(b<0)||(b>255))
        return (false);
    alpha=al;
    red=r;
    green=g;
    blue=b;
    return (true);
}

void my_color::GetColor(int &r, int &g, int &b, int &al)//возвращение значения цвета
{
    al=alpha;
    r=red;
    g=green;
    b=blue;
}
