#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <limits>
#include "iterator.h"
#include <stdexcept>

template<typename T>
class vector
{
    T* _v;
    long long _size,_capacity;

public:
    vector();//+
    ~vector();//+
    void assign(size_t, const T&);

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
    it::iterator<T> begin()const;
    it::const_iterator<T> cbegin()const;
    template<typename... Types>
    void emplace_back(Types... args);
    template<class... Args>
    void emplace(it::iterator<T>, Args &&...);
    void insert(it::iterator<T>, const T& value);
    template<typename InputIterator>
    void insert(const it::iterator<T>&, InputIterator, InputIterator);
    vector<T>& operator=(const vector& other);
    it::iterator<T> end()const;
    void erase(it::iterator<T>);
    void erase(it::iterator<T>, it::iterator<T>);
    it::iterator<T> rend()const;
    it::iterator<T> rbegin()const;
};

#endif // VECTOR_H
