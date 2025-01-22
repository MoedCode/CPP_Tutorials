#include "printlib.h"
using namespace printlib;
int main() {
    // Example usage
    char c = 'A';
    const char* s = "just string"; // Use const char* to avoid warnings
    int i = 42;
    double d = 3.14;
    long l = 1234567890;
    long long ll = 1234567890123456789LL;
    long double ld = 3.141592653589793238L;
    int* ptr = &i;
    char carr[] = {'A', 'B'};
    const char* sarr = "just string"; // Use const char* to avoid warnings
    int iarr[] = {42, 42};
    double darr[] = {3.14, 3.14};
    long larr[] = {1234567890, 2234567890};
    long long llarr[] = {1234567890123456789LL, 2234567890123456789LL};
    long double ldarr[] = {3.141592653589793238L, 4.141592653589793238L};
    int* ptrarr[] = {&i, &i};

    // Print with format string
    print("c => {}, s => {}, i => {}, d => {}, l => {}, ll => {}, ld => {}", c, s, i, d, l, ll, ld);

    // Print with changed argument order
   int  x = print("s => {}, c => {}, d => {}, i => {}, l => {}, ll => {}, ld => {}", s, c, d, i, l, ll, ld);

    // Print without format string
    print(nullptr, c, s, i, d, l, ll, ld);
    print("", c, s, i, d, l, ll, ld);
    print(0, c, s, i, d, l, ll, ld);

    // Print arrays
    print("carr => {}, sarr => {}, iarr => {}, darr => {}, larr => {}, llarr => {}, ldarr => {}", carr, sarr, iarr, darr, larr, llarr, ldarr);
    print(nullptr, carr, sarr, iarr, darr, larr, llarr, ldarr);
    print("number of chars = {}", x);
    return 0;
}