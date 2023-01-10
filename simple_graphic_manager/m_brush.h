#ifndef M_BRUSH_H
#define M_BRUSH_H
#include "color.h"


class m_brush: public color
{
public:
    m_brush();
    void SetStyle(int new_s);//установка стиля

    int GetStyle(void);//вывод стиля
protected:
    int style;
};

#endif // M_BRUSH_H
