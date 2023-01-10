#ifndef ARC_H
#define ARC_H
#include "my_color.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>
#include "my_pen.h"
#include "primitive.h"

class Arc: public Primitive, public my_pen
{
public:
    Arc();

    void SetStartAngle(int new_st);//установка начального угла
    int GetStartAngle(void);//вывод начального угла
    void SetSpanAngle(int new_sp);//установка угла охвата
    int GetSpanAngle(void);//вывод угла охвата
    void SetRadius1(int new_w);//установка радиуса1
    void SetRadius2(int new_h);//установка радиуса2
    int GetRadius1(void);//вывод радиуса1
    int GetRadius2(void);//вывод радиуса2


    tochka begin;
    void draw(QImage *im) override;//рисование

protected:
    int value_r1;
    int value_r2;
    int value_st;
    int value_sp;

};

#endif // ARC_H
