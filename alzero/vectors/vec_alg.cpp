#include "vector.h"
#include <algorithm>
#include <cstring>

I vectorSimpleAlgorithms(void)
{
    CP x= "☺☻♥♦♣♠•◘○♂▬!,▐";
    C xx[500]{'A', 'H'};
    I anum0[]{10, 20, 20, 30, 40, '$' };
    vector<I> vnum0 = {100, 200, 300, 400, '$',200 };
    vector<I> vnum1 {};
    cout << " // count element Repetitions \n";
    PrintIArr(vnum0.data(), vnum0.size(), "venum0 vector: ");


    cout << " // count element Repetitions \n";
    I el200 = count(vnum0.begin(), vnum0.end(), 200);
    cout << "el 200: " << el200 << endl;
    for (I i = 0; i <  strlen(x) ; i++)
    {
        vnum1.push_back(x[i]);
        xx[i] = x[i];
    }

    // PrintIArr(vnum1.data(), vnum1.size(), "venum1-1 vector: ");

    cout << " //reverse \n";
    reverse(vnum0.begin(), vnum0.end());
    PrintIArr(vnum0.data(), vnum0.size(), "venum0 after reverse ");

    for (I &num :vnum1)
        cout << (C) num;
    cout << endl;
    cout << " // count element Repetitions \n";
    int *ptr = &anum0[0];
    ptr+=3;
    cout << *ptr << endl;
    CP cp = "Test charp in cpp";
    CP cptr = &cp[0];
    cptr += 3;

    cout << cptr + 5<< endl;

    return 0;


}