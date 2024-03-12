#include "rectangle.h"

rectangle::rectangle(){}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawRect( -Length / 2,-Width / 2, Length , Width );
}

float rectangle :: Area()
{
    return this->getScale() * this->getScale() * Length * Width;
}

float rectangle :: Perimeter()
{
    return (2 * getScale() * Length + 2 * getScale() * Width);
}
