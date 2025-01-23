#include  "header_b.h"
/*
template <typename Type>
Type bitwise(Type arg1, Type arg2, char logOp )
{
    (!arg1 || !arg2 || logOp  )? exit(-1):(void)0;



}
*/
string binary(unsigned int num, int width=16) {
    string binaryStr; // String to store the binary representation
    for (int i = width - 1; i >= 0; i--) {
        binaryStr += ((num >> i) & 1) ? '1' : '0'; // Append '1' or '0' to the string
    }
    return binaryStr; // Return the binary string
}
void logicAndOr(void)
{
    int n1 = 10, n2 = 2, n3 = 0;

    print(" values of n1=> {}, n2=> {}, n3=> {}", n1, n2, n3);
    cout << "(n1 && n2)=> " << (n1 && n2)<< endl;
    cout << "(n1 || n2)=> " << (n1 || n2)<< endl;
    cout << "(n1 && n3)=> " << (n1 && n3)<< endl;
    cout << "(n1 || n3)=> " << (n1 || n3)<< endl;


}
void bitwise(void)
{
    int n1 = 10, n2 = 2, n3 = 0;

    print(" values of n1=> {}, n2=> {}, n3=> {}", n1, n2, n3);

    print("binary values for \n n1=> {},\n n2=> {},\n n3=> {}",
    binary(n1, 16), binary(n2, 16),
    binary(n2, 16)
    );

    cout << "(n1 & n2)=> " << (n1 & n2)<< endl;
    cout << "(n1 | n2)=> " << (n1 | n2)<< endl;
    cout << "(n1 & n3)=> " << (n1 & n3)<< endl;
    cout << "(n1 | n3)=> " << (n1 | n3)<< endl;
}
