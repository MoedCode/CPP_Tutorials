that program drow letter H on terminal  with given
height , width, wrod or charcter to print with
the issue when i use in letter   `10 50 m` wrks cprrectly
when i use tow leeters '10 50 mo' works but the H shape does not printed corectly
overthan tow letters there areprobem i cant understand


```sh
mohamed@DESKTOP-S296B4S /mnt/c/Users/Active/Desktop/Coding/Gradutaion/CPP/Toturial0
 % g++ -o 1-Lesson12 1-Lesson12.cpp && ./1-Lesson12 10 50 m
m                                                m
m                                                m
m                                                m
m                                                m
m                                                m
mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
m                                                m
m                                                m
m                                                m
m                                                m
mohamed@DESKTOP-S296B4S /mnt/c/Users/Active/Desktop/Coding/Gradutaion/CPP/Toturial0
 % g++ -o 1-Lesson12 1-Lesson12.cpp && ./1-Lesson12 10 50 mo
mo                                                                                                  mo
mo                                                                                                  mo
mo                                                                                                  mo
mo                                                                                                  mo
mo                                                                                                  mo
momomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomomo
mo                                                                                                  mo
mo                                                                                                  mo
mo                                                                                                  mo
mo                                                                                                  mo
mohamed@DESKTOP-S296B4S /mnt/c/Users/Active/Desktop/Coding/Gradutaion/CPP/Toturial0
 % g++ -o 1-Lesson12 1-Lesson12.cpp && ./1-Lesson12 10 50 moh
mohMA��C�                                                                                                                                                    mohMA��C�
mohMA��C�                                                                                                                                                    mohMA��C�
mohMA��C�                                                                                                                                                    mohMA��C�
mohMA��C�                                                                                                                                                    mohMA��C�
mohMA��C�                                                                                                                                                    mohMA��C�
mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�mohMA��C�
mohMA��C�                                                                                                                                                    mohMA��C�
mohMA��C�                                                                                                                                                    mohMA��C�
mohMA��C�                                                                                                                                                    mohMA��C�
mohMA��C�                                                                                                                                                    mohMA��C�
*** stack smashing detected ***: terminated
zsh: abort (core dumped)  ./1-Lesson12 10 50 moh
mohamed@DESKTOP-S296B4S /mnt/c/Users/Active/Desktop/Coding/Gradutaion/CPP/Toturial0

```
# ASKII
int this function that print ASCII ...  there are an some small issues
1 it soesnt print none printable charcters .. like /t /a ad so on
 ```cpp

 #include <cstdlib>
#include <iostream>
using namespace std ;
int print_sakii(int start=0,  int end=127, int indent=0)
{

    int i = 0;
    cout << "ASKII From " << start  << " to " << end << "  :\n {";
    if (indent)
        cout << endl;

    for (;start <= end ; start ++)
    {
        i++;

        if ( i == indent)
        {
            cout << endl;
            i = 0;
        }
        if (start == 10)
        {
            cout << "[10]= \\n, ";
            continue;
        }
        printf("[%i]= %c, " , start, start);
    }
    if (indent)
        cout << endl;

    cout << "}\n";
    return start;

}
int main(int argc, char **argv)
{
    int i, j, indent;

    for (int k = 0; k < argc; k++)
        cout << "  => " << argv[k] ;
    cout <<endl;
    if (argv && argv[1] && argv[2])
    {
        i  = atoi(argv[1]);
        j  = atoi(argv[2]);


    }

    if (argv && argv[2] )
        j  = atoi(argv[2]);
    if (argv && argv[3])
        indent = atoi(argv[3]);
    cout << "i, j, indent: " << i << ", " <<j << ", " <<  indent << endl;
    print_sakii(i, j , indent);
    return  0;
}
```
```sh
mohamed@DESKTOP-S296B4S /mnt/c/Users/Active/Desktop/Coding/Gradutaion/CPP/alzero
 % g++ -o ASKII ASKII.cpp &&  ./ASKII 0 127 10
  => ./ASKII  => 0  => 127  => 10
i, j, indent: 0, 127, 10
ASKII From 0 to 127  :
 {

[0]= , [1]= , [2]= , [3]= , [4]= , [5]= , [6]= , [7]= , [8]=,
, [14]= , [15]= , [16]= , [17]= , [18]= ,
[19]= , [20]= , [21]= , [22]= , [23]= , [24]= , [25]= , [26]= , [27]= 28]= ,
[29]= , [30]= , [31]= , [32]=  , [33]= !, [34]= ", [35]= #, [36]= $, [37]= %, [38]= &,
[39]= ', [40]= (, [41]= ), [42]= *, [43]= +, [44]= ,, [45]= -, [46]= ., [47]= /, [48]= 0,
[49]= 1, [50]= 2, [51]= 3, [52]= 4, [53]= 5, [54]= 6, [55]= 7, [56]= 8, [57]= 9, [58]= :,
[59]= ;, [60]= <, [61]= =, [62]= >, [63]= ?, [64]= @, [65]= A, [66]= B, [67]= C, [68]= D,
[69]= E, [70]= F, [71]= G, [72]= H, [73]= I, [74]= J, [75]= K, [76]= L, [77]= M, [78]= N,
[79]= O, [80]= P, [81]= Q, [82]= R, [83]= S, [84]= T, [85]= U, [86]= V, [87]= W, [88]= X,
[89]= Y, [90]= Z, [91]= [, [92]= \, [93]= ], [94]= ^, [95]= _, [96]= `, [97]= a, [98]= b,
[99]= c, [100]= d, [101]= e, [102]= f, [103]= g, [104]= h, [105]= i, [106]= j, [107]= k, [108]= l,
[109]= m, [110]= n, [111]= o, [112]= p, [113]= q, [114]= r, [115]= s, [116]= t, [117]= u, [118]= v,
[119]= w, [120]= x, [121]= y, [122]= z, [123]= {, [124]= |, [125]= }, [126]= ~, [127]= ,
}
mohamed@DESKTOP-S296B4S /mnt/c/Users/Active/Desktop/Coding/Gradutaion/CPP/alzero
 % g++ -o ASKII ASKII.cpp &&  ./ASKII 0 127 20
  => ./ASKII  => 0  => 127  => 20
i, j, indent: 0, 127, 20
ASKII From 0 to 127  :
 {
[0]= , [1]= , [2]= , [3]= , [4]= , [5]= , [6]= , [7]= , [8]=, [9]=        , [10]= \n, [11]= ,, [14]= , [15]= , [16]= , [17]= , [18]= ,
[19]= , [20]= , [21]= , [22]= , [23]= , [24]= , [25]= , [26]= , [27]= 28]= , [29]= , [30]= , [31]= , [32]=  , [33]= !, [34]= ", [35]= #, [36]= $, [37]= %, [38]= &,
[39]= ', [40]= (, [41]= ), [42]= *, [43]= +, [44]= ,, [45]= -, [46]= ., [47]= /, [48]= 0, [49]= 1, [50]= 2, [51]= 3, [52]= 4, [53]= 5, [54]= 6, [55]= 7, [56]= 8, [57]= 9, [58]= :,
[59]= ;, [60]= <, [61]= =, [62]= >, [63]= ?, [64]= @, [65]= A, [66]= B, [67]= C, [68]= D, [69]= E, [70]= F, [71]= G, [72]= H, [73]= I, [74]= J, [75]= K, [76]= L, [77]= M, [78]= N,
[79]= O, [80]= P, [81]= Q, [82]= R, [83]= S, [84]= T, [85]= U, [86]= V, [87]= W, [88]= X, [89]= Y, [90]= Z, [91]= [, [92]= \, [93]= ], [94]= ^, [95]= _, [96]= `, [97]= a, [98]= b,
[99]= c, [100]= d, [101]= e, [102]= f, [103]= g, [104]= h, [105]= i, [106]= j, [107]= k, [108]= l, [109]= m, [110]= n, [111]= o, [112]= p, [113]= q, [114]= r, [115]= s, [116]= t, [117]= u, [118]= v,
[119]= w, [120]= x, [121]= y, [122]= z, [123]= {, [124]= |, [125]= }, [126]= ~, [127]= ,
}
mohamed@DESKTOP-S296B4S /mnt/c/Users/Active/Desktop/Coding/Gradutaion/CPP/alzero
 %

```
```cpp

#include <cstdlib>
#include <iostream>
#include <functional>
#include <map>
using namespace std;

// Define a function type for mathematical operations
typedef int (*OperationFunc)(int, int);

// Define mathematical operation functions
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return (b != 0) ? a / b : throw runtime_error("Division by zero"); }
int modulo(int a, int b) { return (b != 0) ? a % b : throw runtime_error("Modulo by zero"); }
int power(int a, int b) { return a ^ b; } // XOR as an example

// Define a struct for operators
struct Operator {
    char symbol;
    OperationFunc operation;
};

// Array of operators and their corresponding functions
Operator operations[] = {
    {'+', add},
    {'-', subtract},
    {'*', multiply},
    {'/', divide},
    {'%', modulo},
    {'^', power}
};

int main(int argc, char **argv)
{
    if (argc < 4) {
        cerr << "Usage: ./program num1 operator num2\n";
        return -1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);
    char sign = argv[2][0];

    // Find the operation corresponding to the given operator
    OperationFunc selectedOperation = nullptr;
    for (const auto& op : operations) {
        if (op.symbol == sign) {
            selectedOperation = op.operation;
            break;
        }
    }

    if (!selectedOperation) {
        cerr << "Invalid operator: " << sign << "\n";
        return -2;
    }

    try {
        int result = selectedOperation(num1, num2);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return -3;
    }

    return 0;
}


```

this program shold dorow mattrix from a word passed to it like

all args passed
./ternary 5 5 x
xxxxx
xxxxx
xxxxx
xxxxx
xxxxx
just one anumber args passed print square matrix  and  no watermark
so the waer mark will be program name wituout ./
./ternary 5
 ternary ternary ternary ternary ternary
 ternary ternary ternary ternary ternary
 ternary ternary ternary ternary ternary
 ternary ternary ternary ternary ternary
 ternary ternary ternary ternary ternary

 if tow number paased but no watermark
 ./ternary 3 5
 ternary ternary ternary ternary ternary
 ternary ternary ternary ternary ternary
 ternary ternary ternary ternary ternary
but acual result and code

```sh

 % g++ -o ternary ternary.cpp && ./ternary 5
zsh: segmentation fault (core dumped)  ./ternary 5
mohamed@DESKTOP-S296B4S /mnt/c/Users/Active/Desktop/Coding/Gradutaion/CPP/alzero
 % cat ternary.cpp
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
// #include <string>
using namespace std;

int main(int argc, char **argv)
{
    int height, width, vh , vw, argC;
    string watermarck;
    argC = argc > 4 ? 4 : argc;
    switch(argC)
    {
        case 1:
            return  0;
        break;
        case 2:
        {
            height = width  = atoi(argv[1]);
            watermarck = argv[0];
        }
        case 3:
            {
                if (atoi(argv[2]) && atoi(argv[2]))
                    {
                        height =  atoi(argv[1]);
                        width = atoi(argv[2]);
                        watermarck = argv[0];
                    }
                    if (atoi(argv[1]))
                    {
                        width = height = atoi(argv[1]);
                        watermarck = argv[2];
                    }
                    if (atoi(argv[2]))
                    {
                        width = height = atoi(argv[2]);
                        watermarck = argv[1];
                    }
                cout << atoi(argv[1]) << "\t" <<atoi(argv[2]) << endl;

            }

    }
    for (vh = 0; vh < height; vh++)
        for (vw = 0; vw < width; vw++)
            cout << watermarck;






    return 0;
}%
mohamed@DESKTOP-S296B4S /mnt/c/Users/Active/Desktop/Coding/Gradutaion/CPP/alzero

```

# this should be a generic fuctio print arrays so if i call function on array
## numbers arrays
int arr = {1, 2,3};
print_arr("`{%i , }`", arr);
it prints // {1, 2, 3}
print_arr("`%i , `", arr);
it prints // 1, 2, 3
print_arr("`[$]=%i, `", arr);
it prints  // [0]=1, [1]=2, [2]=3
print_arr("`{[$]=%i,} `", arr);
it prints  // {[0]=1, [1]=2, [2]=3 }
sme for double folat
## in  case of string arrays
string names[] = {"username1", "username2", "username3"}
print_arr("`{[$]=%s,} `", arr);
it prints  // {[0]="username1", [1]="username2", [2]="username3" }
and so on ..
it also should  case handle if user print char or normal string
if user not ass format specifir
it should alos handle cstle or  cpp style arrays from all types
```cpp

int print_array(string format , void **arr, size_t size)
{
    int *intptr,  mode ;

    string befIdx, afterIdx ;
    for (int i = 0; format[i]; i++)
    {
        cout << format[i] ;

            if(format[i] == '`')
            {
                for(size_t j = (i + 1) , k = 0; format[j] !='`'; j++, k++ )
                    {
                        if (!mode)
                        {
                            befIdx[k] = format[j];
                            if(format[j] == '%')
                            {
                                mode = 1;
                                j +=2;
                                k = 0;
                            }
                            else {
                                afterIdx = format[j];

                            }
                        }
                    }
                    continue;
            }
        if (format[i] == '%')
        {


            if(format[i + 1] == 'i' || format[i + 1] == 'd')
            {
                intptr = (int *) *arr;
                for (size_t a = 0; size; i++)
                    cout << befIdx << intptr[i] << afterIdx;

            }
            else if (format[i + 1] == 's')
             {

                for (size_t a = 0; size; i++)
                    // char **charptr = (char **) *arr;
                    string *str = (string *) *arr;
                    cout << befIdx << str[i] << afterIdx;

             }
        }

        for (size_t a = 0; size; i++)
        {
            cout << befIdx << arr[i] << afterIdx;
        }
    }
return  0;

}

```