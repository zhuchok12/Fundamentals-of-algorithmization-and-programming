#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegularExpressionValidator>

QString MainWindow::intToBinary(long long num, long long precision = -1) {
    if (num == 0 || precision == 0)
        return "";
    return intToBinary(num / 2) + QString::number(num % 2);
}


QString MainWindow::doubleToBinary(QString str) {
    str.replace(',', '.');
    QString i_str = str.left(str.indexOf('.')), f_str = str.mid(str.lastIndexOf('.') + 1);
    long long i = i_str.toLongLong(), f = f_str.toLongLong() ;
    if (str.indexOf('.') != -1 && f != 0)
        return intToBinary(i) + '.' + intToBinary(f, 100);
    else if (f == 0)
        return intToBinary(i)+".0";
    else
        return intToBinary(i);
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[-+]?[0-9]{1,16}(?:[.,][0-9]{1,16})?$"),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    if (str == ""){
        ui->ans->setText("Fill some number");
    } else {
        ui->ans->setText("Processing...");
        QCoreApplication::processEvents();
        str = doubleToBinary(str);
        ui->ans->setText("ans: " + str);
    }
}

