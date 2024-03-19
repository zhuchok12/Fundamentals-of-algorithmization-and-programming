#include "circle.h"

Circle::Circle(FigureModel *parent) : FigureModel(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
    int rad = 0;


}

void Circle::draw(QPainter *painter){
    int r = qMax(mouseX, mouseY);
    this->rad=r;
    painter->drawEllipse(QPointF(centerX, centerY), r, r);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

double Circle::calculatePerimetr(){
    perimetr=2*3.14*this->rad;
    return perimetr;
    //return 1;
}

double Circle::calculateSquare(){
    square=3.14*this->rad*this->rad;
    return square;
    //return 11;
}
