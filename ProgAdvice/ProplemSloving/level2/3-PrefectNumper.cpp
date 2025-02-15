#include "headerLev2.h"
int   isPerfect(lli N)
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
// int main()
// {
//     PrintPerfectNumbersFrom1ToN(getUInt("Please enter positive number?"));
//     return 0;
// }