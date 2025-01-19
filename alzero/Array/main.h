#ifndef MAIN_H  // Include guard to prevent multiple inclusions
#define MAIN_H

// Standard library includes
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <array>
#include <cstddef>
#include <cstdio>
#include <cstring>

using namespace std;

// Function declarations
int print_arr_1Dint(int *arr, size_t size, size_t indent=1, int idx=1);
int  print_arr_2Dint(int **array, size_t heigt, size_t width, size_t indent=1, int idx=1);
string  strjoin(string str1,   string str2);
char* c_strjoin(const char* str1, const char* str2);
int str_pract1(void);


// Generic template prototype for print_array
template <typename T>
void print_array(const std::string &format, const T *arr, size_t size);

// Specialized prototype for string arrays
void print_array(const std::string &format, const std::string *arr, size_t size);
#endif // MAIN_H
