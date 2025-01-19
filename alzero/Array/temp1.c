#include <stdio.h>
void print_matrix_vla(int hight, int width,  int matrix[width][hight])
{
    for (int i = 0; i < hight; i++) {
        printf("{ ");
        for (int j = 0; j < width; j++) {
            printf("%d", matrix[i][j]);
            if (j < width - 1) {
                printf(", ");
            }
        }
        printf(" }\n");
    }
}
int main(int argc, char **argv)
{


    int num_matrix[3][5] = {
        // 1 ,(1 + 4) , (5 + 5)
        {1, 5, 10, 16, 23 },
        // 2, (2 * 2), (4 * 2)
        {2, 4, 8, 16, 32},
        //  (curr +prev)
        {1, 1, 2, 3, 5},
    };
    print_matrix_vla(3, 5, num_matrix);


    return 0;
}