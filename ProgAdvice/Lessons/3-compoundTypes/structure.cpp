#include "./header_comp.h"
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <iostream>

struct Employee
{
    const char *first_name;
    const char *last_name;
    float salary;
    const char *currency;
    const char *email = "moahmed@eample.com";
    void __str__()
    {
        printf("{\n\"first_name\":\"%s\", ",first_name);
        printf("\"last_name\":\"%s\", ",last_name);
        printf("\"currency\":\"%s\", ",currency);
        printf("\"salary\":\"%f\", \n}\n",salary);
    }
    char  *ro_json()
    {
    static  char buff[1000];

    sprintf(buff,"{\n\
    \"first_name\":\"%s\",\"last_name\":\"%s\", \"currency\":\"%s\", \"salary\":%f\
    \n}\n",
    first_name, last_name, currency, salary);
    return buff;
    }
};

int writeFile(CCP filename, CCP modes, CCP format, ...) {
    if (!filename || !modes || !format) {
        cerr << (!filename ? "filename nullptr\n" : "");
        cerr << (!modes ? "modes nullptr\n" : "");
        cerr << (!format ? "format nullptr\n" : "");
        return -1;
    }

    FILE *file = fopen(filename, modes);
    if (!file) {
        cerr << "Failed to open file: " << filename << endl;
        return -1;
    }

    va_list args;
    va_start(args, format);
    vfprintf(file, format, args); // Use vfprintf for variable arguments
    va_end(args);

    fclose(file);
    return 0; // Return 0 on success
}
void  employee()
{
    Employee em0 = {"mohamed", "mahmoud",
   1000.0, "₿" };
   Employee *ptr0 = &em0;
   Employee ptr1 = em0;
    CP x  = em0.ro_json();
    // writeFile("data.json", "a", "%s", x);
    cout << "em0.first_name: " << em0.first_name << endl;
    cout << "ptr0->email: " << ptr0->email << endl;
    cout << "(*ptr0).email: " << (*ptr0).email << endl;
    cout << "ptr1.email: " << ptr1.email << endl;

}
