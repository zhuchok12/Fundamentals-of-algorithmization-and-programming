#include "sort.h"

//default construcotrs
Sort::Sort(int *a, long long n)
{
    this->a=a;
    this->n=n;
    heap_size=n;
}

//Heap sort
void Sort::heap_sort()
{
    heapsort_speed=clock();
    for(long long i=n/2;i>=1;i--)
    {
        heapify(i);
    }

    /*
    We now that element in root - max element of our array therefore lets get array [1,n-i]. Then in the end every step we will
    have step sorted elements
    */
    for(long long i=n;i>=1;i--)
    {
        sw(a[i],a[0]);
        heapify(0);
        heap_size--;
    }
    heapsort_speed=heapsort_speed - clock();
    heap_size=n;//Reset size to good
}

void Sort::heapify(long long v) //Function for build heap (log n)
{
    long long max=v;

    for(long long i=0;i<=1;i++)
    {
        if(v*2+i<=heap_size&&a[v*2+i]>a[max])
            max=v*2+i;
    }

    //swap and go down
    if(max!=v)
    {
        sw(a[max],a[v]);
        heapify(max);
    }

    /*
            1
         5     9
       2  6  7  0
   */
}

long double Sort::getHeapsort_speed() const
{
    return heapsort_speed;
}

void Sort::sw(int &f,int &s)
{
    qDebug()<<"-=SWAP=-\n"<<f<<" "<<s;
    f^=s;
    s^=f;
    f^=s;
    qDebug()<<f<<" "<<s;
    qDebug()<<"-=SWAP=-\n";
}
//Quick sort

//Merge sort
