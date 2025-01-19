#include <iostream>

using namespace std;

int  TDAP(int *arr, int size)
{
    int i = 0;
    cout <<"<  class type : arr  " << arr <<" > :\n";
    for (i = 0;  i < size; i++)
        cout << '[' << i << "]="<< arr[i] << ",";
    cout << "}\n";
    return i;

}
int main(void)
{
    int arr[10], i;

    TDAP(arr, 10);
    TDAP(arr, 100);
    cout << (int) '\a';

}