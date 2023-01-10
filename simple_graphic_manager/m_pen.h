#ifndef M_PEN_H
#define M_PEN_H
#include "color.h"


class m_pen: public color
{
public:
    m_pen();
    void SetWidth(int new_w);//установка ширины
    void SetStyle(int new_s);//установка стиля

    int GetWidth(void);//вывод ширины
    int GetStyle(void);//вывод стиля
protected:
    int width;
    int style;
};

#endif // M_PEN_H
