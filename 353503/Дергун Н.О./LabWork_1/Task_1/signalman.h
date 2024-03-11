#ifndef SIGNALMAN_H
#define SIGNALMAN_H

#include <QMainWindow>
#include "movrect.h"

class Signalman : public MovRect
{
    Q_OBJECT

    bool right_is_active;
    bool c_rot_mem;
    QPointF center_mem;
    qreal angle_mem;
    QSizeF size_mem;

    QPoint position;

    void paintEvent(QPaintEvent*) override;
public:
    explicit Signalman(QWidget *parent = nullptr);
    ~Signalman();

private slots:
    void slotChangeActiveHand();
};

#endif // SIGNALMAN_H
