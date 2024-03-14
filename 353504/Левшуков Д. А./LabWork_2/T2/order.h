#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "data.h"
class order
{
public:
    order();
    //Get functions
    std::string get_number();
    std::string get_addres();
    std::string get_date_to();
    std::string get_date_from();
    std::string get_time_to();
    std::string get_time_from();
    unsigned long long get_weight();
private:
    std::string number,addres,time_to,time_from;
    Data date_to,date_from;
    unsigned long long weight;
};

#endif // ORDER_H
