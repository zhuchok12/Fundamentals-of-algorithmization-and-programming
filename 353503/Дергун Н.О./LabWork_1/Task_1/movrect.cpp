#include "movrect.h"

MovRect::MovRect(QWidget *parent)
: QWidget(parent)
{
    center = {140, 140};
    angle = 0;
    size = {110, 15};
    c_rot = false;
    clockwise = false, cntr_clockwise = false;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start(50);
}

MovRect::MovRect(QPoint center, QSize size, qreal angle, QWidget *parent)
: QWidget(parent)
{
    this->center = center;
    this->size = size;
    this->angle = angle;
    c_rot = false;
    clockwise = false, cntr_clockwise = false;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start(50);
}

MovRect::~MovRect() {}

//**********************************************

void MovRect::slotBeginCW()
{
    clockwise = true;
}

void MovRect::slotBeginCntrCW()
{
    cntr_clockwise = true;
}

void MovRect::slotEndCW()
{
    clockwise = false;
}

void MovRect::slotEndCntrCW()
{
    cntr_clockwise = false;
}

void MovRect::slotTimerAlarm()
{
    if (clockwise && cntr_clockwise)
    {
        return;
    }
    else if (clockwise)
    {
        angle += 3;
        repaint();
    }
    else if (cntr_clockwise)
    {
        angle -= 3;
        repaint();
    }
}

//**********************************************

QPointF MovRect::getEndPos()
{
    return QPoint(center.x() + size.height() * cos(angle), center.y() + size.height() * sin(angle));
}

//**********************************************

void MovRect::setRotCenter(bool c_rot)
{
    this->c_rot = c_rot;
}

bool MovRect::getRotCenter()
{
    return c_rot;
}

void MovRect::slotChangeCenter()
{
    if (c_rot)
    {
        center += {-size.width()/2 * cos(angle / 180 * 3.14159), -size.width()/2 * sin(angle / 180 * 3.14159)};
    }
    else
    {
        center += {size.width()/2 * cos(angle / 180 * 3.14159), size.width()/2 * sin(angle / 180 * 3.14159)};
    }

    c_rot = !c_rot;
}

void MovRect::slotReset()
{
    center = {140, 140};
    angle = 0;
    repaint();
}

//**********************************************

void MovRect::paintEvent(QPaintEvent* pe)
{
    if (angle > 360)
    {
        angle -= 360;
    }

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(Qt::black);
    p.setBrush(Qt::gray);
    p.save();
    p.translate(center.x(), center.y());
    p.rotate(angle);
    p.drawRect(-size.width()/2 * c_rot, -size.height()/2, size.width(), size.height());
    p.restore();
    QWidget::paintEvent(pe);
}
