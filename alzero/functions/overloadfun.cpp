#include "main.h"
#include "strfun/strfun.h"

void fun()
{
    int i = 0;
    cout << "from function overload" << ++i << "func1"<< DEBUG
    cout << "from function overload" << ++i << "func1"<< DEBUG
    cout << "from function overload" << ++i << "func1"<< DEBUG
}
void fun(string s)
{
    int i = 0;
    cout << "from function overload" << ++i << "func2"<< DEBUG
    cout << "from function overload" << ++i << "func2"<< DEBUG
    cout << "from function overload" << ++i << "func2"<< DEBUG
}