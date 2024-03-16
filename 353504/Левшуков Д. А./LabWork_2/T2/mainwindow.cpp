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
    ui->FileBrowser->setText(QString::fromStdString(file));
    FileRead();
}

void MainWindow::FileRead()
{
    std::ifstream fin(file);
    std::string s;
    std::getline(fin,s);
    if(s!=orders_head)
    {
        //Bad file
        qDebug()<<"Bad file";
        return;
    }

    Clear();
    orders_in_file="";

    while(s!=couriers_head&&std::getline(fin,s))//Orders read
    {
        if(s==couriers_head)break;
        orders_in_file+=s+'\n';
        qDebug()<<s;
        if(ReadOrders(s))
            order_position_in_file.push_back({orders_in_file.size()-s.size()-1,s.size()+1});

    }
    ui->OrderNumberSelect->addItems(select_orders);
    couriers_in_file="";

    while(std::getline(fin,s))
    {
        qDebug()<<s;
        couriers_in_file+=s+'\n';
        if(ReadCouriers(s))
            courier_position_in_file.push_back({couriers_in_file.size()-s.size()-1,s.size()+1});
    }
    ui->CourierNumberSelect->addItems(select_couriers);
    //std::ofstream fout(file);
    //fin<<1;
}

bool MainWindow::ReadOrders(std::string s)
{
    //Example:[132332] {Belarus, Mogilev, blablabla, 54, 2} 24.01.2020 26.02.2022 1000 1400 228
    order now;
    Data from,to;

    if(s[0]!='[')return false;

    int n=s.size(),i=1;

    for(;i<n;i++)
    {
        if(s[i]==']')
            break;
    }
    if(i==n)return false;

    now.setNumber(s.substr(1,i-1));
    //qDebug()<<"1:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();
    i+=2;
    if(s[i]!='{')return false;
    int j=i+1;

    for(;i<n;i++)
    {
        if(s[i]=='}')
            break;
    }
    if(i==n)return false;

    now.setAddres(s.substr(j,i-j));
    //qDebug()<<"2:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();

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
    if(i==n)return false;
    //qDebug()<<"Try init:"<<s.substr(j,i-j+1);
    if(from.Init(s.substr(j,i-j+1)))
    {
        now.setDate_from(from);
    }
    else
        return false;
    //qDebug()<<"3:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();

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
    if(i==n)return false;

    if(to.Init(s.substr(j,i-j+1)))
    {
        now.setDate_to(to);
    }
    else
        return false;
    //qDebug()<<"4:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();

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
    if(i==n)return false;
    int t=0;
    try
    {
        t=stoi(s.substr(j,i-j+1));
    }
    catch(...)
    {
        qDebug()<<"stoi catch error";
        return false;
    }
    for(;j<=i;j++)
        if(!isdigit(s[j]))
            return false;

    now.setTime_from(t);

    //qDebug()<<"5:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();

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
    if(i==n)return false;
    t=0;
    try
    {
        t=stoi(s.substr(j,i-j+1));
    }
    catch(...)
    {
        return false;
    }
    for(;j<=i;j++)
        if(!isdigit(s[j]))
            return false;

    now.setTime_to(t);
    //qDebug()<<"6:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();
    i+=2;
    j=i;

    unsigned long long w=0;
    try
    {
        w=stoull(s.substr(j,n-j));
    }
    catch(...)
    {
        return false;
    }
    for(;j<n;j++)
        if(!isdigit(s[j]))
            return false;

    now.setWeight(w);
    //qDebug()<<"7:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();
    if(to>=from)
    {
        qDebug()<<"Date to>=from";
    }
    else
        return false;
    if(now.getTime_to()>=now.getTime_from()&&to==from)
    {
        qDebug()<<"Time to>=from";
    }
    else if(to==from)
        return false;
    o.push_back(now);
    select_orders.push_back(QString::fromStdString(now.get_in_string()));
    qDebug()<<"FINAL:"<<now.get_number()<<" "<<now.get_addres()<<" "<<now.get_date_from()<<" "<<now.get_date_to()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.get_weight();
    return true;
}

bool MainWindow::ReadCouriers(std::string s)

{
    //Example:[132332] {Belarus, Mogilev, blablabla, 54, 2} 24.01.2020 26.02.2022 1000 1400 228
    courier now;

    if(s[0]!='[')return false;

    int n=s.size(),i=1;

    for(;i<n;i++)
    {
        if(s[i]==']')
            break;
    }
    if(i==n)return false;

    now.setNumber(s.substr(1,i-1));
    //qDebug()<<"1:"<<now.getNumber()<<" "<<now.getName()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.getMax_weight();
    i+=2;
    if(s[i]!='{')return false;
    int j=i+1;

    for(;i<n;i++)
    {
        if(s[i]=='}')
            break;
    }
    if(i==n)return false;

    now.setName(s.substr(j,i-j));
    //qDebug()<<"2:"<<now.getNumber()<<" "<<now.getName()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.getMax_weight();
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
    if(i==n)return false;
    int t=0;
    try
    {
        t=stoi(s.substr(j,i-j+1));
    }
    catch(...)
    {
        qDebug()<<"stoi catch error";
        return false;
    }
    for(;j<=i;j++)
        if(!isdigit(s[j]))
            return false;

    now.setTime_from(t);

    //qDebug()<<"3:"<<now.getNumber()<<" "<<now.getName()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.getMax_weight();

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
    if(i==n)return false;
    t=0;
    try
    {
        t=stoi(s.substr(j,i-j+1));
    }
    catch(...)
    {
        return false;
    }
    for(;j<=i;j++)
        if(!isdigit(s[j]))
            return false;

    now.setTime_to(t);
    //qDebug()<<"4:"<<now.getNumber()<<" "<<now.getName()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.getMax_weight();
    i+=2;
    j=i;

    unsigned long long w=0;
    try
    {
        w=stoull(s.substr(j,n-j));
    }
    catch(...)
    {
        return false;
    }
    for(;j<n;j++)
        if(!isdigit(s[j]))
            return false;

    now.setMax_weight(w);
    //qDebug()<<"5:"<<now.getNumber()<<" "<<now.getName()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.getMax_weight();
    if(now.getTime_from()>now.getTime_to())
    {
        qDebug()<<"Time from>Time to";
        return false;
    }
    c.push_back(now);
    select_couriers.push_back(QString::fromStdString(now.get_in_string()));
    qDebug()<<"FINAL:"<<now.getNumber()<<" "<<now.getName()<<" "<<now.getTime_from()<<" "<<now.getTime_to()<<" "<<now.getMax_weight();
    return true;
}

void MainWindow::FileSave()
{
    std::ofstream fout(file);
    fout<<orders_head<<'\n'<<orders_in_file<<couriers_head<<'\n'<<couriers_in_file;
}

void MainWindow::Clear()
{
    select_orders.clear();
    select_couriers.clear();
    ui->CourierNumberSelect->clear();
    ui->OrderNumberSelect->clear();
    order_position_in_file.clear();
    courier_position_in_file.clear();
    o.clear();
    c.clear();
}

void MainWindow::FileUpdate(long long pos)
{
    FILE *f=fopen(file.c_str(),"r+");

    qDebug()<<"{UPDATE}";
     fseek(f,pos,SEEK_SET);
    pos-=2;
    if(pos>orders_in_file.size())
    {

        qDebug()<<couriers_in_file;
        qDebug()<<pos-orders_in_file.size()<<" "<<couriers_in_file.substr(pos-orders_in_file.size()-couriers_head.size()-orders_head.size());
        fwrite(couriers_in_file.substr(pos-orders_in_file.size()-couriers_head.size()-orders_head.size()).c_str(),sizeof(char),
               sizeof(char)*couriers_in_file.substr(pos-orders_in_file.size()-couriers_head.size()-orders_head.size()).size(),f);
    }
    else
    {
        pos-=(-1+orders_head.size());
        std::string s=orders_in_file.substr(pos)+couriers_head+'\n'+couriers_in_file;
        qDebug()<<s;
        fwrite(s.c_str(),sizeof(char),sizeof(char)*s.size(),f);
    }

    fclose(f);

}

void MainWindow::on_SaveFileButton_clicked()
{
    std::string new_file="";
    QString filters("Data files (*.inf)");
    QString defaultFilter("Data files (*.inf)");
    new_file=(QFileDialog::getSaveFileName(this,"Save File",QString::fromStdString(file),filters,&defaultFilter)).toUtf8().constData();

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
    ui->FileBrowser->setText(QString::fromStdString(file));
    FileSave();
}


void MainWindow::on_DeleteCourierButton_clicked()
{
    std::string s=ui->CourierNumberSelect->currentText().toUtf8().constData();
    qDebug()<<"Try to delete:"<<s;
    int n=c.size(),i=0;
    for(;i<n;i++)
    {
        //qDebug()<<c[i].get_in_string();
        if(c[i].get_in_string()==s)break;
    }
    if(i==n)return;
    qDebug()<<"Delete ["<<i<<"]";

    c.erase(c.begin()+i,c.begin()+1+i);

    select_couriers.erase(select_couriers.begin()+i,select_couriers.begin()+i+1);

    std::string u((size_t)courier_position_in_file[i].second,' ');
    u.back()='\n';
    //qDebug()<<"Space string:"<<u;
    qDebug()<<courier_position_in_file[i].first<<" "<<courier_position_in_file[i].second;
    couriers_in_file.erase(courier_position_in_file[i].first,courier_position_in_file[i].second);
    couriers_in_file+=u;
    //qDebug()<<"UPD COURIER IN FILE:"<<couriers_in_file;
    FileUpdate(couriers_head.size()+orders_head.size()+orders_in_file.size()+courier_position_in_file[i].first+2);

    int j=i;
    for(;i<courier_position_in_file.size();i++)
        courier_position_in_file[i].first-=(courier_position_in_file[j].second);
    courier_position_in_file.erase(courier_position_in_file.begin()+j,courier_position_in_file.begin()+1+j);
    ui->CourierNumberSelect->removeItem(j);
    //couriers_in_file.erase(i,1);
}


void MainWindow::on_DeleteOrderButton_clicked()
{
    std::string s=ui->OrderNumberSelect->currentText().toUtf8().constData();
    qDebug()<<"Try to delete:"<<s;
    int n=o.size(),i=0;
    for(;i<n;i++)
    {
        //qDebug()<<c[i].get_in_string();
        if(o[i].get_in_string()==s)break;
    }
    if(i==n)return;
    qDebug()<<"Delete ["<<i<<"]";

    o.erase(o.begin()+i,o.begin()+1+i);

    select_orders.erase(select_orders.begin()+i,select_orders.begin()+i+1);

    std::string u((size_t)order_position_in_file[i].second,' ');
    u.back()='\n';
    //qDebug()<<"Space string:"<<u;
    qDebug()<<order_position_in_file[i].first<<" "<<order_position_in_file[i].second;
    orders_in_file.erase(order_position_in_file[i].first,order_position_in_file[i].second);
    orders_in_file+=u;
    //qDebug()<<"UPD order IN FILE:"<<orders_in_file;
    FileUpdate(orders_head.size()+order_position_in_file[i].first+1);

    int j=i;
    for(;i<order_position_in_file.size();i++)
        order_position_in_file[i].first-=(order_position_in_file[j].second);
    order_position_in_file.erase(order_position_in_file.begin()+j,order_position_in_file.begin()+1+j);
    ui->OrderNumberSelect->removeItem(j);
    //couriers_in_file.erase(i,1);
}

