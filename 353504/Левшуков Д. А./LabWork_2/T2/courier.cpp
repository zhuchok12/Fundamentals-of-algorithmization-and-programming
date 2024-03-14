#include "courier.h"

courier::courier() {}

//Get functions
std::string courier::get_number()
{
    return number;
}

std::string courier::get_name()
{
    return name;
}

std::string courier::get_time_to()
{
    return time_to;
}

std::string courier::get_time_from()
{
    return time_from;
}

unsigned long long courier::get_max_weight()
{
    return max_weight;
}
