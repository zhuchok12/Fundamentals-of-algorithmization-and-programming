#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //setup figureSelecter
    //ui->figureSelecter->setVisible(false);
    ui->FigureSelecter->addItem("Triangle");
    ui->FigureSelecter->addItem("Circle");
    ui->FigureSelecter->addItem("Rhomb");
    ui->FigureSelecter->addItem("Square");
    ui->FigureSelecter->addItem("Rect");
    ui->FigureSelecter->addItem("Star(5)");
    ui->FigureSelecter->addItem("Star(6)");
    ui->FigureSelecter->addItem("Star(8)");
    ui->FigureSelecter->addItem("Hexagon");
    ui->FigureSelecter->addItem("My trapeze");

    ui->FigureSelecter->setCurrentIndex(0);

    QColor col = QColor(Qt::red);
    if(col.isValid()) {
        QString qss = QString("color: white; background-color: black");
        ui->ButClear->setStyleSheet(qss);
    }

    //ui->pushButton->setText(ui->figureSelecter->currentText());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ButPaint_clicked()
{
    QColor col = QColor(Qt::red);
    if(col.isValid()) {
        QString qss = QString("color: %1").arg(col.name());
        ui->ButPaint->setStyleSheet(qss);
    }
    ui->ButMove->setStyleSheet("");
    ui->ButScale->setStyleSheet("");
    ui->ButRotate->setStyleSheet("");
    ui->FigureSelecter->setStyleSheet("");
}

void MainWindow::on_ButMove_clicked()
{
    QColor col = QColor(Qt::red);
    if(col.isValid()) {
        QString qss = QString("color: %1").arg(col.name());
        ui->ButMove->setStyleSheet(qss);
    }
    ui->ButPaint->setStyleSheet("");
    ui->ButScale->setStyleSheet("");
    ui->ButRotate->setStyleSheet("");
    ui->FigureSelecter->setStyleSheet("");
}

void MainWindow::on_FigureSelecter_currentIndexChanged(int index)
{
    ui->ButMove->setStyleSheet("");
    ui->ButPaint->setStyleSheet("");
    ui->ButScale->setStyleSheet("");
    ui->ButRotate->setStyleSheet("");

    QColor col = QColor(Qt::red);
    if(col.isValid()) {
        QString qss = QString("color: %1").arg(col.name());
        ui->FigureSelecter->setStyleSheet(qss);
    }
}

void MainWindow::on_ButScale_clicked()
{
    QColor col = QColor(Qt::red);
    if(col.isValid()) {
        QString qss = QString("color: %1").arg(col.name());
        ui->ButScale->setStyleSheet(qss);
    }
    ui->ButMove->setStyleSheet("");
    ui->FigureSelecter->setStyleSheet("");
    ui->ButPaint->setStyleSheet("");
    ui->ButRotate->setStyleSheet("");
}

void MainWindow::on_ButRotate_clicked()
{
    QColor col = QColor(Qt::red);
    if(col.isValid()) {
        QString qss = QString("color: %1").arg(col.name());
        ui->ButRotate->setStyleSheet(qss);
    }
    ui->ButMove->setStyleSheet("");
    ui->FigureSelecter->setStyleSheet("");
    ui->ButPaint->setStyleSheet("");
    ui->ButScale->setStyleSheet("");
}
