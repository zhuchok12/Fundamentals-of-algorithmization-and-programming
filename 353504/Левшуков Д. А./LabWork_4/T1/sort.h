#ifndef SORT_H
#define SORT_H

#include <QApplication>
#include <ctime>

class Sort
{
public:
    Sort(long long *a, long long n);

    //void quicksort();
    //void mergesort();
    void heap_sort();

    void sw(long long &, long long &);

    long double getHeapsort_speed() const;

private:
    void heapify(long long v);
    long long *a=nullptr;
    long long n;
    long double heapsort_speed,quicksort_speed,mergesort_speed;
    long long heap_size;

};

#endif // SORT_H
