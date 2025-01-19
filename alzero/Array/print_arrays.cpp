#include "main.h"
#include <cstddef>
#include <iostream>
#include <string>

int  print_arr_1Dint(int *arr, size_t size, size_t indent, int idx)
{
    size_t i, j = 0 ;
    size = (size_t)size;
    char ind1 = indent >= 1?  '\n':'\0',ind2 = indent >= 2?  '\n':'\0';
    size = (size_t)size;

    cout <<"{" << ind1;

    for (i = 0; i < size; i++ )
        {
            if (idx)
                cout <<'['<< i << "]=";

            cout << arr[i] ;
            cout << (i < size - 1 ? ", " : "");


            cout << ind2;
            j = 1;
        }
    cout << ind1<<"}"  ;

    return  (int)i;
}
int  print_arr_2Dint(int **arr, size_t heigt, size_t width, size_t indent, int idx)
{
    // size_t heigt = size[1], width = size[2];
    char ind1 = indent >= 1?  '\n':'\0',ind2 = indent >= 2?  '\n':'\0';

    cout <<"{" << ind1;
    for (int i = 0; i < heigt; i++)
    {
        print_arr_1Dint(arr[i], width,0,idx);
        if (i < heigt - 1)
            cout << ", ";
        cout << '\n';
    }

     cout << "}"<< ind1 << endl;

    return 0;



}
/*
int print_array(string format , void **arr, size_t size)
{
    int *intptr,  mode ;

    string befIdx, afterIdx ;
    for (int i = 0; format[i]; i++)
    {
        cout << format[i] ;

            if(format[i] == '`')
            {
                for(size_t j = (i + 1) , k = 0; format[j] !='`'; j++, k++ )
                    {
                        if (!mode)
                        {
                            befIdx[k] = format[j];
                            if(format[j] == '%')
                            {
                                mode = 1;
                                j +=2;
                                k = 0;
                            }
                            else {
                                afterIdx = format[j];

                            }
                        }
                    }
                    continue;
            }
        if (format[i] == '%')
        {


            if(format[i + 1] == 'i' || format[i + 1] == 'd')
            {
                intptr = (int *) *arr;
                for (size_t a = 0; size; i++)
                    cout << befIdx << intptr[i] << afterIdx;

            }
            else if (format[i + 1] == 's')
             {

                for (size_t a = 0; size; i++)
                    // char **charptr = (char **) *arr;
                    string *str = (string *) *arr;
                    cout << befIdx << str[i] << afterIdx;

             }
        }

        for (size_t a = 0; size; i++)
        {
            cout << befIdx << arr[i] << afterIdx;
        }
    }
return  0;

}
*/

/**/
// Generic function to print arrays
