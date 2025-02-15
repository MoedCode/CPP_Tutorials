#include "headerLev2.h"
ccp numberPattern(lli N, int inverted)
{
    int reminder;
    static string msg;
    msg.clear();
    if (!inverted)
        N = reversIntDigits(N);
    while(N > 0)
    {
        reminder = N % 10;
        N = N / 10;
        for (int i = 0; i < reminder; i++)
            msg.push_back(reminder + '0');
        // if (reminder == 0)msg.push_back('0');
        msg.push_back(10 );
    }
    return msg.data();
}