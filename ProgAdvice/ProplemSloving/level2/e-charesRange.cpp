#include "headerLev2.h"
#include <cstddef>
#include <cstdio>

ccp allCharsInrange(ccp from, ccp to, bool upper=1)
{
    if(!from || !to)
        return  nullptr;
    short addvalue;
    static string msg;
    char f, t;
    if(!msg.empty()) msg.clear();
    (upper)? addvalue = -32:addvalue = 0;
    for (int i = 0; i <= 27; i++)
    {

    while(*from && *to)
    {
        f = *from; t = *to;
        (f > 64 && f < 97)? f +=32:0;
        (t > 64 && t < 97)? t +=32:0;

            if(f > 64 && f < 123)
                msg.push_back(f + addvalue);
            else
                msg.push_back(f + addvalue);
        msg.push_back(10);
        from ++; to++;
    }
    }

    return msg.data();

}
ccp PrintWordsFromAAAtoZZZ(size_t *size=0)
{
    static string msg;
    if(!msg.empty()) msg.clear();

    for (int i = 65 ; i <=  90; i ++)
    {
        for (int j = 65 ; j <=  90; j ++)
        {
            for (int k = 65 ; k <=  90; k ++)
            {

                msg += i ;
                msg += j ;
                msg += k ;
                msg += ' ';
            }
             msg += 10;

        }
    }
    if(size)
        *size = msg.size();
    return msg.data();
}

// int main()
// {
//     size_t size ;
//     ccp msg = PrintWordsFromAAAtoZZZ(&size);
//     cout << size << endl;
//     cout << msg << endl;
//     return 0;
// }