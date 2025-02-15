#include "headerLev2.h"
#include <cstring>



int SumOfNDigits(lli  N, int *steps)
{
    int  reminder,  result = 0;

    while(N > 0)
    {
        reminder = N % 10;
        N = N /10;
        result += reminder;
        (steps)?++(*steps ):0;
    }
    return result;
}
lli sumOfBuffDigits(ccp buffer, int *steps)
{
    lli result = 0;

    if (!buffer)
    {
        cerr << "Null pointer to buffer";
        return -1;
    }

    while (*buffer)
    {
        if (*buffer == '\'') {
            buffer++;  // Skip the separator and continue
            continue;
        }

        result += *buffer - '0'; // Convert character to digit
        if (steps) ++(*steps);   // Increment steps counter

        buffer++;  // Move to the next character
    }

    return result;
}
