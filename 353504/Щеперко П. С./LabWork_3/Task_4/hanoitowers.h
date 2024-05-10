#ifndef HANOITOWERS_H
#define HANOITOWERS_H

#include<QPainter>
#include<QGraphicsObject>

class HanoiTowers : public QGraphicsObject
{
public:

    HanoiTowers();

    bool isChanging = true;
    bool finished = false;

    int n = 1;
    int lastEmptyPositionA = 230;
    int lastEmptyPositionB = 230;
    int lastEmptyPositionC = 230;
    int posN[10] = {180, 160, 140, 120, 100, 80, 60, 40, 20, 0};

    void SetN(int num);
    void changeNumberOfRings(int arg);
    void animate(int num,char from,char to);

protected:

    QRectF boundingRect() const;
    QPointF DiskPosition[10];

    bool onPositionY[10]{};
    bool onPositionX[10]{};
    bool DiskUnused[10] = {true,true,true,true,true,true,true,true,true,true};

    int posMinN[10] = {-180, -160, -140, -120, -100, -80, -60, -40, -20, 0};
    int DiskWidth[10] = {240, 220, 200, 180, 160, 140, 120, 100, 80, 60}; // Width of disks
    int DiskHeight = 20;
    int TowerX[3] = {-300, 0, 300};

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // HANOITOWERS_H
