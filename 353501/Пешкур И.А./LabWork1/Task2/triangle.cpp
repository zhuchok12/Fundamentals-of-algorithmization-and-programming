#include "triangle.h"

Triangle::Triangle(){}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon polygon;
    polygon << QPoint( -40 , 20 * sqrt( 3 ) ) << QPoint( 0 , -20 * sqrt( 3 ) ) << QPoint( 40 , 20 * sqrt( 3 ) );
    painter->drawPolygon( polygon );

}

float Triangle :: Area()
{
    return this -> getScale() * this -> getScale() * ( Size * Size * sqrt( 3 ) ) / 4;
}

float Triangle :: Perimeter()
{
    return 3 * Size * this->getScale();
}
