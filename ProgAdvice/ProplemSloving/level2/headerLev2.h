#ifndef HEADERLEV2__H
#define HEADERLEV2__H

#include <iostream>
using namespace std;
typedef unsigned long int ULI;
typedef long long int LLI;
typedef long double  LD;
typedef char * CP;
typedef const char *  CCP;
typedef const char **  CC2P;
//functions declaration
LD getPosDouble(CCP msg = "Type Amount: ") ;
ULI getUInt(CCP msg = "Type Amount: ") ;
LLI DrawMultiplicationTable(int from=1 , int to=10);
int   isPerfect(LLI N);
int   isPerfect_(LLI N, int print=1);
string intToCharB(LLI N);
int reverseBuffer(char *buffer);

int PrintPerfectNumbersFrom1ToN(int Number);


#endif
