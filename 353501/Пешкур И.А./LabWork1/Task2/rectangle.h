#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h".h"


class rectangle : public Figure
{
public:

    rectangle();
    float Length=100;
    float Width=50;
    float Area() override;
    float Perimeter() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // RECTANGLE_H
