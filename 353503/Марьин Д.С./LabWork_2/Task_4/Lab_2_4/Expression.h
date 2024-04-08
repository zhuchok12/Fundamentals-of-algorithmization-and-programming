#ifndef SEM_2_LAB_2_3_EXPRESSION_H
#define SEM_2_LAB_2_3_EXPRESSION_H


class Expression
{
public:
    virtual ~Expression(){};
    virtual double evaluate() = 0;
};


#endif//SEM_2_LAB_2_3_EXPRESSION_H
