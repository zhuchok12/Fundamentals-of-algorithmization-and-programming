#include "people.h"

People::People(int floor, const QColor& color, const QString name) : QGraphicsObject(), m_floor(floor), m_color(color), m_name(name)
{
    inside = false;
    m_floor = floor;
    connect(this, &People::entered, this, &People::handleEntered);
}

QRectF People::boundingRect() const
{
    qreal yCoordinate = -(m_floor-1)*250 + 150;
    return QRectF(110, yCoordinate, 50, 100);
}

void People::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush(m_color);

    QPen pen(m_color);
    pen.setWidth(2);

    painter->setPen(pen);
    painter->setBrush(brush);

    painter->translate(rect.bottomLeft());

    painter->drawLine(0, 0, 20, -20);
    painter->drawLine(20, -20, 40, 0);
    painter->drawLine(20, -20, 20, -80);
    painter->drawLine(0, -50, 20, -70);
    painter->drawLine(40, -50, 20, -70);
    painter->drawEllipse(QRectF(10, -100, 20, 20));
}

int People::getFloor()
{
    return m_floor;
}

void People::enter()
{
    inside = !inside;
    emit entered(!inside);
}

void People::setFloor(int floor)
{
    if (inside)
        m_floor = floor;
}

void People::handleEntered(bool inside)
{
    qreal newXCoordinate;
    qreal delta = 0;

    if (this->m_name == "Red")
        delta += 80;

    else if (this->m_name == "Green")
        delta += 90;

    else if (this->m_name == "Blue")
        delta += 100;


    newXCoordinate = inside ? (boundingRect().x() - 110) + delta : (boundingRect().x() - 110) - delta;

    setPos(newXCoordinate, pos().y());
    update();
}
