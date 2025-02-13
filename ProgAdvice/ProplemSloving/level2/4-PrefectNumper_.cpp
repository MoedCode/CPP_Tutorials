#include "headerLev2.h"
int   isPerfect_(LLI N, int print)
{
    int Sum = 0;
    for (int i = 1; i < N; i++)
        if (N % i == 0)
            Sum += i;
    if (N == Sum && print)
        cout << N << " Is Perfect Number.\n";
    else if(print)
        cout << N << " Is NOT Perfect Number.\n";
    return N == Sum;
}

// int main()
// {
//     PrintPerfectNumbersFrom1ToN(getUInt("Please enter positive number?"));
//     return 0;
// }