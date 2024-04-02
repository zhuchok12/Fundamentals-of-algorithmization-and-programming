#include "signalman.h"

Signalman::Signalman(QWidget *parent)
    : MovRect({175, 150}, {55, 10}, 90)
{
    position = {150, 150};
    c_rot_mem = false;
    c_rot = false;
    center_mem = {125, 150};
    angle_mem = 90;
    size_mem = {55, 10};
    right_is_active = true;
}

Signalman::~Signalman()
{

}

//**********************************************

void Signalman::slotChangeActiveHand()
{
    QPointF t1 = center;
    center = center_mem;
    center_mem = t1;
    qreal t2 = angle;
    angle = angle_mem;
    angle_mem = t2;
    right_is_active = !right_is_active;
}

//**********************************************

void Signalman::paintEvent(QPaintEvent* pe)
{
    if (angle_mem > 360)
    {
        angle_mem -= 360;
    }


    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(Qt::black);

    p.setBrush(Qt::lightGray);

    QPointF point_arr[7];
    point_arr[0] = {130, 150};
    point_arr[1] = {170, 150};
    point_arr[2] = {170, 170};
    point_arr[3] = {160, 200};
    point_arr[4] = {140, 200};
    point_arr[5] = {130, 170};

    p.drawPolygon(point_arr, 6);

    p.setBrush(Qt::gray);

    point_arr[0] = {125, 150};
    point_arr[1] = {130, 150};
    point_arr[2] = {130, 160};
    point_arr[3] = {125, 155};

    p.drawPolygon(point_arr, 4);

    point_arr[0] = {170, 150};
    point_arr[1] = {175, 150};
    point_arr[2] = {175, 155};
    point_arr[3] = {170, 160};

    p.drawPolygon(point_arr, 4);

    p.setBrush(Qt::darkGray);

    point_arr[0] = {160, 200};
    point_arr[1] = {170, 245};
    point_arr[2] = {155, 245};
    point_arr[3] = {150, 215};
    point_arr[4] = {145, 245};
    point_arr[5] = {130, 245};
    point_arr[6] = {140, 200};

    p.drawPolygon(point_arr, 7);

    p.setBrush(Qt::black);

    point_arr[0] = {165, 245};
    point_arr[1] = {160, 245};
    point_arr[2] = {160, 255};
    point_arr[3] = {168, 255};

    p.drawPolygon(point_arr, 4);

    point_arr[0] = {140, 245};
    point_arr[1] = {140, 255};
    point_arr[2] = {132, 255};
    point_arr[3] = {135, 245};

    p.drawPolygon(point_arr, 4);

    p.setBrush(Qt::white);

    point_arr[0] = {155, 150};
    point_arr[1] = {160, 140};
    point_arr[2] = {160, 130};
    point_arr[3] = {140, 130};
    point_arr[4] = {140, 140};
    point_arr[5] = {145, 150};

    p.drawPolygon(point_arr, 6);

    p.setBrush(Qt::lightGray);

    point_arr[0] = {165, 130};
    point_arr[1] = {160, 120};
    point_arr[2] = {140, 120};
    point_arr[3] = {135, 130};

    p.drawPolygon(point_arr, 4);

    p.setBrush(Qt::gray);
    p.save();
    p.translate(center_mem.x(), center_mem.y());
    p.rotate(angle_mem);
    p.drawRect(-size_mem.width()/2 * c_rot_mem, -size_mem.height()/2, size_mem.width(), size_mem.height());
    p.restore();

    MovRect::paintEvent(pe);
}
