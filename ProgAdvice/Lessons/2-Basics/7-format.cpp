#include  "header_b.h"
#include <cstdlib>
#include <cstring>
#include <iomanip>

void intformat()
{
    int i = 0, Page = 1, TotalPages = 10 , Number1 = 20, Number2 = 30;
    // print string and int variable
       printf(" num %0*i \n", 5, 9);
    printf("%i-The page number = %d \n",__LINE__, Page);
    printf("%i-You are in Page %d of %d \n",__LINE__, Page, TotalPages);
    //Width specification
    printf("%i-The page number = %0*d \n",__LINE__, 2, Page);
    printf("%i-The page number = %0*d \n",__LINE__, 3, Page);
    printf("%i-The page number = %0*d \n",__LINE__, 4 , Page);
    printf("%i-The page number = %0*d \n",__LINE__, 500, Page);

    printf("The Result of %d + %d = %d \n", Number1, Number2,
    Number1+ Number2);

}

void FDformat()
{
    printf("  AN-94 %.*f  mm\n", 5, 5.45);
    printf("  M4 %.*f mm\n", 5, 5.6);
    printf(" M7  %.5f mm\n",  7.62);
    /* to print zeros before float or double number
    te number after %0 is number of entire float or double digits
    including zeros after and before   */
    printf(" AWM %08.2f mm\n",  12.7);
}
void charsFormat()
{
    /*number of the spaces and the characters
    so in the case that number after %5c is 5 .will leave 4
    spaces cause the fifth is the character ..

    */
    printf("%*c \n", 5, 'A');
    printf("%5c \n",  'B');
    printf("%5s \n",  "HI!");

}
