#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f.clear();
    s.clear();
    f.push_back(1);
    s.push_back(make_pair(1,2.0));
    s.push_back(make_pair(1,2.0));
    s.push_back(make_pair(1,2.0));
    s.push_back(make_pair(1,2.0));
   // qDebug()<<matrix.capacity()<<" "<<matrix.size();
    matrix.push_back(make_pair(f,s));
    show_matrix();
    //qDebug()<<"All good";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_matrix()
{
    //First matrix
    ui->First->clear();
    std::string s="";
    for(int j=0;j<matrix.size();j++){
    for(int i=0;i<matrix[j].first.size();i++)
    {
        s+=std::to_string(matrix[j].first.at(i))+" ";
    }
    s.back()='\n';
    }
    qDebug()<<"First:"<<s;
    ui->First->setText(QString::fromStdString(s));

    s="";
    for(int j=0;j<matrix.size();j++){
    for(int i=0;i<matrix[j].second.size();i++)
    {
        s+="{"+std::to_string(matrix[j].second.at(i).first)+", "+std::to_string(matrix[j].second.at(i).first)+"} ";
    }
    s.back()='\n';
    }
    qDebug()<<"Seocnd:"<<s;
    ui->First->setText(QString::fromStdString(s));

    update();
}


