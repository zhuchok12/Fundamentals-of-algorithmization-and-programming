#include "mainwindow.h"
#include "ui_mainwindow.h"

#define InputError QMessageBox::information(this,"Error", "Wrong format of array elements or you write nothing", QMessageBox::Ok);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //isFullScreen();
    //QWidget::setFixedSize(1850, 1050);

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::check(std::string s)
{
    long long n=s.size();
    bool have_digit=false;
    for(long long i=0;i<n;i++)
    {
        if(s[i]!=' '&&s[i]!='\n'&&!isdigit(s[i])&&s[i]!='-')
            return false;
        if(isdigit(s[i]))have_digit=true;
    }

    if(!have_digit)
        return false;

    for(long long i=0;i<n;i++)
    {
        if(isdigit(s[i])||s[i]=='-')
        {
            int j=i+1;
            int ch=0;
            while(isdigit(s[j])&&j<n)
            {
                j++;
            }
            j--;

            if(j==i&&s[j]=='-')
            {
                qDebug()<<"Bad number";
                delar();
                return false;
            }


            try
            {
                ch=stoi(s.substr(i,j-i+1));
            }
            catch(...)
            {
                qDebug()<<"Bad number";
                delar();
                return false;
            }

            if(ch>(int)1e9*2||ch<(int)1e9*(-2))
            {
                qDebug()<<"Bad number";
                delar();
                return false;
            }

            add(ch);
            //qDebug()<<"dsadasd";
            i=j+1;
        }
        //qDebug()<<"!"<<i;
    }

    return true;
}

void MainWindow::delar()
{
    siz=0;
    free(a);
    a=nullptr;
}

void MainWindow::add(int ch)
{
    a=(int *)realloc(a,(++siz)*sizeof(int));
    a[siz-1]=ch;
    qDebug()<<ch;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    //qDebug()<<"PAINTEVENT";
    g.draw(&p);
}

void MainWindow::on_sortButton_clicked()
{
    delar();

    std::string s=ui->ArrayText->toPlainText().toStdString();

    if(!check(s))
    {
        InputError;
        return;
    }

    g.set(a,siz);

    qDebug()<<"All good. Go to sort";

    qDebug()<<"[Type of sort]\nHeap:"<<ui->Heap->isChecked()<<"\nQuick:"<<ui->Quick->isChecked()<<"\nMerge:"<<ui->Merge->isChecked();

    if(ui->Heap->isChecked())
    {
        ui->speed->setText(QString::fromStdString(std::to_string(heapSort(a,siz))));
    }

    if(ui->Quick->isChecked())
    {

    }
    update();
}

//Heap sort
void MainWindow::heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
clock_t MainWindow::heapSort(int arr[], int n)
{
    double t1=clock();
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i=n-1; i>=0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    printArray(arr,n);
    return clock()-t1;
}

void MainWindow::printArray(int arr[], int n)
{
    //return;
    qDebug()<<"Print Array was started";
    std::string s;
    for(int i=0;i<n;i++)
    {
        s+=std::to_string(arr[i])+" ";
    }
    //qDebug()<<s;
    ui->sortarr->setText(QString::fromStdString(s));
    qDebug()<<"Print Array was finished";
}
