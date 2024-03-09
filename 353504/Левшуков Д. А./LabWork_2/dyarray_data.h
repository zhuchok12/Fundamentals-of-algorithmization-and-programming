#ifndef DYARRAY_DATA_H
#define DYARRAY_DATA_H
#include "data.h"

class dyarray
{
public:
    dyarray();
    long long size();
    void push_back(Date a);
    void pop_back();
    std::string get_string(long long ind);
    void clear();
    Date get(long long ind);
    void update(Date new_value,long long ind);
private:
    long long array_size;
    Date *v;
};

#endif // DYARRAY_DATA_H
