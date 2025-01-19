#include "main.h"
int c_style_array()
{
        char wrarr[30]{'A','7','A'};
    int intarr[30] ;

        cout << strlen(wrarr) << "\n";

    wrarr[3] ='\t';
    for (int i = 0; wrarr[i]; i++)
        {
            if(wrarr[i + 1] == '\0')
            {
                cout <<wrarr[i]<< "\\0";
                // continue;
            }
            intarr[i] = (int) wrarr[i];
            putchar(wrarr[i]);
        }
        putchar(10);
        cout << strlen(wrarr) << "\n";
    // wrarr[30] = '\0';
    cout << wrarr << "\n\a";
    cout << sizeof(wrarr) << endl;
    return 0;
}
int arr_methods0()
{
        array<int , 4> nums = {1,2,3,4};

    cout <<"array  size :"<<nums.size()<<"\n";
    print_arr_1Dint(nums.data(), nums.size(),0);
    nums.fill(10);
    print_arr_1Dint(nums.data(), nums.size(),0);
    cout << "fill array with \'A\' \n";
    nums.fill('A');
    print_arr_1Dint(nums.data(), nums.size(),0);
    cout << "fill array with \\0 \n";

    nums.fill('\0');
    print_arr_1Dint(nums.data(), nums.size(),0);
    cout << "fill array with NULL \n";

    // nums.fill(NULL);
    print_arr_1Dint(nums.data(), nums.size(),0);
 return 0;
}
/*
int main(int argc, char **argv) {
    array<string , 3> names {"user1","user2", "user3"};
    array<int , 3> names1 = {};

    cout <<  "names.front(): " << names.front() << endl;

    cout <<  "names.back(): " << names.back() << endl;

    cout <<  "names.at(2): " << names.at(2) << endl;

    cout <<  "names.size(): " << names.size() << endl;

    cout <<  "names.empty(): " << names.empty() << endl;

    cout <<  "names1.empty(): " << names1.empty() << endl;


    return 0;
}
*/