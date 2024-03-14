#include "order.h"

order::order()
{

}



//Get functions
std::string order::get_number()
{
    return number;
}

std::string order::get_addres()
{
    return addres;
}

std::string order::get_date_to()
{
    return date_to.get();
}

std::string order::get_date_from()
{
    return date_from.get();
}

std::string order::get_time_to()
{
    return time_to;
}

std::string order::get_time_from()
{
    return time_from;
}

unsigned long long order::get_weight()
{
    return weight;
}
