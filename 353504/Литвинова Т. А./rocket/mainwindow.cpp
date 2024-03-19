#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Rocket.h"
#include <QPainter>
#include <QPixmap>
#include <QPalette>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int width = 1500; // ширина в пикселях
    int height = 840;
    ui->setupUi(this);
    QPixmap bkgnd("/home/taisa/Загрузки/640px-Безмятежность.png");

    bkgnd = bkgnd.scaled(width, height, Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)// отрисовка обьекта
{
    QPainter painter(this);
    R->drawRocket(&painter);
    R->drawFlame(&painter);

}

void MainWindow::on_pushButton_clicked()
{
    R->engineStarted=true;
    //R->setVisible(true);
    //QPainter painter(this);

    //R->drawFlame(&painter);

 qDebug()<<"In mw1"<<R->engineStarted;
    R->move();
    repaint();

    for(int i=0;i<450;i++){
        R->move();
        repaint();
    }
    //R->setVisible(false);
    R->engineStarted=false;
    qDebug()<<"In mw2"<<R->engineStarted;
    //R->eraseFlame(&painter);
    repaint();

}




void MainWindow::on_pushButton_2_clicked()
{
    //R->setVisible(true);
    R->engineStarted=true;
    //QPainter painter(this);

    //R->drawFlame(&painter);


    if(R->y < 720){
        return;
    }



    for(int i=450;i>0;i--){
        R->moveDown();
        repaint();
    }

    R->engineStarted=false;
    repaint();
    //R->setVisible(false);
    //R->eraseFlame(&painter);



}

