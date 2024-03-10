#include "dyarray_data.h"
#include <iostream>


dyarray::dyarray()
{
    array_size=0;
    v=nullptr;
    positions=nullptr;
}

long long dyarray::size()
{
    return array_size;
}

void dyarray::push_back(Date a, int not_data_size)
{
    if(a.get_day()==-8888)return;
    v=(Date *)realloc(v,(++array_size)*sizeof(Date));
    positions=(int *)realloc(positions,(1+array_size)*sizeof(int));
    positions[array_size]=0;
    v[array_size-1]=a;

    if(array_size>1)
    {
        positions[array_size-1]+=not_data_size;
        positions[array_size-1]+=positions[array_size-2];
        positions[array_size]+=a.get_date().size();
    }
    else positions[array_size-1]=not_data_size,positions[array_size]+=a.get_date().size();

    //qDebug()<<"In push_back "<<a.get_year()<<" "<<v[array_size-1].get_year();
}

void dyarray::pop_back()
{
    v=(Date *)realloc(v,(--array_size)*sizeof(Date));
}

std::string dyarray::get_string(long long ind)
{
    return v[ind].get_date();
}


Date dyarray::get(long long ind)
{
    return v[ind];
}


int dyarray::get_pos(long long ind)
{
    return positions[ind];
}

void dyarray::update(Date new_value, long long ind)
{
    v[ind]=new_value;
}
void dyarray::clear()
{
    free(v);
    v=nullptr;
    array_size=0;
}

