#include "headerLev2.h"
#include <cstring>



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
// Function to reverse a buffer in place
int reverseBuffer(char *buffer)
{
    if (buffer == nullptr) return -1;  // Error: NULL buffer

    int length = strlen(buffer);
    if (length == 0) return -2;  // Error: Empty string

    int start = 0, end = length - 1;
    while (start < end) {
        swap(buffer[start], buffer[end]);
        start++;
        end--;
    }
    return length;  // Return string length
}

// Function to convert integer to character string
string intToCharB(LLI N) {
    string Nbuff;  // Static buffer
    int i = 0;

    if (N < 0) {
        Nbuff[i++] = '-';
        N = -N; // Convert to positive for processing
    }

    do {
        Nbuff[i++] = (N % 10) + '0';  // Convert to char
        N /= 10;
    } while (N > 0);

    Nbuff[i] = '\0'; // Null termination

    // Reverse the digits (excluding minus sign)
    reverseBuffer(Nbuff.data() + (Nbuff[0] == '-'));

    return  Nbuff.data();
}
int callPrintDigit(int argc , CCP argv[])
{
    if(argc >= 2)
        PrintDigits(atoi(argv[1]));
    else
     PrintDigits(getUInt());
return 0;
}