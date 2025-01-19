#ifndef STRFUN_H
#define STRFUN_H
#include <iostream>
#include <string.h>
using namespace std;
#define DEBUG printf("File: %s, Line: %d\n", __FILE__, __LINE__);
int swap_chars(char* str, int start = 0, int end = -1, int steps = 1);
int replace_char(char *charp ,char *rep,  int start = 0, int end = -1);
int remove_char(char *charp,  int start = 0, int end = -1, char c = ' ');
int charpcomp(const char* charp1, const char* charp2, char* res=NULL);


void string_functions();

#endif
