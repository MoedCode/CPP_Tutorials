#include "header_b.h"


int ternary_if(char **argv)
{
    int n;
    (argv && argv[1]) ? n = atoi(argv[1]) :n = n;
    cout <<  (n < 0 ? "negative":( n ==  0 ? "zero":"positive")) << endl;
    (n < 0) ? cout << "negative-\n" :
    (n  == 0) ? cout << "zero-\n":
    cout << "positive-\n";
    const char  *names[]{"name0", "name1", "name2"};
    int IDs[]{1, 2, 3};
    for (const char *name : names)
        {
            static int i = 0;
            if (i == 0)
                cout << "|name|\t|ID|\n";
            cout << name << " \t";
            cout << IDs[i] << '\n';
            i++;
        }

    return 0;
}