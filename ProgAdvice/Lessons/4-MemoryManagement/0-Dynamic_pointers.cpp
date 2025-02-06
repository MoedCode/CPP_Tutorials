#include "header_MM.h"
void Dynamic_pointers0()
{
        int *Iptr = new int;
    float *Fptr = new float;
    *Iptr = 45;
    *Fptr = 58.35f;
    cout << "*Iptr: " << *Iptr<< endl;
    // delete Iptr;
    free(Iptr);
    cout << "*Fptr: "<<*Fptr <<  endl;
    delete Fptr;
    cout << ": " << endl;
}

