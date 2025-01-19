#include "vector.h"
I PrintIArr(I * arr, I size, CC* msg, I cast)
{   if (msg)
        cout << msg ;
    if (!size)
         printf("-- size: %i \n", size);

    if (!arr)
         printf("{NULL}\n");
    if (!arr || !size)
        return !arr ? -1 :  -2;
    for (I i = 0; i <size; i++)
        {

            if (cast)
                printf("[%i]=%c ", i, arr[i]);
            else
                printf("[%i]=%i", i, arr[i]);;
            if (i < size - 1)
                cout << ", ";
        }
    cout << endl;
    return 0;
}
void vectors()
{
    I numbers[] {10, 20, 30, 40};
    PrintIArr(numbers, size(numbers), "Numbers: ");
    vector<I> numbers1 = {10, 20, 30, 40};
    vector<I> numbers2 {10, 20, 30, 40};
    vector<I> numbers3(4, 1);
    numbers3.push_back(40);
    // numbers[5]=4;
    PrintIArr(numbers, size(numbers), "Numbers: ");

    cout << "numbers.size(): " << numbers1.size() << endl;
    cout << "last index " << numbers1[3] << endl;
    PrintIArr(numbers1.data(), numbers1.size(), "Numbers1: ");
    PrintIArr(numbers3.data(), numbers3.size(), "Numbers3: ");

}
I arr_cls()
{
     I numbers[] {10, 20, 30, 40};
    PrintIArr(numbers, size(numbers), "carray bef: ");
    // numbers[5]=4;

    array<I, 4> numbers4{1, 2, 3, 4};

    PrintIArr(numbers, size(numbers), "carray aft: ");
    numbers4[3] = 50;
    numbers4[4] = 60;
    PrintIArr(numbers4.data(), size(numbers), "cpp rray after [4] = 60: ");
    numbers4.at(4)=60;
    PrintIArr(numbers4.data(), size(numbers), "cpp rray after .at(4)=60: ");


    return  0;
}
void vectVSarr()
{
    I num_arr[] {10, 20, 30, 40};
    vector<I> vnums = {1, 2, 3, 4};
    array<I, 4> numb_arr_cls = {100, 200, 300, 400};
    I vsize = vnums.size(), asize = size(num_arr), acsize = numb_arr_cls.size();
    cout << "PrintIArr in poundery\n";
    printf("array: %i \n", num_arr[asize -1]);
    printf("array cls: %i \n", numb_arr_cls[acsize -1]);
    printf("vwctor: %i \n", vnums[vsize -1]);
    cout << "PrintIArr out of poundery\n";
    printf("array: %i \n", num_arr[asize]);
    printf("array cls: %i \n", numb_arr_cls[acsize]);
    printf("vwctor: %i \n", vnums[vsize]);
    cout << "PrintIArr in poundery using at\n";
    printf("array cls: %i \n", numb_arr_cls.at(acsize -1));
    printf("vwctor: %i \n", vnums.at(vsize -1));
    /*
        cout << "PrintIArr out of poundery  using at\n";
        printf("array cls: %i \n", numb_arr_cls.at(acsize));
        printf("vwctor: %i \n", vnums.at(vsize));

        terminate called after throwing an instance of 'std::out_of_range'
        what():  array::at: __n (which is 4) >= _Nm (which is 4)
        zsh: abort (core dumped)  ./main
    */
    cout << "ubdate using at\n";
    vnums.at(vsize - 1) = 9;
    numb_arr_cls.at(acsize - 1) = 900;

    printf("array cls: %i \n", numb_arr_cls.at(acsize - 1));
    printf("vwctor: %i \n", vnums.at(vsize - 1));
    cout << "\n\n push baclk\n";
    PrintIArr(vnums.data(), vnums.size(), "vector before: ");
    vnums.push_back(4);
    PrintIArr(vnums.data(), vnums.size(), "vector after: ");

    printf("vector: %i, size: %li \n", vnums.at(vnums.size() -1 ), vnums.size());
    cout << "\n\n pop baclk\n";
    vnums.pop_back();

    printf("vector: %i, size: %li \n", vnums.at(vnums.size() -1), vnums.size());
}
void vecfun()
{
    vector<I> vnums = {1, 2, 3, 4};
    PrintIArr(vnums.data(), vnums.size(), "vector before: ");

    printf("vnums.front(): %i\n",vnums.front());
    printf("vnums.back(): %i\n",vnums.back());

    // vnums.clear();
    cout << "size " << vnums.size() << "  ";
   I  x =  PrintIArr(NULL, vnums.size(), "vector after: ");
   cout << x << endl;

    cout << "show how much memeory used  to instantiate vector \n";
    printf("vnums.capacity(): %li \n",vnums.capacity());
    printf("vnums.max_size(): %li \n",vnums.max_size());
    printf("Maximum size in GB:    %zu\n", vnums.max_size() /(size_t) pow(1024, 4));

}
I vector_iterator()
{
/*

    I *ptr  = &vnums[0];

    cout << "=>p " <<  *ptr << '\n';
    // ptr = (ptr+ 2); // incdnrement pointer itself
    cout << "=>p " <<  *(ptr+ 2) << '\n';
*/

    vector<I> vnums = {10, 20, 30, 40, 'a'};
    PrintIArr(vnums.data(), vnums.size(), "vector before: ");
    // start from first index
    vector<I>::iterator idx = vnums.begin();
    // step number
    auto step = vnums.begin() + 1;
    // use iterator
    cout << "=> " <<  *idx << '\n';
    // vnums.erase(vnums.begin() , vnums.begin() + 3);
    PrintIArr(vnums.data(), vnums.size(), "vector after: ");
    cout <<  "\n ====  traversing  ==== \n";
    VII first = vnums.begin();
    VII last = vnums.end() -1;
    /*vector<I>::iterator last_ = vnums.end();
     printf("first %i last %i \n ", *first, *(last_ -1));
     we can use last = last - 1; pr last -- ; last -= 1 */

    printf("first %i last %i \n ", *first, *last );
    // for (I *f = first, *l = last; f < l; f++)

    for (VII fptr = first; fptr < last;)
    {
        printf(" =>%i, ",  *fptr );
        fptr++;

    }
    cout << endl;
    cout <<  "\n ====  more simple syntax  ==== \n";
    vector<I> vnum1 = {100, 200, 300, 400, '$'};
    VII itr1;
    for (itr1 = vnum1.begin(); itr1 < vnum1.end(); ++itr1)
        printf("%i, ", *itr1);
    cout << endl;
    cout <<  "\n ====  for loop simple  short syntax c int.char * array ==== \n";


    I nums[] {1, 2, 3, 4, 'a'};
    CC *cparr[] =  {"♂","7", "▬", "☺" , "▶︎", ":ok: "};
    cout << "---fot in--- \n";
    for (I num : vnums)
        cout << num << ", ";
    cout << endl;
    for (CC *cp : cparr)
        cout <<"" << cp << "=>" << strlen(cp) << " bytes" << "\t ";
    cout << endl;
    return 0;
}

I cls_arr()
{
    array <I, 4> anums[]{1, 2, 3, 4, 'a'};
    I nums[]{1, 2, 3, 4, 'a'};
    cout << "---fot in--- \n";
    array<I,4> ::iterator AII;
    I *Iptr;
    C *Cptr;
    cout << "I *Iptr: " << typeid(Iptr).name() << endl;
    cout << "C *Cptr: " << typeid(Iptr).name() << endl;

    // for ()
    //     cout << num << ", ";

    return 0;
}