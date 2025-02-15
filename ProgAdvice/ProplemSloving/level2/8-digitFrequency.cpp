#include "headerLev2.h"
#include <string>

ccp digitFreqInLLInt(lli N, int digit)
{
    int reminder  = 0, counter =0;
    static string  msg;

    if (N == 0 || (digit < 0 || digit > 9))
    {
        msg =  "invalid " ;
        (N == 0) ? msg.append(" Number") : "";
        (N == 0) ? msg.append(" Digit") : "";
        return msg.data();
    }

    while (N > 0) {
        reminder = N % 10;
        N = N / 10;
        (reminder == digit )? ++counter : 0;
    }
    msg = "Digit " + to_string(digit) + "  Frequency is " + to_string(counter) + " Time(s)";


    return  msg.data();
}