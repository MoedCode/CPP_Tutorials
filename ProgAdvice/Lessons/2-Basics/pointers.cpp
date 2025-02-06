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
void voidPointers()
{
    int i = 5, *ptr0 = &i;
    void *ptr1 = ptr0, *ptr2 = &i ;
    // ptr0  = ptr1 = &i; // error: Assigning to 'int *' from incompatible type 'void
    cout <<"ptr0: " << ptr0 << " ptr1: " << ptr1 << endl;
    //cout << " ptr: " << *ptr << endl; //error: ‘void*’ is not a pointer-to-object type
    //
    cout << "dereference => `*()`casting => `(<type-name *>)`\
     `*` => refare to casting a pointer  \n";
    cout << "*(ptr0): "<< *(ptr0)<<"\t*((int *)ptr1):  " << *((int *)ptr1)
    <<"\t*((int *)ptr2):  " << *((int *)ptr2) << endl;

    cout << "\n ----- using static casting ------- \n" << endl;
    cout << " (static_cast<int *>(ptr1)): " << (static_cast<int *>(ptr1))<<endl;
    cout << "print memory address instead of value // messing  derrforonce the pointer\n";
    cout << " *(static_cast<int *>(ptr1)): " << *(static_cast<int *>(ptr1))<<endl;

}