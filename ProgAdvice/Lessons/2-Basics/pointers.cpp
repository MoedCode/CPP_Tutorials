#include "./header_b.h"
void pointers()
{
	int i = 5, *p;
	p = &i;
	cout << "p = "<< p << endl;
	cout << "p = + 1"<< p + 1<< endl;
	cout << "*p = + 1"<< *p + 1<< endl;
	cout << "(p = + 1) = "<< (*p + 1)<< endl;
	if (p == &i) cout  << (p == &i) << endl;
	const char *x = "HI!";
	const char *x_ = x, *cptr = &x[0];
	cout <<( x_ == &x[0] && x_== x) << endl;

	const char *xar[] = {"str0", "str1", "str2", };
	char const  **xar_1= xar, **xar_2 ;
	xar_1 += 1;
	cout << *xar_1 << endl;
	xar_2 = &xar_1[0];
	cout << *xar_2 << endl;
	cout << *xar_1 + 1 << endl;
	cout << *(xar_1 + 1) << endl;

	cout << *xar_1 << endl;

}