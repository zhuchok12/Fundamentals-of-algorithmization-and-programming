#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //isFullScreen();
    //QWidget::setFixedSize(1850, 1050);
}

MainWindow::~MainWindow()
{
    delete ui;
}
