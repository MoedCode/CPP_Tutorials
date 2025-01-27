#include  "header_comp.h"


#include <vector>


#include "../1-Library/printlib.h"
using namespace printlib;


using namespace std;

void Trash_useless(char *buff, size_t r=10, size_t c = 10, const char *F = "%02d ")
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cout <<  (i + 1) * (j + 1);

            char temp[15];    // Temporary buffer to hold each formatted string
            sprintf(temp, "%08i ", (i + 1) * (j + 1)); // Format the number
            strcat(buff, temp); // Append the formatted string to the main buffer
        }
        strcat(buff, "\n"); // Append a newline after each row
    }
}

int vectores()
{
    vector< int>vnum;

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            vnum.push_back(((i + 1) *( j +1)));
    for (int &n : vnum )
         printf(" %i", n);
    cout << endl;
    cout << vnum.size() << endl;
    return 0;
}
