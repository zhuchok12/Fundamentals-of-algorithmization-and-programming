#ifndef CIRCLE_H
#define CIRCLE_H

#include "figuremodel.h"

class Circle : public FigureModel{
public:
    int rad = 0;
    explicit Circle(FigureModel *parent = nullptr);

    void draw(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) ;
    double calculatePerimetr() override;
    double calculateSquare() override;
};

#endif // CIRCLE_H
