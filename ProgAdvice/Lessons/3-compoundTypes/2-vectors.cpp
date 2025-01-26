// #include "header_comp.h"


#include <iostream>
#include "../1-Library/printlib.h"
using namespace printlib;


using namespace std;



int vectores()
{
    // vector< int> intMatrix ;
    int intMatrix[10][10];

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            intMatrix[i][j] = (i + 1) * (j + 1);
/*
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
            printf("%03d \t",intMatrix[i][j] );

    putchar(10);
    }
*/
    size_t sizes[2] = {10, 10};
    // printf_array(intMatrix[0], 10, "  %03d", "{%ar}");
    // cout << "\n-------\n";
    printf_matrix(intMatrix, 10, 10, "  %03d", "%Mx\n", "%ar\n");
    printf_matrix(intMatrix, 10, 10, " %03d, ", "[\n%Mx],", "[%ar]\n");


    return 0;
}
