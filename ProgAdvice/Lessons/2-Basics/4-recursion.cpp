#include  "header_b.h"
int i=0 ;


int accumulatedNumber(int N, int M, int accumulatedSum = 0)
{
    if (N <= M)
    {
        // Add the current value of N to the accumulated sum
        accumulatedSum += N;
        // Recurse with the next value of N and the updated accumulated sum
        return accumulatedNumber(N + 1, M, accumulatedSum);
    }
    else
    {
        // Base case: return the accumulated sum
        return accumulatedSum;
    }
}

int ascPrintNum(int n1, int n2)
{
    static int  acc_n1 = 0;
    if(n1 <= n2)
        {
            acc_n1 += n1;
            cout << n1 <<", ";
            ascPrintNum(++n1, n2);
            }
        cout << endl;
    return acc_n1;
}
int desPrintNum(int n1, int n2)
{
    static int  acc_n2 = 0;
    if(n1 <= n2)
        {
            acc_n2 += n2;
            cout << n2 << ", ";
            desPrintNum(n1, --n2);
        }
        cout << endl;
    return acc_n2;
}
int power(int base, int pow)
{
    int i = 0, result = 1;

    if (base == 0 || base == 1 ||  pow == 1)
        return base;

    if ( pow == 0)
        return result;
    for (; i < pow; i++)
        result *= base ;
    return result;
}