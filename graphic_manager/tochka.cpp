#include "tochka.h"

tochka::tochka()
{
    x=0;
    y=0;
}


void tochka::SetX(int new_x)//установка значения X
{
    if(new_x<0)
        x=0;
    else if(new_x>1021)
        x=1021;
    else
    x=new_x;
}
void  tochka::SetY(int new_y)//установка значения Y
{
    if(new_y<0)
        y=0;
    else if(new_y>441)
        y=441;
    else
    y=new_y;
}
void tochka::SetXY(int new_x,int new_y)//установка значения XY
{
    x=new_x;
    y=new_y;
}

int tochka::GetX()//возвращаем значение X
{
    return(x);
}
int tochka::GetY()//возвращаем значение Y
{
    return(y);
}
void tochka::SetXY(int &zn_x, int &zn_y)//установка значения XY
{
    zn_x=x;
    zn_y=y;
}

int tochka::getXY(int &new_x, int &new_y)
{
    new_x = x;
    new_y = y;
}
