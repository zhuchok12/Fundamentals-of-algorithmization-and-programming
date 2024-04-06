#ifndef ITERATOR_H
#define ITERATOR_H

namespace it{

template<class T>
class const_iterator{
    const T* it;
public:
    const_iterator();

    const_iterator(T* it);

    const T *operator->();

    bool operator !=(const const_iterator<T>&b);

    const_iterator &operator = (const const_iterator &b)
    {
        it = b.it;
        return *this;
    }
    const T &operator*()
    {
        return *it;
    }

    const T*get();

};

template<class T>
class iterator:public const_iterator<T>{
protected:
    T* it;
public:
    iterator();

    iterator(const iterator <T>& it);

    iterator(T *iter);

    T *operator->();

    virtual bool operator !=(iterator b);

    bool operator ==(iterator b);

    iterator &operator=(const iterator &b);

    iterator &operator=(const iterator *b);

    T&operator*();

    T *get();
};

template<class T>
class reverse_iterator:public iterator<T>{
protected:
    T* it;
public:
    reverse_iterator()
    {
        it=nullptr;
    }

    reverse_iterator(const iterator <T>& it);


    reverse_iterator(T *iter);

    T *operator->();

    virtual bool operator !=(reverse_iterator b);

    bool operator ==(reverse_iterator b);

    reverse_iterator &operator=(const reverse_iterator &b)
    {
        it = b.it;
        return *this;
    }

    reverse_iterator &operator=(const reverse_iterator *b)
    {
        it = b->it;
        return *this;
    }

    T&operator*();

    T *get();
};


}

#endif // ITERATOR_H
