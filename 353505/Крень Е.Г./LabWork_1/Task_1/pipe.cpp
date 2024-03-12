#include "pipe.h"

Pipe::Pipe(int x, int y,  int w, int h)
    :Body(x,y,w,h)
    ,Smoke_1(x, -100, 20, 10)
    ,Smoke_2(x, -100, 20, 10)
    ,Smoke_3(x, -100, 20, 10)
{
}
void Pipe::smoke_physik(bool active, int speed){
    bool s1=0, s2=0, s3=0;

    if(Smoke_1.y()<0 && active){
        Smoke_1.setRect(get_x_pos(), 250, 20, 10);
    }
    else if(Smoke_1.y()>-300){
        Smoke_1.setRect(Smoke_1.x()-1, Smoke_1.y()-5, Smoke_1.width()+1, Smoke_1.height()+1);
    }
    else{
        Smoke_1.setRect(get_x_pos(), -100, 20, 10);
    }

    if(Smoke_2.y()<0 && active && Smoke_1.y()<=167 && Smoke_1.y()>= 0){
        Smoke_2.setRect(get_x_pos()+speed/100, 250, 20, 10);
    }
    else if(Smoke_2.y()>-300 && qAbs(Smoke_2.y() - Smoke_1.y()) >= 83){
        Smoke_2.setRect(Smoke_2.x()-1, Smoke_2.y()-5, Smoke_2.width()+1, Smoke_2.height()+1);
    }
    else{
        Smoke_2.setRect(get_x_pos(), -100, 20, 10);
    }

    if(Smoke_3.y()<0 && active && Smoke_1.y()<=83 && Smoke_1.y()>= 0){
        Smoke_3.setRect(get_x_pos()+speed/100, 250, 20, 10);
    }
    else if(Smoke_3.y()>-300 && qAbs(Smoke_3.y() - Smoke_2.y()) >= 83){
        Smoke_3.setRect(Smoke_3.x()-1, Smoke_3.y()-5, Smoke_3.width()+1, Smoke_3.height()+1);
    }
    else{
        Smoke_3.setRect(get_x_pos(), -100, 20, 10);
    }
}
