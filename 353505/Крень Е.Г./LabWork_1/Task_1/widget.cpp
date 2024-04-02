#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , body(0, 300, 200, 70)
    , pipe(body.get_x_pos()+160, body.get_y_pos()-50, 20, 20)
    , body_render_timer()
    , cabin(body.get_x_pos(), body.get_y_pos() -40, 90, 40)
{

    ui->setupUi(this);
    int speed = 0;
    qDebug()<<speed;

    ui->verticalSlider->setTickPosition(QSlider::TicksLeft);
    ui->verticalSlider->setRange(0, 1000);

    connect(ui->verticalSlider, &QAbstractSlider::valueChanged, [this, &speed](){
        qDebug()<<speed;
        speed = ui->verticalSlider->value();
    });

    connect(ui->pushButton, &QPushButton::clicked, [this](){
        if(!this->isClicked){
        body_render_timer.start(10);
        smoke_render_timer.start(10);
        this->isClicked = 1;
        }else{
            this->isClicked=0;
        }
    });

    connect(&body_render_timer, &QTimer::timeout, [this, &speed](){
        QWidget::update();
        if(ui->verticalSlider->value()==0)speed=0;
        body_render_timer.start(10);
        if(isClicked){
            body.x_pos_incr(speed/100);
            if(body.get_x_pos()>=1920){
                body.x_pos_incr(-2120);
            }
        }
        pipe.smoke_physik(isClicked, speed);
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    painter.setBrush(QBrush(Qt::cyan));
    painter.drawRect(0,0,2000, 280);
    painter.setBrush(QBrush(Qt::green));
    painter.drawRect(0,280,2000, 1000);
    painter.setBrush(QBrush(Qt::lightGray));
    painter.drawRect(0,330,2000, 100);


    QRect wheel1(body.get_x_pos(),body.get_y_pos() + 50 ,40, 40);
    QRect wheel2(body.get_x_pos() + 53,body.get_y_pos() + 50 ,40, 40);
    QRect wheel3(body.get_x_pos() + 106,body.get_y_pos() + 50 ,40, 40);
    QRect wheel4(body.get_x_pos() + 159,body.get_y_pos() + 50 ,40, 40);
    body.rect_upt(body.get_x_pos(), body.get_y_pos(), body.get_width(), body.get_height());
    pipe.rect_upt(body.get_x_pos()+160, body.get_y_pos()-50, 20, 50);
    cabin.rect_upt(body.get_x_pos(), body.get_y_pos() -40, 90, 40);

    painter.setBrush(QBrush(Qt::black));
    painter.drawEllipse(wheel1);
    painter.drawEllipse(wheel2);
    painter.drawEllipse(wheel3);
    painter.drawEllipse(wheel4);

    painter.setBrush(QBrush(Qt::darkBlue));
    painter.drawRect(cabin.get_rect());

    painter.setBrush(QBrush(Qt::darkGray));
    painter.drawEllipse(pipe.get_smoke1());
    if(pipe.get_smoke2().y()<250){painter.drawEllipse(pipe.get_smoke2());}
    if(pipe.get_smoke3().y()<250){painter.drawEllipse(pipe.get_smoke3());}



    painter.setBrush(QBrush(Qt::red));
    painter.drawRect(pipe.get_rect());
    painter.drawRect(body.get_rect());
}


