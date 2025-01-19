#include<iostream>
#include<stdio.h>
#include<string.h>
int printline(int len, char charc, char endwith);
int main(void)
{
    const char* name = "Mohamed Mahmoud Abdalstar Hadhoud";
    const char*  city = "Alexandria";
    const char*  country = "Egypt";
    int age = 33;

    int name_len =  strlen(name);
    std::cout << "name_len " << name_len << std::endl;
    int len  = name_len *1.5 ;
    int margin = len *  .1;
    printline(len, '*', '\n');
    printline(margin, ' ', ' ');
    std::cout << "name: " << name << '\n' ;
    printline(margin, ' ', ' ');
    std::cout << "city: " << city << '\n' ;
    printline(margin, ' ', ' ');
    std::cout << "country: " << country << '\n' ;
    printline(margin, ' ', ' ');
    std::cout << "age: " << age << '\n' ;
    printline(len, '*', '\n');
    return (5);
}
int printline(int len, char charc, char endwith='\n')
{
        int i = 0;

    if (!len || (!charc && !endwith))
        return 0;
    for (; i < len; i++)
        std::cout << charc;
    putchar(endwith);
    return 0;
}