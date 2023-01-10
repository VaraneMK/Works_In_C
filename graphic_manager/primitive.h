#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include "my_brush.h"
#include "my_pen.h"
#include "tochka.h"
#include <vector>
#include <QImage>

enum PrType  {
    Pixel,
    Line,
    Rectangle,
    Ellipse,
    Circle,
    Arc,
    Curve,
    Polygon
};

class Primitive
{
public:
    void setType(PrType type){_type = type;}
    void setPen(my_pen* pen){_pen = pen;}
    void setBrush(my_brush* brush){_brush = brush;}
    void setPoints(std::vector<tochka>* points){_points = points;}

    PrType getType(){return _type;}
    my_pen* getPen(){return _pen;}
    my_brush* getBrush(){return _brush;}
    std::vector<tochka>* getPoints(){return _points;}

    virtual void draw(QImage* image) = 0;
protected:
    my_pen * _pen{nullptr};
    PrType _type;
    my_brush * _brush{nullptr};
    std::vector<tochka> * _points{nullptr};
};

#endif // PRIMITIVE_H
