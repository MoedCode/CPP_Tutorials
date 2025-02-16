#ifndef HEADERLEV2__H
#define HEADERLEV2__H

#include <cstdint>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>

using namespace std;
typedef unsigned long int llu;
typedef long long int lli;
typedef long double  ld;
typedef char * cp;
typedef const char *  ccp;
typedef const char **  cc2p ;
//functions declaration
//  #define DEBUG(msg) cout << __FILE__ << " : " << __LINE__ <<(msg )?msg:" " << endl;
 #define DEBUG_M(msg) cout << __FILE__ << " : " << __LINE__ << " " << ((msg) ? (msg) : " ") << endl;
 #define DEBUG cout << __FILE__ << " : " << __LINE__ <<  << endl;



lli  PrintDigits(lli Number);
ld getPosDouble(ccp msg = "Type Amount: ") ;
llu getUInt(ccp msg = "Type Amount: ") ;
lli DrawMultiplicationTable(int from=1 , int to=10);
int   isPerfect(lli N);
int   isPerfect_(lli N, int print=1);
string intToCharB(lli N);
int reverseBuffer(char *buffer);
int SumOfNDigits(lli  N, int *steps=0);
lli sumOfBuffDigits(ccp buffer, int *steps=0);
lli reversIntDigits(lli N);
ccp digitFreqInLLInt(lli N, int digit);
ccp LLIntDigitsFrequency(lli N);
ccp numberPattern(lli N, int inverted = 0);
void printDigitInOrder(lli N);
bool isPalindromeInt(lli N);

int PrintPerfectNumbersFrom1ToN(int Number);
ccp charsPattern(lli N, bool invert=0, bool upper=1);

    bool check_PWD(ccp PWD);
    ccp crackPWD(size_t size , bool useMaxTrial = true, size_t maxTrial=SIZE_MAX);

#endif

//find . -type f -name "*.cpp" -exec sed -i 's/LD /ld /g' {} +
//find . -type f -name "*.cpp" -exec sed -i 's/ccp /ccp /g' {} + && find . -type f -name "*.h" -exec sed -i 's/ccp /ccp /g' {} +