#include "header.h"



LLI  PrintDigits(LLI Number)
{
LLI Remainder, steps = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        cout << Remainder << endl;
    }
    return  steps;
}
int main(int argc , CCP argv[])
{
    if(argc >= 2)
        PrintDigits(atoi(argv[1]));
    else
     PrintDigits(getUInt());
return 0;
}