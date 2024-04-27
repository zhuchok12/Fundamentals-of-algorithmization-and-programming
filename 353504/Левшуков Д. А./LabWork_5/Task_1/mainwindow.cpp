#include "mainwindow.h"
#include "ui_mainwindow.h"

#define Button(x) ui->b##x

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setBelarussian();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBelarussian()
{
    alphabet="Ё            ЙЦУКЕНГШЎЗХ ФЫВАПРОЛДЖЭЯЧСМІТЬБЮ ё            йцукенгшўзх фывапролджэячсмітьбю ";

    Caps_on=false;
    Shift_on=false;

    clearKeyboard();


}

QPushButton *MainWindow::getButton(int ind)
{
    if(ind==1)
        return Button(1);
    if(ind==2)
        return Button(2);
    if(ind==3)
        return Button(3);
    if(ind==4)
        return Button(4);
    if(ind==5)
        return Button(5);
    if(ind==6)
        return Button(6);
    if(ind==7)
        return Button(7);
    if(ind==8)
        return Button(8);
    if(ind==9)
        return Button(9);
    if(ind==10)
        return Button(10);
    if(ind==11)
        return Button(11);
    if(ind==12)
        return Button(12);
    if(ind==13)
        return Button(13);
    if(ind==14)
        return Button(14);
    if(ind==15)
        return Button(15);
    if(ind==16)
        return Button(16);
    if(ind==17)
        return Button(17);
    if(ind==18)
        return Button(18);
    if(ind==19)
        return Button(19);
    if(ind==20)
        return Button(20);
    if(ind==21)
        return Button(21);
    if(ind==22)
        return Button(22);
    if(ind==23)
        return Button(23);
    if(ind==24)
        return Button(24);
    if(ind==25)
        return Button(25);
    if(ind==26)
        return Button(26);
    if(ind==27)
        return Button(27);
    if(ind==28)
        return Button(28);
    if(ind==29)
        return Button(29);
    if(ind==30)
        return Button(30);
    if(ind==31)
        return Button(31);
    if(ind==32)
        return Button(32);
    if(ind==33)
        return Button(33);
    if(ind==34)
        return Button(34);
    if(ind==35)
        return Button(35);
    if(ind==36)
        return Button(36);
    if(ind==37)
        return Button(37);
    if(ind==38)
        return Button(38);
    if(ind==39)
        return Button(39);
    if(ind==40)
        return Button(40);
    if(ind==41)
        return Button(41);
    if(ind==42)
        return Button(42);
    if(ind==43)
        return Button(43);
    if(ind==44)
        return Button(44);
    if(ind==45)
        return Button(45);
    if(ind==46)
        return Button(46);
    //Caps
    if(ind==47)
        return ui->CapsLock;
    //Shift
    if(ind==48)
        return ui->Shift;
    //Shift
    if(ind==49)
        return ui->Space;
}

void MainWindow::clearKeyboard()
{
    for(int i=1;i<=49;i++)
    {
        getButton(i)->setStyleSheet(default_button);
        if(i<=46)
        getButton(i)->setText(alphabet[i-1]);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    //qDebug()<<index;
    if(index==0)//Belarussian
    {
        setBelarussian();
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1==2)
        for(int i=1;i<=49;i++)
        {
            if(getButton(i)->text()==" ")
                getButton(i)->hide();
        }
    else
        for(int i=1;i<=49;i++)
        {
                getButton(i)->show();
        }
}

