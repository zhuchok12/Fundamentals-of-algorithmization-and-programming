#include "vector.h"

template<typename T>
vector<T>::vector()
{
    _v=(T*)malloc(sizeof(T));
    _size=0;
    _capacity=1;
}

template<typename T>
vector<T>::~vector()
{
    if(_v!=nullptr)
    {
        for(int i=0;i<_size;i++)
            _v[i]->~T();
    }
    _v=nullptr;
    _size=_capacity=0;
}

template<typename T>
T &vector<T>::at(int i)
{
    if(i>=_size)
        throw std::out_of_range("index out of range");
    return _v[i];
}

template<typename T>
long long vector<T>::capacity()
{
    return _capacity;
}

template<typename T>
void vector<T>::clear()
{
    for(int i=0;i<_size;i++)
        _v[i]->~T();
    _size=0;
}

template<typename T>
T &vector<T>::back()
{
    return _v[_size-1];
}

template<typename T>
T *vector<T>::data()
{
    return &_v[0];
}

template<typename T>
bool vector<T>::empty()
{
    return _size==0;
}

template<typename T>
T &vector<T>::front()
{
    return _v[0];
}

template<typename T>
void vector<T>::swap(vector<T> &b)
{
    T* temp=_v;
    _v=b._v;
    b._v=temp;

    //size
    _size^=b._size;
    b._size^=_size;
    _size^=b._size;

    //capacity
    _capacity^=b._capacity;
    b._capacity^=_capacity;
    _capacity^=b._capacity;
}

template<typename T>
long long vector<T>::size()
{
    return _size;
}

template<typename T>
void vector<T>::resize(long long n)
{
    if(n==_size)return;
    if(n<_size)
    {
        for(;n<_size;n++)
            _v[n]->~T();
    }
    else
    {
        if(n>_capacity)
        {
            _v=(T*)realloc(_v,sizeof(T)*n);
            _capacity=n;
        }
            for(;_size<n;_size++)
                _v[_size]=0;
    }
}

template<typename T>
void vector<T>::reserve(long long size)
{
    if(size<=_capacity)return;
    _v=(T*)realloc(_v,sizeof(T)*size);
    for(;_size<size;_size++)
        _v[_size]=0;
    _capacity=_size;
    //for(int i=0;i)
}

template<typename T>
void vector<T>::push_back(const T &a)
{
    if(++_size>_capacity)
    {
        reserve(_size+1);
    }
    _v[_size-1]=a;
}

template<typename T>
void vector<T>::pop_back()
{
    if(_size==0)return;

    _v[--_size].~T();
}

template<typename T>
long long vector<T>::max_size()
{
    return std::numeric_limits<T>::max()/sizeof(T);
}
