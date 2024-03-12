#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    {

    ui -> comboBox -> addItem( "Page_1" );
    ui -> comboBox -> addItem( "Page_2" );
    ui -> comboBox -> addItem( "Page_3" );
    ui -> comboBox -> addItem( "Hexagon" );
    ui -> comboBox -> addItem( "Page_5" );

    }

    scene = new QGraphicsScene();
    ui -> graphicsView -> setScene( scene );
    ui -> comboBox -> setCurrentIndex( 0 );
    connect( ui -> comboBox , SIGNAL( currentIndexChanged(int) ) , this , SLOT( change_figure(int) ) );



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: change_figure( int currentIndex ){

    this -> ui -> stackedWidget -> setCurrentIndex( currentIndex );
    scene -> clear();

    switch( currentIndex )
    {

        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            putHexagon();
            break;


        case 4:
            break;


    }

    setValue();

}

void MainWindow :: putHexagon()
{

    figure = new Hexagon;
    scene -> addItem( figure );
    connect( this -> ui -> horizontalSliderHexagon_1 , SIGNAL( valueChanged(int) ) , figure , SLOT( moveX(int) ) );

}

void MainWindow :: setValue()
{

    ui -> Area -> setText( QString :: number( figure -> Area() ) );
    ui -> Perimeter -> setText( QString :: number ( figure -> Perimeter() ) );

}

