#ifndef ARRAY_H
#define ARRAY_H

#include "date.h"

class array
{
public:
    array();
    long long size();
    void push_back(Date a,int not_data_size);
    void pop_back();
    std::string get_string(long long ind);
    void clear();
    Date get(long long ind);
    void update(Date new_value,long long ind);
    int get_pos(long long ind);
private:
    void upd(int ind,int delta);
    long long array_size;
    Date *v;
    int *positions;
};

#endif // ARRAY_H
