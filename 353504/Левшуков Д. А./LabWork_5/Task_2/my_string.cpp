#include "my_string.h"

my_string::my_string()
{
    data_=nullptr;
    reserve(1);
    capacity_=0;
    size_=0;
}

my_string::my_string(const my_string &other)
{
    if(other.size_>capacity_)
        reserve(other.size_);
    for(int i=0;i<other.size_;i++)
        data_[i]=other.data_[i];
    size_=other.size_;
}

my_string::my_string(std::initializer_list<char>list): size_(list.size()),capacity_(list.size())
{
    data_ = std::make_unique<char[]>(size_);
    auto listIt = list.begin();

    int i=0;
    for (; i < size_; ++i, ++listIt)
    {
        data_[i] = *listIt;
    }
    data_[i] = '\0';
}

my_string::my_string(const char *other)
{
    int size=0;
    while(other[size++]!='\0');
    size=0;
    reserve(size);

    for (size_t i = 0; i < size; i++)
    {
        data_[i] = other[i];
    }
    size_ = size;

    data_[size_] = '\0';
}

char &my_string::operator[](int i)
{
    return data_[i];
}

my_string &my_string::operator=(const char * other)
{
    int size = 0;
    while (other[size++] != '\0');
    size--;

    reserve(size);

    for (int i = 0; i < size; i++)
    {
        data_[i] = other[i];
    }
    size_ = size;
    data_[size_] = '\0';
    return *this;
}

void my_string::reserve(int size)
{
    if(size<capacity_)
        return;

    auto tmp=std::make_unique<char[]>(size);
    for(int i=0;i<this->size_;i++)
        tmp[i]=data_[i];

    capacity_=size;
    data_ = std::move(tmp);
}

bool my_string::empty()
{
    return size_==0;
}

void my_string::resize(int size, char tmp)
{
    if (size > capacity_) reserve(size);

    //if(size_<size)
    for (int i = size_; i < size; i++)
    {
        data_[i] = tmp;
    }
    //else
    for (int i = size; i < size_; i++)
    {
        ~(data_[i]);
    }
    size_ = size;
}

void my_string::clear()
{
    resize(0);
}

int my_string::size() const
{
    return size_;
}

int my_string::capacity() const
{
    return capacity_;
}

char &my_string::front()
{
    return data_[0];
}

char &my_string::back()
{
    return data_[size_-1];
}

char &my_string::at(int i)
{
    if(i<=size_)
    {
        try
        {
            return data_[i];
        }
        catch (...)
        {
            throw;
        }
    }
    else throw;
}

char *my_string::data()
{
    return data_.get();
}

my_string::iterator my_string::begin()
{
    return iterator(data_.get());
}

my_string::rIterator my_string::rbegin()
{
    return rIterator(data_.get()+size_);
}

my_string::iterator my_string::end()
{
    return iterator(data_.get()+size_);
}

my_string::rIterator my_string::rend()
{
    return rIterator(data_.get());
}

void my_string::swap(my_string &b)
{
    std::swap(b.size_,size_);
    std::swap(b.capacity_,capacity_);
    std::swap(b.data_,data_);
}

void my_string::push_back(char a)
{
    reserve(size_+2);
    size_++;

    data_[size_-1]=a;
    data_[size_]=0;
}

void my_string::insert(cIterator pos, const char & tmp)
{
    int ind = pos.base() - data_.get();

    reserve(size_ + 2);

    for (size_t i = size_; i > ind; i--)
    {
        data_[i] = data_[i - 1];
    }

    data_[ind] = tmp;
    size_++;
}

void my_string::insert(cIterator pos, char && tmp)
{
    int ind = pos.base() - data_.get();

    reserve(size_ + 2);

    for (size_t i = size_; i > ind; i--)
    {
        data_[i] = data_[i - 1];
    }

    data_[ind] = tmp;
    size_++;
}

void my_string::erase(iterator pos)
{
    erase(pos,end());
}

void my_string::erase(iterator f , iterator s)
{
    int i = f.base() - data_.get();
    int j = s.base() - data_.get();

    for (auto it = i; it <= j; it++)
    {
        data_[it] = data_[it + 1];
    }

    size_ = size_ - (j - i);
}

void my_string::assign(int n, char c)
{
    clear();
    resize(n, c);
}

void my_string::assign(cIterator f, cIterator s)
{
    clear();
    int size = f.base() - s.base();
    resize(size);
    for (auto it = 0; it < size; it++)
    {
        data_[it] = *(f + it);
    }
}

void my_string::pop_back()
{
    ~(data_[size_ - 1]);
    size_--;
}

void *my_string::memcpy(void *s1, const void *s2, size_t n)
{
    if (s1 == nullptr)
    {
        return s1;
    }

    char* cs1 = (char*)s1;
    char* cs2 = (char*)s2;
    for(int i = 0; i < n; ++i)
    {
        cs1[i] = cs2[i];
    }

    return s1;
}

void *my_string::memmove(void *s1, const void *s2, size_t n)
{
    char* cs1 = (char*)s1;
    char* cs2 = (char*)s2;
    char* tmp = new char[n];
    for(int i = 0; i < n; ++i)
    {
        tmp[i] = cs2[i];
    }
    for(int i = 0; i < n; ++i)
    {
        cs1[i] = tmp[i];
    }
    delete [] tmp;
    return s1;
}

char *my_string::strcpy(char *s1, const char *s2)
{
    int i=0;

    while(s2[i]!='0')
    {
        s1[i]=s2[i];
        i++;
    }

    s1[i]=0;

    return s1;
}

char *my_string::strncpy(char *s1, const char *s2, size_t n)
{
    int i=0;
    while(n--&&s2[i]!=0)
    {
        s1[i]=s2[i];
        i++;
    }
    while(n--)
    {
        s1[i]=0;
        i++;
    }

    s1[i]=0;

    return s1;
}

char *my_string::strcat(char *s1, const char *s2)
{
    int ind=s1.size();

    while (s2[ind-s1.size()]!='\0')
    {
        s1[ind] = s2[ind-s1.size()];
        ind++;
    }
    s1[ind] = '\0';
    return s1;
}

char *my_string::strncat(char *s1, const char *s2, size_t n)
{
    int ind=s1.size();

    while (s2[ind-s1.size()]!='\0'&&n--)
    {
        s1[ind] = s2[ind-s1.size()];
        ind++;
    }
    while(n--)
        s1[ind++]=0;
    s1[ind] = '\0';
    return s1;
}

template<typename... Args>
void my_string::emplace(cIterator pos, Args &&... args)
{
    char tmp(args...);
    insert(pos, tmp);
}

template<typename... Args>
void my_string::emplace_back(Args &&... args)
{
    char tmp(args...);
    push_back(tmp);
}
