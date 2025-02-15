#include "headerLev2.h"
#include <cstdlib>

int main(int argc, cc2p argv)
{
    lli N = getUInt("type number to print inverted pattern: ");
    int steps = 0, digit0 = 8;
    // lli N0 = 12321, N1 = 12233456788 ,N2 = 12233456788, N3 = 12345;
    /*

    DrawMultiplicationTable();
    string x = intToCharB(123456);
    string _x = intToCharB(-123456);
    cout << x << endl << _x << endl;
    cout << SumOfNDigits(999'999'999'999'999'999, &steps) << "\t" << steps << endl ;
    steps = 0; ccp xx = "999'999'999'999'999'999";
    cout << sumOfBuffDigits(xx, &steps) << "\t" << steps << endl ;
    cout << (int) '1' << endl;;
    cout << xx << endl;
    cout << "N0: " + to_string(N) + " reversed N0: " + to_string(reversIntDigits(N0)) + '\n';
     cout << digitFreqInLLInt(N1, digit0) << endl;
     cout << LLIntDigitsFrequency(N1) << endl;
     printDigitInOrder(N1);
    cout << "isPalindromeInt(N0): " <<isPalindromeInt(N0)<<endl;
      cout << "isPalindromeInt(N1): " <<isPalindromeInt(N1)<<endl;
      cout << "isPalindromeInt(N2): " <<isPalindromeInt(N2)<<endl;
        printf("N:%lli \n",N);
    cout << "inverted Pattern :\n" << numberPattern(N)<< endl;
    cout << "inverted inverted Pattern for :\n" << numberPattern(N, 1)<< endl;
      */

    cout << charsPattern(N) << endl;
    cout << charsPattern(N, 1) << endl;
    cout << charsPattern(N, 0, 0) << endl;
    cout << charsPattern(N, 1, 0) << endl;

    return 0;
}
