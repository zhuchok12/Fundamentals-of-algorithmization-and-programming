#ifndef COURIER_H
#define COURIER_H

#include<string>

class courier
{
public:
    courier();
    //Get functions
    std::string get_number();
    std::string get_name();
    std::string get_time_to();
    std::string get_time_from();
    unsigned long long get_max_weight();
private:
    std::string number,name,time_to,time_from;
    unsigned long long max_weight;
};

#endif // COURIER_H
