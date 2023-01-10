#ifndef LINE_H
#define LINE_H
#include "tochka.h"
#include <QImage>
#include <QPainter>
#include "m_pen.h"


class line: public m_pen
{
public:
    line();
    void draw(QImage &im);//рисование

    tochka start;
    tochka end;
};

#endif // LINE_H
