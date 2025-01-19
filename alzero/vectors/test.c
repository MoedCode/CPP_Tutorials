#include <stdio.h>

int main(void)
{
    int i = 5, *pi;

    char *x = "char *x", y='y', *pc0, *pc1;
    void *pv0, *pv1, *pv2;
    printf("all pointer before pointing to nay values \n");
    printf("pi=%li, pc0=%li, pc1=%li, pv0=%li, pv1=%li, pv2=%li \n",sizeof(pi),sizeof(pc0),sizeof(pc1),sizeof(pv0), sizeof(pv1), sizeof(pv2));
    pi = &i; pc0 = &y; pc1 = x;
    pv0 =  &i; pv1 = &y; pv2 = &x[0];
    printf("all pointer after  pointing to values \n");
    printf("pi=%li, pc0=%li, pc1=%li, pv0=%li, pv1=%li, pv2=%li \n",sizeof(pi),sizeof(pc0),sizeof(pc1),sizeof(pv0), sizeof(pv1), sizeof(pv2));
    printf("%i \n", *(int *)pv0);
    return 0;
}