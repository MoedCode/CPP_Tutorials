#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include <vector>
#include <typeinfo>
#include <array>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
typedef int I;
typedef unsigned int UI;
typedef long int LI;
typedef unsigned long int ULI;

typedef long long int LLI;
typedef unsigned long long int ULLI;

typedef double  F;
typedef double  D;
typedef long double  LD;
typedef char C;
typedef const char CC;

typedef const char * C_CP;
typedef vector<I>::iterator  VII ;
//macros
#define DEBUG(...) \
    do { \
        std::cout << "[DEBUG] File: " << __FILE__ << ", Line: " << __LINE__ << std::endl; \
        if (__VA_ARGS__[0] != '\0') { \
            std::cout << "Message: " << __VA_ARGS__ << std::endl; \
        } \
    } while (0)



// function definations

I PrintIArr(I * arr, I size, CC* msg=NULL, I cast=0)
;
I vectorSimpleAlgorithms(void);

void vectors();
I arr_cls();
void vectVSarr();
void vecfun();
I vector_iterator();
I cls_arr();

#endif