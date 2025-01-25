#ifndef HEADER_B_H
#define HEADER_B_H
// includes
#include <iostream>
#include <cstring>
#include "../1-Library/scanlib.h"
#include "../1-Library/printlib.h"
//globals
using namespace std;
using namespace  scanlib;
using namespace  printlib;
// function declaration
string validate_PWD();
void bitwise(void);
void  simple_stack();
void PrintNumbers(int N, int M);
int ascPrintNum(int n1, int n2);
int desPrintNum(int n1, int n2);
int power(int n1, int n2);
const char* cstrJoin(int count, ...);
void autovars();
void intformat();
void  charsFormat();

#endif