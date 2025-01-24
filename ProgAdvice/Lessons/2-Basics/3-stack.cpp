#include  "header_b.h"

void Function4()
{
    cout << "function4 " << endl;
}
void Function3()
{

    Function4();
    cout << " function3 " << endl;
}

void Function2()
{

    Function3();
    cout << " function2 " << endl;
}

void Function1()
{

    Function2();
    cout << " function1 " << endl;
}

void  simple_stack()
{
    Function1();

}
