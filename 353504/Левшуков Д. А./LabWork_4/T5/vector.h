#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<limits>

template<typename T>
class vector
{
    T* _v;
    long long _size,_capacity;

public:
    vector();//+
    ~vector();//+
    void assign();
    T& at(int);//+
    long long capacity();//+
    void clear();//+
    T& back();//+
    T* data();//+
    bool empty();//+
    T& front();//+
    void swap(vector<T>&);//+
    long long size();//+
    void resize(long long);//+
    void reserve(long long);//+
    void push_back(const T& a);//+
    void pop_back();//+
    long long max_size();//?
    void insert();//?
    void emplace_back();//?
};

#endif // VECTOR_H
