#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include <QVector2D>
#include "ifigure.h"
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void setButtons(bool a);
    void info(IFigure a);
    void lFigure(IFigure a);
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
private:
    bool lastIsLine = false;
    bool processing1 = false;
    bool processing2 = false;
    bool processing3 = false;
    bool processing4 = false;
    short counter1 = 0;
    short counter2 = 0;
    short counter3 = 0;
    short counter4 = 0;
    double scaleUp=1;
    double scaleDown=1;
    double roll=0;
    IFigure lastFigure;
    double rotationX = 0;
    double rotationY = 0;
    int size = 5;
    int size_2 = 5;
    int size_3 = 5;
    int currentFigure = 0;
    int currentPosArr = 0;
    bool isDrawing = 0;
    QTimer timer1;
    QTimer timer2;
    QTimer timer3;
    QTimer timer4;
    QVector<QVector<QVector2D>> line ;
    Ui::Widget *ui;
};
#endif // WIDGET_H
