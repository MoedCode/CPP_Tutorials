#include "headerLev2.h"
#include <iomanip>
#include <iostream>
LLI DrawMultiplicationTable(int from , int to)
{
    // iterators
    int i = from, j = from,steps = 0;
    if (from >= to || from < 1 || to < 1 )
        return 0;
    // drow header
    for(;i <=to ; ++i , steps+=5  )
    {
        (i == from) ? cout << "\t" :cout << "";
        cout<< "\t" << i  ;
        (i == to) ?cout << "\n":cout << "";
    }
    // for(i = 0; i <= to; ++i , ++steps  )

    //     cout << "________" ;
    // cout << endl;
    cout << std::setw(steps*2  ) << std::setfill('-') << "" << std::endl;
    for(i = from; i <= to; i++,steps+=5)
    {
        cout << i<<"\t" << "|";

        for (j = from; j <= to ; j++, steps+=5)
            cout << "\t" << i * j;
        cout <<"\n";
    }
    return steps;
}