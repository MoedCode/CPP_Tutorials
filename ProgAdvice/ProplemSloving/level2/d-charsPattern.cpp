#include "headerLev2.h"

ccp charsPattern(lli N, bool invert, bool upper)
{
    lli reminder;
    static string msg;
    short addvalue;
    (upper)? addvalue = 64:addvalue = 96;
    if(!msg.empty()) msg.clear();
    if(!invert)
        N = reversIntDigits(N);
    for(;N > 0 ;)
    {
        reminder = N % 10;
        N /= 10;
        for(int i = 0; i < reminder ; ++i)
            msg.push_back(reminder + addvalue);
        msg.push_back(10);

    }
    return msg.data();
}
