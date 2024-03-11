#ifndef PIPE_H
#define PIPE_H

#include "body.h"
#include <QTimer>

class Pipe : public Body
{
public:
    Pipe(int x, int y, int w, int h);
    QRect get_smoke1(){return Smoke_1;}
    QRect get_smoke2(){return Smoke_2;}
    QRect get_smoke3(){return Smoke_3;}
    void set_smoke1(QRect a){Smoke_1 = a;}
    void set_smoke2(QRect a){Smoke_2 = a;}
    void set_smoke3(QRect a){Smoke_3 = a;}
    void smoke_physik(bool active, int speed);


private:
    QRect Smoke_1;
    QRect Smoke_2;
    QRect Smoke_3;
};

#endif // PIPE_H
