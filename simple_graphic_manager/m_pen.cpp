#include "m_pen.h"

m_pen::m_pen()
{
    width=1;
    //style=1;
}


void m_pen::SetWidth(int new_w)
{
    if(new_w<0)
        width=0;
    else if(new_w>25)
        width=25;
    else
        width=new_w;
}
void  m_pen::SetStyle(int new_s)
{
    style=new_s;
}

int m_pen::GetWidth(void)
{
    return width;
}
int m_pen::GetStyle(void)
{
    return style;
}
