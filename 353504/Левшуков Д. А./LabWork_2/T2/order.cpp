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

std::string order::get_in_string()
{
    std::string s;
    s="["+number + "] " + addres + " from "+date_from.get()+" to "+date_to.get()+" ("
        +get_time_from_in_string()+" - "+get_time_to_in_string()+") weight: "+std::to_string(get_weight());
    return s;
}

std::string order::get_time_to_in_string()
{
    short h=time_to/60,m=time_to%60;
    std::string s="";
    if(h<10)
        s+="0";
    s+=std::to_string(h);
    s+=":";
    if(m<10)
        s+="0";
    s+=std::to_string(m);
    return s;
}

std::string order::get_time_from_in_string()
{
    short h=time_from/60,m=time_from%60;
    std::string s="";
    if(h<10)
        s+="0";
    s+=std::to_string(h);
    s+=":";
    if(m<10)
        s+="0";
    s+=std::to_string(m);
    return s;
}


unsigned long long order::get_weight()
{
    return weight;
}

//Set functions
void order::setNumber(const std::string &newNumber)
{
    number = newNumber;
}

void order::setAddres(const std::string &newAddres)
{
    addres = newAddres;
}



void order::setDate_to(const Data &newDate_to)
{
    date_to = newDate_to;
}

void order::setDate_from(const Data &newDate_from)
{
    date_from = newDate_from;
}

void order::setWeight(unsigned long long newWeight)
{
    weight = newWeight;
}

short order::getTime_to() const
{
    return time_to;
}

void order::setTime_to(short newTime_to)
{
    time_to = newTime_to;
}

short order::getTime_from() const
{
    return time_from;
}

void order::setTime_from(short newTime_from)
{
    time_from = newTime_from;
}
