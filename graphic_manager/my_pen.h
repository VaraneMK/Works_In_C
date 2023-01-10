#ifndef MY_PEN_H
#define MY_PEN_H
#include "my_color.h"
#define KOL_STYLE 5

class my_pen : public my_color
{
public:
    my_pen();

protected:
    int my_style;
    int w;

public:
    bool SetStyle (int st);
    int GetStyle (void);
    void SetW(int w);
    int GetW (void);
};

#endif // MY_PEN_H
