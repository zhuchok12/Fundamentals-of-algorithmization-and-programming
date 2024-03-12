#include "wheel.h"

Wheel :: Wheel(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) : Circle( x , y , width , height , parent )
{}

void Wheel :: paint( QPainter *painter , const QStyleOptionGraphicsItem *option , QWidget *widget ){


    painter -> drawRect( 210 , 240 , 80 , 20 );
    painter -> drawRect( 240 , 210 , 20 , 80 );

}

void Wheel :: rotate( int angle ){

    setTransformOriginPoint( boundingRect().center());
    setRotation( (qreal)angle );

}
