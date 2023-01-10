#ifndef MY_BRUSH_H
#define MY_BRUSH_H
#include "my_color.h"


class my_brush:public my_color
{
public:
    my_brush();

protected:
    int my_style;

public:
    void SetStyle (int st);//установка стиля
    int GetStyle (void);
};

#endif // MY_BRUSH_H
