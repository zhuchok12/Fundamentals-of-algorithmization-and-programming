#ifndef BODY_H
#define BODY_H

#include <QWidget>

class Body : public QWidget
{
    Q_OBJECT
public:
    Body(int x, int y, int w, int h);
    void rect_upt(int x, int y, int w, int h);
    int get_x_pos(){return x_pos;}
    int get_y_pos(){return y_pos;}
    int get_height(){return height;}
    int get_width(){return width;}
    void x_pos_incr(int x){x_pos += x;}
    QRect get_rect(){return Rect;}
private:
    QRect Rect;
    int x_pos;
    int y_pos;
    int height;
    int width;
};

#endif // BODY_H
