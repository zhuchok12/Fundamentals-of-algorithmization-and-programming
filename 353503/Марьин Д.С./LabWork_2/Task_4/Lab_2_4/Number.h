//
// Created by Daniil Mariyn on 10.03.24.
//

#ifndef SEM_2_LAB_2_3_NUMBER_H
#define SEM_2_LAB_2_3_NUMBER_H

#include "Expression.h"

class Number : public Expression
{
public:
    Number(double);
    double evaluate() override;
private:
    double value;
};


#endif//SEM_2_LAB_2_3_NUMBER_H
