#include  "../1-Library/printlib.h"
// #include <unistd.h>

using namespace printlib;


int main(void)
{
    int i = 0;
    char msg[] = "its kaky\n";
//    i >= 0 ? write(1, msg, size(msg) ) :0;
   i >= 0 ? print(0, msg) :0;
   return 0;

}