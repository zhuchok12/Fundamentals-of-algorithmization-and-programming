#include "func.h"

double func::recurs( int n)
{
        if (n == 0)
            return 0;
        else
            return (n % 2) + 10 * recurs(n / 2);
}
