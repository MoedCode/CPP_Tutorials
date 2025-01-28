#ifndef HEADER_COMP_H
#define HEADER_COMP_H

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// Function declarations with default arguments

void printMatrixTestCases(void);
int testVectores(void);
 void TestGetData(void);

string getUserAnswer(const char **questionArr, size_t size,char  action = 'r' );
#endif