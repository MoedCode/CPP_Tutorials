#include  "header_b.h"

void autovars()
{
    auto i = 5;
	auto j = 999999999999999999;
	auto s1 = "auto string s1";
	printf("int var [%i] , strvar[%s]\n", i, s1);
    bitset<32> binary(i); // 32 bits for a 32-bit integer
    cout << "Binary: " << binary << endl;

	s1 = "string s1 after has  been overwritten";
	i = 5llu;


	printf("int var [%i] , strvar[%s]\n", i, s1);
    bitset<23> binary2_i(i);
    cout << "Binary i: " << binary2_i << endl;
    bitset<23> binary_j(j);
    cout << "Binary j: " << binary_j << endl;
}