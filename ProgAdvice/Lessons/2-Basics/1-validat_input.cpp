#include "header_b.h"
#include <limits>

string validate_PWD()
{
    string PWD1, PWD2;
    int sign = 1;
    while (cin.fail() || sign)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        PWD1 = getInput<string>("please type new password. \n\t:- ");
        if (PWD1.size() > 50)
        {
            cerr << "\n --password more than 50 characters-- \n\n";
            continue;
        }
        if (PWD1 == "\\e")
            exit(0);
        PWD2 = getInput<string>("confirm password. \n\t:- ");
        if (PWD2 == "\\e")
            exit(0);
        if (PWD1 != PWD2)
        {
            cerr << "passwords not match. \n";
            continue;
        }
        else
            sign = 0;

    }
    print("password1 =>{} password2 => {}", PWD1, PWD2);
    return PWD1;
}
