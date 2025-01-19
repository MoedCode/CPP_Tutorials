int  printarr_2Dstr(char **arr, size_t size, char  *indent, char *endln)
{
    size_t i;
    size = (size_t)size;
    // string buff2print;
    // indent = !indent ? "\n" : indent;


    size = (size_t)size;

    cout <<"{" << indent;

    for (i = 0; i < size; i++ )
        {

            cout <<'['<< i << "]=" << arr[i] ;

            cout << (i < size - 1 ? ", " : "");
            cout <<  endln;


        }
    cout << indent<<"}"  << endl;

    return  (int)i;
}