#ifndef MY_COLOR_H
#define MY_COLOR_H

class my_color
{
public:
    my_color();
protected:
    int red;
    int green;
    int blue;
    int alpha;

public:
    bool SetColor( int r,int g, int b, int al);
    void GetColor(int &r, int &g, int &b,int &al);
};


#endif // MY_COLOR_H
