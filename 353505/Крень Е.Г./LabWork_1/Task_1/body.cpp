#include "body.h"

Body::Body(int x, int y, int w, int h)
    :x_pos(x)
    ,y_pos(y)
    ,height(h)
    ,width(w)
    ,Rect(x, y, w, h)
{
}

void Body::rect_upt(int x, int y, int w, int h){
    x_pos = x;
    y_pos = y;
    width = w;
    height = h;
    Rect.setRect(x, y, w, h);
};
