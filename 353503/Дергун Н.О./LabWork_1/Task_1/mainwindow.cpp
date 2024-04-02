#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(700, 400);
    setMaximumSize(1000, 600);
}

MainWindow::~MainWindow()
{
    delete ui;
}
