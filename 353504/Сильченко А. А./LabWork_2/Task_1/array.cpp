#include "array.h"
#include <iostream>


array::array()
{
    array_size=0;
    v=nullptr;
    positions=nullptr;
}


long long array::size()
{
    return array_size;
}


void array::push_back(Date a, int pos)
{
    if(a.get_day()==-8888)return;
    v=(Date *)realloc(v,(++array_size)*sizeof(Date));
    positions=(int *)realloc(positions,(array_size)*sizeof(int));
    v[array_size-1]=a;

    positions[array_size-1]=pos;
    //qDebug()<<"In push_back "<<a.get_year()<<" "<<v[array_size-1].get_year();
}


void array::pop_back()
{
    v=(Date *)realloc(v,(--array_size)*sizeof(Date));
}


std::string array::get_string(long long ind)
{
    return v[ind].get_date();
}


Date array::get(long long ind)
{
    return v[ind];
}


int array::get_pos(long long ind)
{
    if(ind>=array_size||ind<0)return (int)-1;
    return positions[ind];
}

void array::upd(int ind, int delta)
{
    if(ind==array_size)return;
    positions[ind]+=delta;
    upd(ind+1,delta);
}


void array::update(Date new_value, long long ind)
{
    int old_size=v[ind].get_date().size();
    v[ind]=new_value;
    int new_size=v[ind].get_date().size();
    upd(ind,new_size-old_size);
}


void array::clear()
{
    free(v);
    v=nullptr;
    array_size=0;
}
