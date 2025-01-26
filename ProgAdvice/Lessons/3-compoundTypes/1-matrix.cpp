#include "header_comp.h"

#include "../1-Library/printlib.h"
using namespace printlib;

void printMatrixTestCases()
{
    int intnum[] = {100, 400, 200, 300, 400, 500}; // Not null-terminated
    char str[] = "HI!"; // Null-terminated
    char carr[] = {'H', 'I', '!', '\0'}; // Null-terminated
    const char* strarr[] = {"HI!", "HI?", nullptr}; // Null-terminated
    int intmatrix[2][5] = {
        {10, 20, 30, 40, 50},
        {60, 70, 80, 90, 100}
    };
   int intmatrix2[10][10] = {
        {10, 20, 30, 40, 50},
        {60, 70, 80, 90, 100}
    };

    printArray(intnum, 6, "{%}\n", "[%i]=%, ");
    printArray(str, 3, "{%}\n", "[%i]=%v, ");
    printArray(carr, 3, "{%}\n", "[%i]=%v, ");
    printArray(strarr, 2, "{%}\n", "[%i]=%v, ");

    // Print matrix with explicit rows and columns
    printMatrix(intmatrix, 2, 5, "{%}, ", "[%i]=%v, ");
    printMatrix(intmatrix, 2, 5, 0, "[%i]=%v");
    printMatrix(intmatrix, 2, 5, 0, 0);


}