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

void MainWindow::on_lineEdit_textChanged(const QString &text)
{
    std::string str = text.toStdString();
    const char *start = str.c_str();
    char *end;
    long double value = strtold(start, &end);

    if (str.empty())
    {
        ui->label_binary->setText("");
        ui->label_IEEE->setText("");
    }

    else
    {
        ui->label_binary->setText(Converter::ToBin(value));
        ui->label_IEEE->setText(Converter::ToIEEE(value));
    }
}
