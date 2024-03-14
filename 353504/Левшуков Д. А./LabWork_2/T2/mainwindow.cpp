#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OpenFileButton_clicked()
{
    file=(QFileDialog::getOpenFileName(this,"Open File","/home/dzmitry","*.inf")).toUtf8().constData();
    qDebug()<<file;
}

