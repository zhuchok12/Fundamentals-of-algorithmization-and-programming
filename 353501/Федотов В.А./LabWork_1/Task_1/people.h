#ifndef PEOPLE_H
#define PEOPLE_H

#include "rectangle.h"

class People : public QGraphicsObject
{
    Q_OBJECT;
public:
    People(int floor, const QColor& color, const QString name);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    int getFloor();

private:
    bool inside;
    int m_floor;
    QColor m_color;
    QString m_name;

signals:
    void entered(bool inside);

public slots:
    void enter();
    void setFloor(int floor);

private slots:
    void handleEntered(bool inside);
};

#endif // PEOPLE_H
