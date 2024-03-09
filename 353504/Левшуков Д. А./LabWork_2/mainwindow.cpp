#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showing=false;
    //this->showFullScreen();
    ctrlo= new QShortcut(this);
    ctrlo->setKey(Qt::CTRL + Qt::Key_O);
    //ui->Table->column
    connect(ctrlo, SIGNAL(activated()), this, SLOT(on_OpenFileButton_clicked()));
    /*
    qDebug()<<birthday->get_date();
    birthday->Init("01.03.2024");
    qDebug()<<"Today: "<<birthday->get_date();
    qDebug()<<"Next day: "<<birthday->NextDay().get_date();
    qDebug()<<"Previous day: "<<birthday->PreviousDay().get_date()
    */
    birthday={-1,-1,-1};
    //ShowTable();
    Today();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FileRead()
{
    if(file=="")return;

    std::ifstream cin(file.toUtf8().constData());
    std::string s;
    data->clear();
    while(cin>>s)
    {
        if(current.Init(s))
    data->push_back(current);
    //qDebug()<<s<<" "<<current.get_year();
    }
    ShowTable();
}


void MainWindow::Today()
{
    t=t.today();
    ui->Today->setText("Today: "+QString::fromStdString(t.get_date()));
}


void MainWindow::ShowTable()
{
    Today();

    long long n=data->size();
    long long rows=ui->Table->rowCount();
    showing=true;
    for(int i=0;i<rows;i++)
        ui->Table->removeRow(i);

    ui->Table->setRowCount(n);
    qDebug()<<"Start build table\nRows"<<n;

    for(int i=0;i<n;i++)
    {
        QTableWidgetItem* real= new QTableWidgetItem;
        real->setTextAlignment(Qt::AlignCenter);
        real->setText(QString::fromStdString(data->get_string(i)));
        ui->Table->setItem(i,0,real);

        QTableWidgetItem* prev= new QTableWidgetItem;
        prev->setTextAlignment(Qt::AlignCenter);
        prev->setText(QString::fromStdString(data->get(i).PreviousDay()));
        ui->Table->setItem(i,1,prev);

        QTableWidgetItem* next= new QTableWidgetItem;
        next->setTextAlignment(Qt::AlignCenter);
        next->setText(QString::fromStdString(data->get(i).NextDay()));
        ui->Table->setItem(i,2,next);

        if(birthday.get_day()!=-1)
        {
        //qDebug()<<(data->get(i).Duration(birthday));
        QTableWidgetItem* bi= new QTableWidgetItem;
        bi->setTextAlignment(Qt::AlignCenter);
        if((birthday.get_month()==data->get(i).get_month()&&birthday.get_day()>=data->get(i).get_day())||(birthday.get_month()>data->get(i).get_month()))
        birthday.set_year(data->get(i).get_year());
        else
            birthday.set_year(data->get(i).get_year()+1);
        long long bdr =data->get(i).Duration(birthday);
        //birthday.set_year(y);
        std::string bdr_str=std::to_string(abs(bdr));
        if(bdr==0)
            bdr_str = "now";
        bi->setText(QString::fromStdString(bdr_str));
        ui->Table->setItem(i,3,bi);
        }
        else
        {
            QTableWidgetItem* bi= new QTableWidgetItem;
            bi->setTextAlignment(Qt::AlignCenter);
            bi->setText("NO INFO");
            ui->Table->setItem(i,3,bi);
        }

        if(i>0)
        {
        QTableWidgetItem* dur= new QTableWidgetItem;
        dur->setTextAlignment(Qt::AlignCenter);
        //qDebug()<<data->get_string(i)<<" and "<<data->get_string(i-1);
        long long dr =data->get(i).Duration(data->get(i-1));
        std::string d_str=std::to_string(abs(dr));
        if(dr>0)
            d_str += " ago";
        else if(dr<0)
            d_str += " before";
        else
            d_str="now";
        dur->setText(QString::fromStdString(d_str));
        ui->Table->setItem(i,4,dur);
        }

        QTableWidgetItem* to_today= new QTableWidgetItem;
        to_today->setTextAlignment(Qt::AlignCenter);
        long long d=data->get(i).Duration(t);
        std::string to_t=std::to_string(abs(d))+" ";
        if(d<0)
        {
            to_t+="ago";
        }
        else
            to_t+="before";
        to_today->setText(QString::fromStdString(to_t));
        ui->Table->setItem(i,5,to_today);

    }
    showing=false;

}


void MainWindow::on_OpenFileButton_clicked()
{
    file=QFileDialog::getOpenFileName(this,"Open File","/home/dzmitry","*.txt");
    qDebug()<<file;
    FileRead();
}


void MainWindow::on_DateOfBirthday_textChanged()
{
    //QString text=ui->DateOfBirthday->toPlainText();
    std::string text=ui->DateOfBirthday->toPlainText().toStdString();
    //qDebug()<<text<<"[1]";
    if(!isdigit(text.back())&&text.back()!='.'&&text.size()>0)
    {
        text.pop_back();
        //qDebug()<<text<<"[2]";
        //ui->DateOfBirthday->clear();
        //ui->DateOfBirthday->setText(QString::fromStdString(text));
        if(!birthday.Init(text))
        {
            ui->DateOfBirthday->clear();
            ui->DateOfBirthday->setTextColor(Qt::red);
            //ui->DateOfBirthday->setTe
            ui->DateOfBirthday->setPlainText("You are retard <3");
            //ui->DateOfBirthday->setText("You are retard <3");
            ui->DateOfBirthday->setTextColor(Qt::white);
            //timer->start(1e4);
            ui->DateOfBirthday->repaint();
            QThread::sleep(1);
            ui->DateOfBirthday->clear();
        }
        else
        {
            ui->DateOfBirthday->clear();
            ui->birth->setText(QString::fromStdString(birthday.get_date()));
            ShowTable();
        }
    }
}


//void MainWindow::CellUpdate()


void MainWindow::on_Table_itemChanged(QTableWidgetItem *item)
{
    if(showing)return;
    if(item->column())
        return item->setText(QString::fromStdString(data->get(item->row()).get_date()));

    qDebug()<<"Try to edit. ID: "<<item->row();
    std::string new_value=item->text().toUtf8().constData();
    Date nw;
    if(!nw.Init(new_value))
    {
        qDebug()<<"Incorrect edit";
        item->setText(QString::fromStdString(data->get(item->row()).get_date()));
    }
    else
    {

        qDebug()<<"Correct edit";
        data->update(nw,item->row());
        qDebug()<<data->get(item->row()).get_date();
        //FileUpdate(item->row());
        ShowTable();
    }
}

/*
void MainWindow::FileUpdate()
{

}
*/
