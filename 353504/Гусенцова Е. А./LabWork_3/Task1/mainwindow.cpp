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

void MainWindow::on_pushButton_clicked()
{

    int num = ui->lineEdit->text().toDouble();
    if (num >=1024)
    {
        QMessageBox::information(this, tr("Warning!"), tr(" Your number is too big! "), QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }

    int output = func::recurs(num);
    ui->textBrowser->setText(QString::number(output));
}
