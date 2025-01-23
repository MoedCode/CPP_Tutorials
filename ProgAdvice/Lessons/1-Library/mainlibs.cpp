#include "printlib.h"
using namespace printlib;

int main() {
    char c = 'A';
    const char* s = "just string";
    int i = 42;
    double d = 3.14;
    long l = 1234567890;
    long long ll = 1234567890123456789LL;
    long double ld = 3.141592653589793238L;

    int count1 = print("c => {}, s => {}, i => {}, d => {}, l => {}, ll => {}, ld => {}", c, s, i, d, l, ll, ld);
    int count2 = print("s => {}, c => {}, d => {}, i => {}, l => {}, ll => {}, ld => {}", s, c, d, i, l, ll, ld);
    int count3 = print(nullptr, c, s, i, d, l, ll, ld);
    int count4 = print("", c, s, i, d, l, ll, ld);

    cout << "Count1: " << count1 << "\n";
    cout << "Count2: " << count2 << "\n";
    cout << "Count3: " << count3 << "\n";
    cout << "Count4: " << count4 << "\n";

    return 0;
}
