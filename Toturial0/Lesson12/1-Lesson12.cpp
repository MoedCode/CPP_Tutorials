#include<iostream>
#include<math.h>
int main( int argc, char** argv)
{

    int vh = 0, vw = 0, height = 5, width = 7;
    char to_print[] = "*";
    if(argv[1])
        if(atoi(argv[1]))
            height = atoi(argv[1]);
    if(argv[2])
        if(atoi(argv[2]))
            width = atoi(argv[2]);
    if(argv[3])
    {   int j = 0;


        for(int i = 0; argv[3][i]!= '\0'; i++)
        {

            if (argv[3][i] == '\n')
                break;
            to_print[i] = argv[3][i];
            j++;
        }
        width = width * j;
    }
    int mid = height/2 ;

    for (; vh < height; vh++)
    {

        for (vw = 0; vw < width; vw++)
        {
            if (vw == 0 || vw == width - 1)
                std::cout << to_print;
            else if (vh == mid)
                std::cout << to_print;
            else
                std::cout << ' ';

        }
        std::cout << '\n';

    }
    return 0;
}