#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <cmath>

class Figure :  public QGraphicsItem
{
public:

    QPoint center;
    QVector < QPoint > points;
    Figure();
    float getScale();
    QPoint getCenter();
    virtual float Area();
    virtual float Perimeter();
    float scale = 1.0;
    void moveX( int newX );
    void moveY( int newY );
    void rotateFigure( int newAngle );

protected:

    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);


};

#endif // FIGURE_H
