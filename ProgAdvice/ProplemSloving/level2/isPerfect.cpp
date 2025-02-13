#include "header.h"
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

int   isPerfect(LLI N)
{
    int Sum = 0;
    for (int i = 1; i < N; i++)
        if (N % i == 0)
            Sum += i;
    return N == Sum;
}
int PrintPerfectNumbersFrom1ToN(int Number)
{
    int i = 1;
    for (int i = 1; i <= Number; i++)
        if (isPerfect(i))
            cout << i << endl;
    return i;
}
int main()
{
PrintPerfectNumbersFrom1ToN(getUInt("Please enter a positive number?"));
return 0;
}