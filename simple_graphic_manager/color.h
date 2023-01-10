#ifndef COLOR_H
#define COLOR_H


class color
{
public:
    color();
    void SetRGBA(int r,int g,int b,int a);//установка цвета RGBA
    void GetRGBA(int &r,int &g,int &b,int&a);//вывод цвета RGBA

protected:
    int red;
    int green;
    int blue;
    int alpha;//прозрачность
};

#endif // COLOR_H
