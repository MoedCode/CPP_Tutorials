#include "headerLev2.h"

ccp LLIntDigitsFrequency(lli N)
{
    if(N == 0)
        return nullptr;
    int reminder;
    lli N_;
    static string msg;
    while (N_ > 0) {
        reminder = N_ % 10;
        N_ = N_ / 10;
        msg.append(digitFreqInLLInt(N, reminder) );
        msg.push_back('\n');
    }
    return msg.data();
}