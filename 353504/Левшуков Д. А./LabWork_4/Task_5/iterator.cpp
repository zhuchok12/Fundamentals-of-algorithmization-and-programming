#include "iterator.h"



template<class T>
it::const_iterator<T>::const_iterator()
{
    it=nullptr;
}

template<class T>
it::const_iterator<T>::const_iterator(T *it)
{
    this->it=it;
}

template<class T>
const T *it::const_iterator<T>::operator->() {
    return it;
}

template<class T>
bool it::const_iterator<T>::operator !=(const const_iterator<T> &b){
    return it!=b.it;
}



template<class T>
const T *it::const_iterator<T>::get(){
    return it;
}


template<class T>
it::iterator<T>::iterator()
{
    it=nullptr;
}

template<class T>
it::iterator<T>::iterator(const iterator<T> &b)
{
    this->it=b.it;
}



template<class T>
it::reverse_iterator<T>::reverse_iterator(const iterator<T> &it)
{
    this->it=it.it;
}

template<class T>
it::reverse_iterator<T>::reverse_iterator(T *iter)
{
    it=iter;
}

template<class T>
T *it::reverse_iterator<T>::operator->()
{
    return it;
}

template<class T>
bool it::reverse_iterator<T>::operator !=(reverse_iterator b)
{
    return this->it != b.it;
}

template<class T>
bool it::reverse_iterator<T>::operator ==(reverse_iterator b)
{
                return this->it == b.it;
}


template<class T>
T &it::reverse_iterator<T>::operator*()
{
    return *it;
}

template<class T>
T *it::reverse_iterator<T>::get()
{
    return it;
}
