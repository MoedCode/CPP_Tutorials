#include <cstdio>
#include <iostream>
using namespace std;

int main(void)
{
    int x , X = 1, X_ = 1, y = 1, n = 2147483647, u = NULL;
    unsigned int i, j, k;
    // i =  j = k = -5;
    x = -5;
    if ( x < 0)
        i = - x;
    else
        i = x;
    j = (unsigned int) x ;
    unsigned int m  = (unsigned int) x;
    k = m;
    cout << "i => "<< i << endl;
    cout << "j => "<< j << endl;
    cout << "k => "<< k << endl;
    cout << "cust   x => "<< (char)(x + '0') << endl;

    while (X  > 0)
        X ++;
    while (y  < 0)
    {

        X_ ++;
        y = X_ + 1;
    }
    cout << "null int: " << ++u<< endl;
    cout << "null int: " << u<< endl;
    printf("max_int[%i] max_int+1[%i]\n", n , (n + 1));
    printf("max_int[%i] max_int+2[%i]\n", n , (n + 2));
    cout << "overflow the int " << X << endl;
    cout << "reach to max of  the int " << X_ << X_ << '\t' << y <<endl;


    return 0;
}