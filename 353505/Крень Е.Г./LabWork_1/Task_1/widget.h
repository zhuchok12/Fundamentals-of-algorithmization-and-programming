#ifndef WIDGET_H
#define WIDGET_H

#include <QTimer>
#include <QPainter>
#include "pipe.h"

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
    void paintEvent(QPaintEvent *event) override;
private:
    bool isClicked = 0;
    QTimer body_render_timer;
    QTimer smoke_render_timer;
    Body body;
    Body cabin;
    Pipe pipe;
    Ui::Widget *ui;
};
#endif // WIDGET_H
