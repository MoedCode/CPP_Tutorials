#include "headerLev2.h"
enum prmVal {NotPrime  , Prime};
prmVal isPrime( long long int N)
{
    int M = 0, i = 2;
    if (N <= 0)
    {
        cerr << "number cant be negative or zero ";
        return NotPrime ;
    }
    if (N == 1)  return prmVal::Prime ;
    if (N == 2)  return prmVal::NotPrime ;

     M = N/2;
     for (; i < M ; i++)
        if(M % i == 0)
            return NotPrime;
    return  Prime;
}

