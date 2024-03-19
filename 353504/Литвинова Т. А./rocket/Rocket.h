#ifndef ROCKET_H
#define ROCKET_H
#include "Line.h"

class Rocket : public Line {
public:
    bool engineStarted = false;
    Rocket();
    void paintEvent(QPaintEvent *event);
    void drawRocket(QPainter *painter);
    void drawFlame(QPainter *painter);
};

#endif // ROCKET_H
