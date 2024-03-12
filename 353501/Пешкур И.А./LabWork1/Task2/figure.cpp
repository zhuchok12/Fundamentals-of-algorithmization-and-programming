#include "figure.h"

Figure::Figure() {}

// 300 na 250

void Figure :: paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *){}


QRectF Figure :: boundingRect() const
{

    return QRectF( -1000 , -1000 , 1500 , 1500 );

}

float Figure :: getScale()
{

    return scale;

}

QPoint Figure :: getCenter()
{

    return QPoint(this->x(), this->y());

}

void Figure :: moveX( int newX )
{

    this -> setX( newX );

}

void Figure :: moveY( int newY )
{

    this -> setY( newY );

}

void Figure :: rotateFigure( int newAngle )
{

    this -> setRotation( newAngle );

}

float Figure :: Area()
{

    return 0;

}

float Figure :: Perimeter()
{

    return 0;

}
