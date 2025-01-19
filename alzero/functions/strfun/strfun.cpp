#include "strfun.h"
#include <iostream>


int swap_chars(char* str, int start, int end, int steps)
{
    int len = strlen(str), i = 0;

    // Adjust 'end' if it's set to the default value
    if (end == -1 || end >= len) {
        end = len - 1;
    }

    // Validate parameters
    if (start < 0 || start >= len || end < 0 || end >= len || start >= end || steps <= 0) {
        cerr << "Invalid parameters." << endl;
        return -1;
    }

    // Move characters to the left by 'steps' positions
    for (i = start; i <= end; ++i)
    {
        if (i + steps <= end) {
            str[i] = str[i + steps];
        } else {
            str[i] = ' '; // Replace the vacated positions with spaces
        }
    }
    return i;
}
int replace_char(char *charp ,char *rep,  int start, int end)
{
    int i = 0;
    if (!charp or !rep)
        return  -1;
    for (i = start; 1; ++i)

        {
            if(!charp[i] || (end > 0 && i >= end) )
                break;

            if (!rep[1])
                {
                    charp[i] = rep[0];
                    continue;
                }
            if(charp[i] == rep[0])
            {
                if (rep[1] =='\\' && rep[2] == '0')
                        {
                            charp[i] = '\0';
                            continue;

                        }

                    charp[i] = rep[1];
            }
            // cout << charp[i];
        }
        // cout <<endl;
    return i;



}

int remove_char(char *charp,  int start, int end, char c){
    int i = 0;
    if(!charp)
        return -1;
    for (i = start; 1; i++)
    {

        if(!charp[i] || (end > 0 && i >= end) )
            break;
        if(charp[i] == c)
        {
            swap_chars(charp,i);
        }
    }

    return i;
}
long long int letters_num(char * charp)
{
   long long int letterCount = 0;
    for (int i = 0; charp[i]; i++)
        if(charp[i] != ' ')
            letterCount++;
    return  letterCount;
}
int charpcomp(char *charp1 , char *charp2, char *res)
{
    int i = 0, dif=0, k = 0;
    char res_[2] ;
    if (res)
    {
        res_[0] = res[0]; res_[1] = res[1];
    }
    if (!charp1 || !charp2)
    {   char err[] = "no valid cha* 1 or char* 2";
        res = err;
        return (-1);
    }
    for (; 1 ; i++)
    {

        if (!charp1[i] || !charp2[i])
        {
            dif++;
            break;

        }
        if(charp1[i] != charp2[i])
        {

            dif++;
        if (res && res_[0]=='%' )
        {

            if(res_[1] == '1')
            {
                res[k] = charp1[i];
                k++;
                }
            if(res_[1] == '2')
            {
                res[k] = charp2[i];
                k++;
                }
        }
        }

    }
    res[k] = '\0';
    if (dif)
        return  -dif;
    return i;
}
void string_functions()
{

    string str0 = "Jus String For Test CPP String Functions";
    char str1[] = "Jus String For Test CPP String \nFunctions", x[] = " \\0";

    cout << "Charcters Functions \n string before" << str0 << endl;
    cout << "str0.size(): " << str0.size() << endl;
    cout << "letters_num(str0.data()) " << letters_num(str0.data()) << endl;
    cout << "isupper(str0[0]): " <<bool(tolower(str0[0])) << endl;
    cout << "tolower(str0[0]): " <<char(tolower(str0[0])) << endl;
    cout << "islower(str0[1]): " <<bool(toupper(str0[4])) << endl;
    cout << "toupper(str0[4]): " <<char(toupper(str0[4])) << endl;
    // remove_char(str1);

    replace_char(str1, x);
    cout << "replace_char(str1, \"\n\\0\"): " << str1<< endl;
	string s0 = "asdsadasdsad asdasadsasas as dasd", s1  = "dsafsdgf ds fsdgdsf sdfsd fsdgfdsda d adfds"; char  res[500]="%2 dasdasdasdasdas";
	int m = charpcomp(s0.data(), s1.data(), res);
	cout << "res: " << res << " m: " << m << endl;
	// string_functions();
}