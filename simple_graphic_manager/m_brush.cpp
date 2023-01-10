#include "m_brush.h"

m_brush::m_brush()
{
   //style=1;
}


void  m_brush::SetStyle(int new_s)
{
    style=new_s;
}

int m_brush::GetStyle(void)
{
    return style;
}
