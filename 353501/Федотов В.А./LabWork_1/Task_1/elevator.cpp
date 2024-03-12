#include "elevator.h"

Elevator::Elevator() : Rectangle() {
    floor = 1;

    connect(this, &Rectangle::floorChanged, this, &Rectangle::handleFloorChange);

}

void Elevator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    QPen pen(Qt::black);
    pen.setWidth(4);

    painter->setPen(pen);
    painter->drawRect(rect);
}
