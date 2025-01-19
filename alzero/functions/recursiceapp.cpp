#include "main.h"

int fibonaccirec(int n)
{
    if (n <= 1) {
        return n;  // Base case: F(0) = 0, F(1) = 1
    } else {
        cout << n << endl;
        return fibonaccirec(n - 1) + fibonaccirec(n - 2);  // Recursive step
    }
}
int fibonacciito(int n)
{
    if (n <= 1) {
        return n;  // Base cases: F(0) = 0, F(1) = 1
    }

    int first = 0, second = 1, next;
    for (int i = 2; i <= n; ++i) {
        next = first + second;  // Calculate the next Fibonacci number
        first = second;         // Shift the values for the next iteration
        second = next;
    }
    return second;  // After the loop, `second` holds F(n)
}