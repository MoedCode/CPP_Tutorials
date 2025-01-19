#include "main.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

/**/
int matrix0()
{
        int **x = (int **)malloc(3 * (5 * sizeof(int)));
        for (int i = 0; i < 3; i++)
           x[i] =(int *) malloc(5 * sizeof(int));

    int num_matrix[3][5] = {
        // 1 ,(1 + 4) , (5 + 5)
        {1, 5, 10, 16, 23 },
        // 2, (2 * 2), (4 * 2)
        {2, 4, 8, 16, 32},
        //  (curr +prev)
        {1, 1, 2, 3, 5},
    };
    print_arr_2Dint(x, 3, 5);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            x[i][j] = num_matrix[i][j];
    print_arr_2Dint(x, 3, 5);
    for (int i = 0; i < 3; i++)
        free(x[i]);
    free(x);
    return 0;
}
int numgame(){

    int num_matrix[3][5] = {
        // 1 ,(1 + 4) , (5 + 5)
        {1, 5, 10, 16, 23 },
        // 2, (2 * 2), (4 * 2)
        {2, 4, 8, 16, 32},
        //  (curr +prev)
        {1, 1, 2, 3, 5},
    };
    int i = 0;
    while (true) {
        if (i >= 3)
            i = 0;
        char x[10];
        if (!strcmp("exit", x))
            exit(0);

        cout << "compleate the next  ";
        print_arr_1Dint(num_matrix[i], 4,0,0);
        cout << endl << "  :-  ";
        scanf("%s",x);
        int num = atoi(x);
        if (num == num_matrix[i][4])
        {
            cout << "(:-) you are correct\n";
            i ++;

        }
        else
            cout << "haed luck tray again :)\n\n";
    if (i == 3)
        cout << "\n\n-----------WINNER---------------\n\n";


    }

return 0;

}
