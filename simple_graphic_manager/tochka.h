#ifndef TOCHKA_H
#define TOCHKA_H


class tochka
{
public:
    tochka();
    void SetX(int new_x);//установка координаты X
    void SetY(int new_y);//установка координаты Y
    void SetXY(int new_x,int new_y);//установка координат XY

    int GetX(void);//вывод координаты X
    int GetY(void);//вывод координаты Y
    void SetXY(int &zn_x,int &zn_y);//Установка координат XY
    int getXY(int &new_x, int &new_y);//вывод координат XY


protected:
    int x;
    int y;
};

#endif // TOCHKA_H
