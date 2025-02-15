#include "headerLev2.h"

lli reversIntDigits(lli N)
{
    lli result = 0, reminder;
    while (N > 0) {
        reminder = N % 10;
        N = N / 10;
        result = (result * 10) + reminder;
        /* 1234
            N > 1 : true, rem: 4 , N:123 res:(0 * 10) + 4#4
            N > 1 : true, rem: 3 , N:12 res:(4 * 10) + 3 #43
            N > 1 : true, rem: 2 , N:1 res:(43 * 10) + 3 #432
            N > 1 : true, rem: 1 , N:0 res:(432 * 10) + 3 #4321
            N > 1 : false, break

        */
    }
    return result;
}