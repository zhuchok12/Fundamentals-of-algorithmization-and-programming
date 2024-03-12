#include "rectangle.h"

Rectangle::Rectangle() : QGraphicsObject()
{
    floor = 1;

    connect(this, &Rectangle::floorChanged, this, &Rectangle::handleFloorChange);
}

QRectF Rectangle::boundingRect() const
{
    return QRectF(0,0, 100, 250);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush(Qt::gray);

    painter->fillRect(rect, brush);
}

void Rectangle::setFloor(int floor)
{
    emit floorChanged(floor);
    this->floor = floor;
}

void Rectangle::handleFloorChange(int newFloor)
{
    qreal newYCoordinate = - 250 * (newFloor - 1);
    setPos(pos().x(), newYCoordinate);
    update();
}
