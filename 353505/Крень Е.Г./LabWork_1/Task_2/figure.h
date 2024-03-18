#ifndef FIGURE_H
#define FIGURE_H

#include "ifigure.h"
#include <QDebug>

namespace figures {

class circle:public IFigure
{
public:
    circle(QVector2D coordinates,int radius, float valueSectors);
    ~circle() = default;
protected:
    int valueSectors;
};

class square:public circle
{
public:
    square(QVector2D coordinates, int length);
    ~square() = default;
};

class triangle:public circle
{
public:
    triangle(QVector2D coordinates, int length);
    ~triangle() = default;
};

class hexagon:public circle
{
public:
    hexagon(QVector2D coordinates, int length);
    ~hexagon() = default;
};

class elipse: public IFigure
{
public:
    elipse(QVector2D coordinates, int bigAxis, int smallAxis);
    ~elipse() = default;
};

class rhomb: public IFigure
{
public:
    rhomb(QVector2D coordinates, int length, int width);
    ~rhomb() = default;
};

class star: public IFigure
{
public:
    star(QVector2D coordinates, int length, int width);
    ~star() = default;
};

class rectangle:public IFigure
{
public:
    rectangle(QVector2D coordinates, int length, int width);
    ~rectangle() = default;
protected:
};

class trapezoid:public IFigure
{
public:
    trapezoid(QVector2D coordinates, float length1, float length2, float height);
    ~trapezoid() = default;
protected:
};
}
#endif // FIGURE_H
