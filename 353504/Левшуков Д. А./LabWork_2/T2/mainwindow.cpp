#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ctrlo= new QShortcut(this);
    ctrlo->setKey(Qt::CTRL + Qt::Key_O);
    connect(ctrlo, SIGNAL(activated()), this, SLOT(on_OpenFileButton_clicked()));

    ctrls= new QShortcut(this);
    ctrls->setKey(Qt::CTRL + Qt::Key_S);
    connect(ctrls, SIGNAL(activated()), this, SLOT(on_SaveFileButton_clicked()));
    //showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OpenFileButton_clicked()
{
    file=(QFileDialog::getOpenFileName(this,"Open File","/home/dzmitry","*.inf")).toUtf8().constData();
    qDebug()<<file;
    if(file=="")
        return;
    FileRead();
}

void MainWindow::FileRead()
{
    std::ifstream fin(file);
    std::string s;
    std::getline(fin,s);
    if(s!="------=======Orders=======------")
    {
        //Bad file
        qDebug()<<"Bad file";
        return;
    }
    select_orders.clear();
    orders_in_file=s+'\n';
    while(s!="------=======Couriers=======------")//Orders read
    {
        std::getline(fin,s);
        orders_in_file+=s+'\n';
        qDebug()<<s;
        ReadOrders(s);
    }
    ui->OrderNumberSelect->addItems(select_orders);
    couriers_in_file="";
    while(std::getline(fin,s))
    {
        couriers_in_file+=s+'\n';
        ReadCouriers(s);
    }
    ui->CourierNumberSelect->addItems(select_couriers);
}

void MainWindow::ReadOrders(std::string s)
{
    //Example:[132332] {Belarus, Mogilev, blablabla, 54, 2} 24.01.2020 26.02.2022 1000 1400 228
    order now;
    Data from,to;

    if(s[0]!='[')return;

    int n=s.size(),i=1;

    for(;i<n;i++)
    {
        if(s[i]==']')
            break;
    }
    if(i==n)return;

    now.setNumber(s.substr(1,i-1));
    qDebug()<<"1:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();
    i+=2;
    if(s[i]!='{')return;
    int j=i+1;

    for(;i<n;i++)
    {
        if(s[i]=='}')
            break;
    }
    if(i==n)return;

    now.setAddres(s.substr(j,i-j));
    qDebug()<<"2:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();

    i+=2;
    j=i;
    for(;i<n;i++)
    {
        if(s[i]==' ')
        {
            i--;
            break;
        }
    }
    if(i==n)return;
    //qDebug()<<"Try init:"<<s.substr(j,i-j+1);
    if(from.Init(s.substr(j,i-j+1)))
    {
        now.setDate_from(from);
    }
    else
        return;
    qDebug()<<"3:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();

    i+=2;
    j=i;
    for(;i<n;i++)
    {
        if(s[i]==' ')
        {
            i--;
            break;
        }
    }
    if(i==n)return;

    if(to.Init(s.substr(j,i-j+1)))
    {
        now.setDate_to(to);
    }
    else
        return;
    qDebug()<<"4:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();

    i+=2;
    j=i;
    //qDebug()<<s[i];
    for(;i<n;i++)
    {
        if(s[i]==' ')
        {
            i--;
            break;
        }
    }
    //qDebug()<<i;
    if(i==n)return;
    int t=0;
    try
    {
        t=stoi(s.substr(j,i-j+1));
    }
    catch(...)
    {
        qDebug()<<"stoi catch error";
        return;
    }
    for(;j<=i;j++)
        if(!isdigit(s[j]))
            return;

    now.setTime_from(t);

    qDebug()<<"5:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();

    i+=2;
    j=i;
    for(;i<n;i++)
    {
        if(s[i]==' ')
        {
            i--;
            break;
        }
    }
    if(i==n)return;
    t=0;
    try
    {
        t=stoi(s.substr(j,i-j+1));
    }
    catch(...)
    {
        return;
    }
    for(;j<=i;j++)
        if(!isdigit(s[j]))
            return;

    now.setTime_to(t);
    qDebug()<<"6:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();
    i+=2;
    j=i;

    unsigned long long w=0;
    try
    {
        w=stoull(s.substr(j,n-j));
    }
    catch(...)
    {
        return;
    }
    for(;j<n;j++)
        if(!isdigit(s[j]))
            return;

    now.setWeight(w);
    qDebug()<<"7:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();
    if(now.getTime_from()>now.getTime_to())
    {
        qDebug()<<"Time from>Time to";
        return;
    }
    if(to>=from)
    {
        qDebug()<<"Date to>=from";
    }
    else
        return;
    o.push_back(now);
    select_orders.push_back(QString::fromStdString(now.get_in_string()));
    qDebug()<<"FINAL:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();
}

void MainWindow::ReadCouriers(std::string s)

{
    //Example:[132332] {Belarus, Mogilev, blablabla, 54, 2} 24.01.2020 26.02.2022 1000 1400 228
    courier now;

    if(s[0]!='[')return;

    int n=s.size(),i=1;

    for(;i<n;i++)
    {
        if(s[i]==']')
            break;
    }
    if(i==n)return;

    now.setNumber(s.substr(1,i-1));
    qDebug()<<"1:"<<now.getNumber()<<" "<<now.getName()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.getMax_weight();
    i+=2;
    if(s[i]!='{')return;
    int j=i+1;

    for(;i<n;i++)
    {
        if(s[i]=='}')
            break;
    }
    if(i==n)return;

    now.setName(s.substr(j,i-j));
    qDebug()<<"2:"<<now.getNumber()<<" "<<now.getName()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.getMax_weight();
    i+=2;
    j=i;
    //qDebug()<<s[i];
    for(;i<n;i++)
    {
        if(s[i]==' ')
        {
            i--;
            break;
        }
    }
    //qDebug()<<i;
    if(i==n)return;
    int t=0;
    try
    {
        t=stoi(s.substr(j,i-j+1));
    }
    catch(...)
    {
        qDebug()<<"stoi catch error";
        return;
    }
    for(;j<=i;j++)
        if(!isdigit(s[j]))
            return;

    now.setTime_from(t);

    qDebug()<<"3:"<<now.getNumber()<<" "<<now.getName()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.getMax_weight();

    i+=2;
    j=i;
    for(;i<n;i++)
    {
        if(s[i]==' ')
        {
            i--;
            break;
        }
    }
    if(i==n)return;
    t=0;
    try
    {
        t=stoi(s.substr(j,i-j+1));
    }
    catch(...)
    {
        return;
    }
    for(;j<=i;j++)
        if(!isdigit(s[j]))
            return;

    now.setTime_to(t);
    qDebug()<<"4:"<<now.getNumber()<<" "<<now.getName()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.getMax_weight();
    i+=2;
    j=i;

    unsigned long long w=0;
    try
    {
        w=stoull(s.substr(j,n-j));
    }
    catch(...)
    {
        return;
    }
    for(;j<n;j++)
        if(!isdigit(s[j]))
            return;

    now.setMax_weight(w);
    qDebug()<<"5:"<<now.getNumber()<<" "<<now.getName()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.getMax_weight();
    if(now.getTime_from()>now.getTime_to())
    {
        qDebug()<<"Time from>Time to";
        return;
    }
    c.push_back(now);
    select_couriers.push_back(QString::fromStdString(now.get_in_string()));
    qDebug()<<"FINAL:"<<now.getNumber()<<" "<<now.getName()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.getMax_weight();
}

void MainWindow::FileSave()
{
    std::ofstream fout(file);
    fout<<orders_in_file<<couriers_in_file;
}

void MainWindow::on_SaveFileButton_clicked()
{
    std::string new_file="";
    QString filters("Data files (*.inf)");
    QString defaultFilter("Data files (*.inf)");
    new_file=(QFileDialog::getSaveFileName(this,"Save File","/home/dzmitry",filters,&defaultFilter)).toUtf8().constData();

    qDebug()<<"Save in "<<new_file;
    int n=new_file.size(),i=n-1;

    if(new_file=="")
        return;

    for(;n-i<=4;i--)
    {
        if(new_file[i]=='.')
        {
            if(new_file.substr(i,n-i)==".inf")
                break;
            return on_SaveFileButton_clicked();
        }
    }
    if(n-i>4)return;
    file=new_file;
    FileSave();
}

