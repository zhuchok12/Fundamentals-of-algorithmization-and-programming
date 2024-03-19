#ifndef FIGUREMODEL_H
#define FIGUREMODEL_H

//#pragma once
#include <QGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QTransform>
#include <QPushButton>

class FigureModel : public QGraphicsItem {
private:
    bool setCenter = false;
    QTimer *timer;


public:
    int centerX = 0, centerY = 0;
    int mouseX, mouseY;
    double square=0;
    double perimetr=0;

    explicit FigureModel(QGraphicsItem *parent = nullptr);

    virtual void draw(QPainter *painter) = 0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
        draw(painter);
    }
    QRectF boundingRect() const {
        // Возвращает ограничивающий прямоугольник
        return QRectF(-100,-100,625,450);
    }
    void move(int dx, int dy);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual double calculateSquare()=0;
    virtual double calculatePerimetr()=0;


private slots:
    //void rotate();

};
#endif // FIGUREMODEL_H
