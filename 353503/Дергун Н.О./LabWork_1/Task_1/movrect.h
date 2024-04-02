#ifndef MOVRECT_H
#define MOVRECT_H

#include <QPoint>
#include <QSize>
#include <QWidget>
#include <QMainWindow>
#include <QPainter>
#include <QTimer>

class MovRect : public QWidget
{
    Q_OBJECT

public:
    explicit MovRect(QWidget *parent = nullptr);
    MovRect(QPoint, QSize, qreal, QWidget *parent = nullptr);
    ~MovRect();
    void setRotCenter(bool);
    bool getRotCenter();
    QPointF getEndPos();

protected:
    bool c_rot, clockwise, cntr_clockwise;
    QPointF center; //of rotation
    qreal angle;
    QSizeF size; //of rectangle
    QTimer* timer;
    void paintEvent(QPaintEvent*);

protected slots:
    void slotBeginCW();
    void slotBeginCntrCW();
    void slotEndCW();
    void slotEndCntrCW();
    void slotTimerAlarm();
    void slotChangeCenter();
private slots:
    void slotReset();
};
#endif // MOVRECT_H
