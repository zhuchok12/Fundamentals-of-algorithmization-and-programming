#include "dyarray_data.h"
#include <iostream>


dyarray::dyarray()
{
    array_size=0;
    v=nullptr;
}

long long dyarray::size()
{
    return array_size;
}

void dyarray::push_back(Date a)
{
    if(a.get_day()==-8888)return;
    v=(Date *)realloc(v,(++array_size)*sizeof(Date));
    v[array_size-1]=a;
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

