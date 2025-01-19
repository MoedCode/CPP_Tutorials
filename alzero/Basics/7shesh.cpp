#include <cstdio>
#include <cstdlib>
#include <iostream>
// #include <string>
using namespace std;

int main(void)
{
    bool condation = true;
    char * x;
    cout << 20 / 5 * 4 << "\n";
    cout << (condation ? "true\n" : "false\n");
    string msg = condation ? "its kaky" : "laaa" ;
    cout << "condtional assignment: " << msg << endl;
    msg[140] = 'D';
    cout << "msg after overwite: " << msg << endl;
    char *d = (char *)malloc(1000000000); // Allocate memory for 4,000,000 integers
    if (!d) {
        cerr << "Memory allocation failed!" << endl;
        return 1;
    }
    string  logo = "a7ena men ... al da3 men 30mrena snine";
    int j = 0;
    for (int i = 0; i <= 1000000000; i++)
    {
        if (i == 1000000000)
            {
                d[i] = '\0'; break;
            }
        if (logo[j] == '\0'){
            d[i] = '\t'; j = 0; continue;

            }
        d[i] = logo[j];
        j++;
    }

    FILE *file = fopen("7shesh.txt", "w");
    fprintf(file, "%s", d);
    fclose(file);

    cout << '\a'; // Audible alert
    cout << sizeof(d) << endl;
    free(d);      // Free allocated memory
    return 0;
}