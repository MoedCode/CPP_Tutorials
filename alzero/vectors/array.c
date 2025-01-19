
#include <stdio.h>
int print(int * arr, int size, char* msg)
{   if (msg)
        printf("%s", msg);
    for (int i = 0; i <size; i++)
        printf("%i, ", arr[i]);
    putchar(10);
    return 0;
}
int main()
{
    int numbers[]={10, 20, 30, 40};
    int size = sizeof(numbers) / sizeof(int);
    print(numbers, size, "numbres bef: ");
    numbers[3]  = 50;
    print(numbers, size, "numbres aft: ");
    numbers[4]  = 60;
    print(numbers, size, "numbres aft: ");
    return 0;
}
