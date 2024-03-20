#include "widget.h"
#include "./ui_widget.h"
#include "figure.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , timer1()
    , timer2()
    , timer3()
    , timer4()
{
    ui->setupUi(this);
    ui->spinBox->setRange(5, 1000);
    ui->spinBox->hide();
    ui->spinBox_2->setRange(5, 1000);
    ui->spinBox_2->hide();
    ui->spinBox_3->setRange(5, 1000);
    ui->spinBox_3->hide();
    ui->spinBox_4->setRange(-360, 360);
    ui->spinBox_5->setRange(-1000, 1000);
    ui->spinBox_6->setRange(-1000, 1000);

    setButtons(1);


    connect(ui->pushButton, &QPushButton::clicked, [this](){
        if(processing1||processing2||processing3||processing4) return;
        if(currentPosArr>0){
            line.pop_back();
            currentPosArr--;
            QWidget::update();
            ui->label_4->setText("");
            ui->label_5->setText("");
            ui->label_6->setText("");
            ui->label_10->setText("");
            setButtons(1);
        }
    });

    connect(ui->spinBox, &QSpinBox::valueChanged, [this](){
        size = ui->spinBox->value();
    });

    connect(ui->spinBox_2, &QSpinBox::valueChanged, [this](){
        size_2 = ui->spinBox_2->value();
    });

    connect(ui->spinBox_3, &QSpinBox::valueChanged, [this](){
        size_3 = ui->spinBox_3->value();
    });

    connect(ui->spinBox_4, &QSpinBox::valueChanged, [this](){
        roll = ui->spinBox_4->value();
    });

    connect(ui->spinBox_5, &QSpinBox::valueChanged, [this](){
        rotationX = ui->spinBox_5->value();
    });

    connect(ui->spinBox_6, &QSpinBox::valueChanged, [this](){
        rotationY = ui->spinBox_6->value();
    });

    connect(ui->doubleSpinBox, &QDoubleSpinBox::valueChanged, [this](){
        scaleUp = ui->doubleSpinBox->value();
    });

    connect(ui->doubleSpinBox_2, &QDoubleSpinBox::valueChanged, [this](){
        scaleDown = ui->doubleSpinBox_2->value();
    });

    connect(ui->pushButton_3, &QPushButton::clicked, [this](){
        ui->pushButton_3->setDisabled(1);
        counter1 = 0;
        processing1 = 1;
        timer1.start(30);
        ui->pushButton->setDisabled(1);
        ui->spinBox_5->setDisabled(1);
        ui->spinBox_6->setDisabled(1);
    });

    connect(&timer1, &QTimer::timeout, [this](){
        if(counter1++<100){
            ui->pushButton->setDisabled(1);
            processing1 = 1;
            timer1.start(30);
            lastFigure.transform(rotationX/100, -1*rotationY/100);
            if(!lastIsLine)info(lastFigure);
            line.pop_back();
            line.push_back(lastFigure.getCoordinates());
            QWidget::update();
        }else{
            timer1.stop();
            processing1 = 0;
            ui->pushButton_3->setDisabled(0);
            ui->pushButton->setDisabled(0);
            ui->spinBox_5->setDisabled(0);
            ui->spinBox_6->setDisabled(0);
        }
    });

    connect(ui->pushButton_2, &QPushButton::clicked, [this](){
        counter2 = 0;
        processing2 = 1;
        ui->pushButton_2->setDisabled(1);
        timer2.start(30);
        ui->pushButton->setDisabled(1);
        ui->spinBox_4->setDisabled(1);
    });

    connect(&timer2, &QTimer::timeout, [this](){
        if(counter2++<100){
            ui->pushButton->setDisabled(1);
            processing2 = 1;
            timer2.start(30);
            lastFigure.rotation(roll/100);
            if(!lastIsLine)info(lastFigure);
            line.pop_back();
            line.push_back(lastFigure.getCoordinates());
            QWidget::update();
        }else{
            timer2.stop();
            ui->pushButton_2->setDisabled(0);
            processing2 = 0;
            ui->pushButton->setDisabled(0);
            ui->spinBox_4->setDisabled(0);
        }
    });

    connect(ui->pushButton_4, &QPushButton::clicked, [this](){
        ui->pushButton_4->setDisabled(1);
        ui->pushButton_5->setDisabled(1);
        ui->pushButton->setDisabled(1);
        counter3 = 0;
        processing3 = 1;
        timer3.start(30);
        ui->doubleSpinBox->setDisabled(1);
        ui->doubleSpinBox_2->setDisabled(1);
    });

    connect(&timer3, &QTimer::timeout, [this](){
        if(counter3++<100){
            ui->pushButton->setDisabled(1);
            processing3 = 1;
            timer3.start(30);
            lastFigure.scaleUp(qPow(scaleUp, 0.01));
            if(!lastIsLine)info(lastFigure);
            line.pop_back();
            line.push_back(lastFigure.getCoordinates());
            QWidget::update();
        }else{
            timer3.stop();
            ui->pushButton_4->setDisabled(0);
            ui->pushButton_5->setDisabled(0);
            ui->pushButton->setDisabled(0);
            ui->doubleSpinBox->setDisabled(1);
            ui->doubleSpinBox_2->setDisabled(1);
            processing3 = 0;
        }
    });

    connect(ui->pushButton_5, &QPushButton::clicked, [this](){
        ui->pushButton_4->setDisabled(1);
        ui->pushButton_5->setDisabled(1);
        ui->pushButton->setDisabled(1);
        counter4 = 0;
        processing4 = 1;
        timer4.start(30);
    });

    connect(&timer4, &QTimer::timeout, [this](){
        if(counter4++<100){
            ui->pushButton->setDisabled(1);
            processing4 = 1;
            timer4.start(30);
            lastFigure.scaleDown(qPow(scaleDown, 0.01));
            if(!lastIsLine)info(lastFigure);
            line.pop_back();
            line.push_back(lastFigure.getCoordinates());
            QWidget::update();
        }else{
            timer4.stop();
            ui->pushButton_4->setDisabled(0);
            ui->pushButton_5->setDisabled(0);
            ui->pushButton->setDisabled(0);
            processing4 = 0;
        }
    });

    connect(ui->comboBox, &QComboBox::currentIndexChanged, [this]( int a){
        currentFigure = a;
        switch (a) {
        case 1:
            ui->label->setText("Радиус");
            ui->spinBox->show();
            ui->label_2->setText("");
            ui->spinBox_2->hide();
            ui->label_3->setText("");
            ui->spinBox_3->hide();
            break;
        case 2:
            ui->label->setText("Полуось по Х");
            ui->spinBox->show();
            ui->label_2->setText("Полуось по Y");
            ui->spinBox_2->show();
            ui->label_3->setText("");
            ui->spinBox_3->hide();
            break;
        case 3:
            ui->label->setText("Длинна");
            ui->spinBox->show();
            ui->label_2->setText("Ширина");
            ui->spinBox_2->show();
            ui->label_3->setText("");
            ui->spinBox_3->hide();
            break;
        case 4:
            ui->label->setText("Вертикальная диагональ");
            ui->spinBox->show();
            ui->label_2->setText("Горизонтальная диагональ");
            ui->spinBox_2->show();
            ui->label_3->setText("");
            ui->spinBox_3->hide();
            break;
        case 5:
            ui->label->setText("Сторона квадрата");
            ui->spinBox->show();
            ui->label_2->setText("");
            ui->spinBox_2->hide();
            ui->label_3->setText("");
            ui->spinBox_3->hide();
            break;
        case 6:
            ui->label->setText("Радиус внешних точек");
            ui->spinBox->show();
            ui->label_2->setText("Радиус внутренних точек");
            ui->spinBox_2->show();
            ui->label_3->setText("");
            ui->spinBox_3->hide();
            break;
        case 7:
            ui->label->setText("Сторона треугольника");
            ui->spinBox->show();
            ui->label_2->setText("");
            ui->spinBox_2->hide();
            ui->label_3->setText("");
            ui->spinBox_3->hide();
            break;
        case 8:
            ui->label->setText("Сторона шестиугольника");
            ui->spinBox->show();
            ui->label_2->setText("");
            ui->spinBox_2->hide();
            ui->label_3->setText("");
            ui->spinBox_3->hide();
            break;
        case 9:
            ui->label->setText("Нижнее основание");
            ui->spinBox->show();
            ui->label_2->setText("Верхнее основание");
            ui->spinBox_2->show();
            ui->label_3->setText("Высота");
            ui->spinBox_3->show();
            break;
        default:
            ui->label->setText("");
            ui->spinBox->hide();
            ui->label_2->setText("");
            ui->spinBox_2->hide();
            ui->label_3->setText("");
            ui->spinBox_3->hide();
            break;
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setButtons(bool a){
    ui->pushButton_2->setDisabled(a);
    ui->pushButton_3->setDisabled(a);
    ui->pushButton_4->setDisabled(a);
    ui->pushButton_5->setDisabled(a);
}

void Widget::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(Qt::black));
    QPen pen(Qt::black);
    pen.setWidth(1);
    painter.setPen(pen);

    for(int j = 0; j<line.size(); ++j){
        if(line[j].size()==1){
            painter.drawPoint(line[j][0].x(), line[j][0].y());
        }else{
            for(int i = 0; i<line[j].size()-1; ++i){
                painter.drawLine(line[j][i].x(), line[j][i].y(), line[j][i+1].x(), line[j][i+1].y());
            }
        }
    }

    painter.setBrush(QBrush(Qt::lightGray));
    painter.drawRect(0,0,2000,140);
}

void Widget::info(IFigure a){
    ui->label_4->setNum(a.getPerimeter());
    ui->label_5->setNum(a.getArea());
    ui->label_6->setNum((int)a.getCenterCoordinates().x());
    ui->label_10->setNum((int)a.getCenterCoordinates().y());

}

void Widget::lFigure(IFigure a){
    line.push_back(a.getCoordinates());
    currentPosArr++;
    info(a);
    setButtons(0);
    lastFigure = a;
}

void Widget::mousePressEvent(QMouseEvent *event){
    if(processing1||processing2||processing3) return;

    if(QCursor::pos().y()<160){
        return;
    }
    switch (currentFigure) {
    case 1:
    {
        figures::circle a(QVector2D(mapFromGlobal(QCursor::pos())), size, 100);
        lFigure(a);
        break;
    }
    case 2:
    {
        figures::elipse a(QVector2D(mapFromGlobal(QCursor::pos())), size, size_2);
        lFigure(a);
        break;
    }
    case 3:
    {
        figures::rectangle a(QVector2D(mapFromGlobal(QCursor::pos())), size, size_2);
        lFigure(a);
        break;
    }
    case 4:
    {
        figures::rhomb a(QVector2D(mapFromGlobal(QCursor::pos())), size, size_2);
        lFigure(a);
        break;
    }
    case 5:
    {
        figures::square a(QVector2D(mapFromGlobal(QCursor::pos())), size);
        lFigure(a);
        break;
    }
    case 6:
    {
        figures::star a(QVector2D(mapFromGlobal(QCursor::pos())), size, size_2);
        lFigure(a);
        break;
    }
    case 7:
    {
        figures::triangle a(QVector2D(mapFromGlobal(QCursor::pos())), size/sqrt(3));
        lFigure(a);
        break;
    }
    case 8:
    {
        figures::hexagon a(QVector2D(mapFromGlobal(QCursor::pos())), size);
        lFigure(a);
        break;
    }
    case 9:
    {
        figures::trapezoid a(QVector2D(mapFromGlobal(QCursor::pos())), size_2, size, size_3);
        lFigure(a);
        break;
    }
    case 10:
    {
        setButtons(1);
        line.resize(line.size()+1);
        if (event->button() == Qt::LeftButton) {
            isDrawing = true;
            setButtons(true);
            QVector <QVector2D> a;
            line[currentPosArr].push_back(QVector2D(mapFromGlobal(QCursor::pos())));
        }
        break;
    }
    }
    QWidget::update();
}

void Widget::mouseMoveEvent(QMouseEvent* event){
    if(processing1||processing2||processing3) return;
    if(currentFigure == 10){
        if(isDrawing){
            line[currentPosArr].push_back(QVector2D(mapFromGlobal(QCursor::pos())));
            QWidget::update();
        }
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event){
    if(processing1||processing2||processing3) return;
    setButtons(0);
    if(currentFigure == 10&&isDrawing){
        if (event->button() == Qt::LeftButton) {
            lastFigure.setCoordinates(line[currentPosArr]);
            lastFigure.setCenterCoordinates(line[currentPosArr][0]);
            isDrawing = false;
            currentPosArr++;
        }
    }
}
