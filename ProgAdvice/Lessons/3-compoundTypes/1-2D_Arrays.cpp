#include <iostream>
#include <iterator>
using namespace std;

template<typename Type>
int printarr1d(Type arr, int length, const char* F = nullptr, const char* idx = nullptr) {
    int i = 0;
    if (!arr)
        return -1;

    // Print opening delimiter
    int c = 0;
    for(; F && F[c] && F[c] != '%'; c++)
        cout << F[c];

    // Iterate through the array
    for (i = 0; i < length; i++) {
        // Print index and value if idx is provided
        if (idx) {
            for (int j = 0; idx[j]; j++) {
                if (idx[j] == '%' && idx[j + 1] == 'i') {
                    cout << i;
                    j++; // Skip the next character ('i')
                } else if (idx[j] == '%' && idx[j + 1] == 'v') {
                    cout << arr[i];
                    j++; // Skip the next character ('v')
                } else {
                    cout << idx[j];
                }
            }
        } else {
            // Print the element directly
            cout << arr[i];
        }

        // Print separator if there is a next element
        if (i < length - 1)
            cout << " ";
    }

    // Print closing delimiter
    if (F) {
        c++;
        for(; F[c]; c++)
            cout << F[c];
    }

    return 0;
}

template<typename Type>
int printMatrix(Type arr, int rownum, int colnum, const char* F = NULL, const char* idx = nullptr, char end='\n') {
    int c = 0;
    for(; F && F[c] && F[c] != '%'; c++)
        cout << F[c];
    cout << endl;
    for(int i = 0; i < rownum; i++) {
        printarr1d(arr[i], colnum, F, idx);
        if (i < rownum )
            cout << end;
    }

    if (F) {
        c++;
        for(; F[c]; c++)
            cout << F[c];
    }
    cout << endl;

    return 0;
}

int main() {
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

    printarr1d(intnum, 6, "{%}\n", "[%i]=%, ");
    printarr1d(str, 3, "{%}\n", "[%i]=%v, ");
    printarr1d(carr, 3, "{%}\n", "[%i]=%v, ");
    printarr1d(strarr, 2, "{%}\n", "[%i]=%v, ");

    // Print matrix with explicit rows and columns
    printMatrix(intmatrix, 2, 5, "{%}, ", "[%i]=%v, ");
    printMatrix(intmatrix, 2, 5, 0, "[%i]=%v");
    printMatrix(intmatrix, 2, 5, 0, 0);

    return 0;
}