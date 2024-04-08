#include <iostream>
#include "Expression.h"
#include "BinaryOperation.h"
#include "Number.h"
bool check_equals(Expression const *left, Expression const *right)
{
    return *(void**)left == *(void**)right;
}

int main()
{
    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression *expr = new BinaryOperation(new Number(3.3), '+', sube);
    std::cout << expr->evaluate() << "\n";
    Expression *ev = new BinaryOperation(expr, '-', sube);
    std::cout << ev->evaluate() << "\n";
    std::cout << check_equals(new Number(0),expr);
    return 0;
}
