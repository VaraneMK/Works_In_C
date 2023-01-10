#include "color.h"

color::color()
{
red=0;
green=0;
blue=0;
alpha=0;
}

void color::SetRGBA(int r,int g,int b,int a)
{
    red=r;
    green=g;
    blue=b;
    alpha=a;
}
void color::GetRGBA(int &r,int &g,int &b,int&a)
{
    r=red;
    g=green;
    b=blue;
    a=alpha;
}

