// #include <ios>
#include <cmath>

// #include <string>
#include <string>
#include <unordered_map>
// #include <vector>
#include "promptlib.h"
using namespace promptlib;
struct User{
    unordered_map<string  , string> data;
    void print_user()
    {
        if (data.empty())
            return;

        for (const auto &entry : data)
        {
            static int  i =0 ;
            // auto *ptr = &entry;
            (i < 1) ? cout << "{\t":cout <<"";
            cout << entry.first + " : " + entry.second  ;
            (i < (data.size() -1))? cout << ",  " : cout << "";

            ++i;
            (i == (data.size() ))? cout << "\t}\n": cout <<"";
            // cout << (*ptr).first + " : " + ptr->second + ", " << endl;


        }
    }
};
    enum modes  {R = ios::in, W = ios::out, A = ios::app, RA = ios::in | ios::app};
    enum prmVal {NotPrime  , Prime};

    prmVal isPrime( long long int N)
    {
        int M = 0, i = 2;
        if (N <= 0)
        {
            cerr << "number cant be negative or zero ";
            return NotPrime ;
        }
        if (N == 1)  return prmVal::Prime ;
        if (N == 2)  return prmVal::NotPrime ;

         M = N/2;
         for (; i < M ; i++)
            if(M % i == 0)
                return NotPrime;
        return  Prime;
    }
int main()
{
    // User  user0;
    // user0.data= {
    //     {"username","user0"}, {"email", "user0@example.com"},
    //     {"password","User0_PWD", }, {"age", "33"},{"income", "500B/M"}
    // };
    // user0.print_user();
    // cout << R << "\t" << W << "\t"<< A << "\t" << RA << endl;



    // cout <<"user0 size " + to_string(user0.data.size()) + '\n';
    // cout << "user0[\"username\"]: " + user0.data["username"] + '\n';
    // int x = 9;
    // (isPrime(x)) ? cout << "Prime\n" :  cout << "Not Prime\n";
   cout <<  "amount: "  << getPosDouble()  << "\n";
   cout <<  "amount type: "  << typeid(5.0).name() << "\n";
    return  0;
}

