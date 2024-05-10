#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "figure.h"

class Parallelogram : public Figure
{
    Q_OBJECT
public:
    explicit Parallelogram(QPointF point, QObject *parent = nullptr);
    ~Parallelogram();

    qreal square() override;
    qreal perimeter() override;

protected:
    QPointF A, B, C, D;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // PARALLELOGRAM_H
