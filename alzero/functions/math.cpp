#include "main.h"

void math_functions(void)
{
    	double num = 123.521 ;
	cout << "num: " << num << endl ;
	cout << "round(num): " << typeid(round(num)).name() <<round(num) << endl ;
	cout << "ceil(num): " << typeid(ceil(num)).name() <<ceil(num) <<  endl ;
	cout << "floor(num): " << typeid(floor(num)).name() <<floor(num) << endl ;
	cout << "fmod(num, 2): " << typeid(fmod(num, 2)).name()<<fmod(num, 2) << endl ;
	cout << "pow(num, 2): " << typeid(pow(num, 2)).name()<<pow(num, 2) << endl ;
	cout << "return type of typeid: " << typeid(typeid(round(num)).name()).name() << endl;
	const char *x = typeid(round(num)).name();
	cout << x << endl;
	cout << "num: " << num << endl ;
}