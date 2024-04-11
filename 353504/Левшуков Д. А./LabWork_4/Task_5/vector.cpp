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

template<typename T>
template<typename... Types>
void vector<T>::emplace_back(Types... args){
    T t(std::forward<Types>(args)...);
    push_back(t);
}

template<typename T>
it::iterator<T> vector<T>::begin() const
{
    return it::iterator(_v);
}

template<typename T>
it::const_iterator<T> vector<T>::cbegin() const
{
    return it::const_iterator(_v);
}

template<typename T>
void vector<T>::insert(it::iterator<T> _pos, const T &value)
{
    it::iterator<T> it = vector::begin();
    size_t ind = 0;
    while (it != _pos)
    {
        ind++;
        it++;
    }
    if (_capacity <= _size + 1)
    {
        size_t new_capacity = _size + 5;
        T* new_v = new T[new_capacity];
        for (size_t i = 0; i < _size; ++i)
        {
            new (&new_v[i]) T(_v[i]);
            _v[i].~T();
        }
        delete[] _v;
        _v = new_v;
        _capacity = new_capacity;
    }
    it = vector::begin();
    for (int i = 0; i < ind; ++i)
    {
        it++;
    }
    size_t i;
    try
    {
        for (i = _size; i > ind; --i)
        {
            new (&_v[i]) T(_v[i - 1]);
            (_v + i - 1)->~T();
        }
        new (&*it) T(value);
        _size++;
    }
    catch (...)
    {
        vector::clear();
        throw;
    }
}

template<typename T>
vector<T> &vector<T>::operator=(const vector &other) {
    if (this != &other) {
        vector<T> temp(other);
        T* temp_v = temp._v;
        temp._v = _v;
        _v = temp_v;

        size_t temp_size = temp._size;
        temp._size = _size;
        _size = temp_size;

        size_t temp_capacity = temp._capacity;
        temp._capacity = _capacity;
        _capacity = temp_capacity;
    }
    return *this;
}

template<typename T>
it::iterator<T> vector<T>::end() const
{
    return it::iterator(_v+_size);
}

template<typename T>
void vector<T>::erase(it::iterator<T> it)
{
    size_t ind=0;
    for(auto i = begin();i!=it&&ind<_size;i++,ind++);
    try {
        for (size_t i = ind + 1; i < _size; ++i) {
            new (_v + i - 1) T(_v[i]);
            (_v + i)->~T();
        }
        _size--;
    } catch (...) {
        vector::clear();
        throw;
    }
}

template<typename T>
void vector<T>::erase(it::iterator<T> begin, it::iterator<T> end) {
    size_t count = end - begin;
    size_t ind = begin - vector::begin();
    for (size_t i = ind; i < _size; ++i) {
        _v[i - count] = std::move(_v[i]);
    }
    for (size_t i = _size - count; i < _size; ++i) {
        _v[i].~T();
    }
    _size -= count;
}

template<typename T>
it::iterator<T> vector<T>::rend() const
{
    return it::reverse_iterator<T>(_v-1);
}

template<typename T>
it::iterator<T> vector<T>::rbegin() const
{
    return it::reverse_iterator<T>(_v+_size-1);
}

template<typename T>
template<typename... Args>
void vector<T>::emplace(it::iterator<T> pos, Args &&...args) {
    pos.get()->~T();
    new (pos.get()) T(args...);
}

template<typename T>
void vector<T>::assign(size_t n, const T & v)
{
    clear();
    for(int i=0;i<n;i++)
        push_back(v);
}


template<typename T>
template<typename InputIterator>
void vector<T>::insert(const it::iterator<T> &pos, InputIterator beg, InputIterator end)
{
    auto other_beg=beg;
    size_t kol=0;
    while(other_beg!=end)
    {
        other_beg++;
        kol++;
    }
    it::iterator<T>it=vector::begin();
    size_t ind=0;
    while(it!=pos)
    {
        ind++;
        it++;
    }
    if(_size+kol>_capacity)//need add
    {
        size_t new_capacity=_size+kol+5;
        T* new_v=new T[new_capacity];
        for(size_t i=0;i<ind;i++)
        {
            new(&new_v[i]) T(_v[i]);
            _v[i].~T();
        }
        for(size_t i=0;other_beg!=end;i++)
        {
            new(&new_v[ind+i]) T(*(other_beg++));
        }
        for(size_t i=ind;i<_size;i++)
        {
            new (&new_v[kol + i]) T(_v[i]);
            _v[i].~T();
        }
        delete []_v;
        _v=new_v;
        _capacity=new_capacity;
    }else
    {
        for (size_t i = _size - 1 + kol; i > ind; --i) {
            new (&_v[i]) T(_v[i - kol]);
            (_v + i - kol)->~T();
        }
        other_beg = beg;
        for (size_t i = ind; other_beg != end; ++i) {
            new (_v + i) T(*(other_beg++));
        }
    }
    _size+=kol;
}
