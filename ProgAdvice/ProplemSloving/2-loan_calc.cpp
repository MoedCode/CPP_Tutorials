#include "promptlib.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace promptlib;

typedef const char *  CCP;
string ResType;

LD calcLoan(CCP toGet=NULL ,LD arg1 = 0 , LD arg2 = 0)
{
    LD LoanAmount = 0, monthInst = 0 ,months = 0;
    string  options =  " amount or installment or time ";
    if (toGet == NULL)
    {

        int res = 0;
        string prompt ;
        while(res == prompt.npos || res == 0)
        {

        cout << "result you want to calculate\n " + options + ":";
        cin >> prompt;

         res = options.find(prompt);
        }
        toGet = prompt.data();
        ResType = prompt;
    }
    cout << toGet << " " << LoanAmount << " " << monthInst << endl;
    int isValid = 0;
    if(!strcmp(toGet, "time"))

    {
        LoanAmount = arg1; monthInst = arg2;
        if (LoanAmount > 0 && monthInst >0 && monthInst < LoanAmount)
            return LoanAmount/monthInst;
        LoanAmount = getPosDouble("Loan Total Amount: ");
        while( !isValid)
        {
            monthInst =getPosDouble("Monthly loan installment : ");
            if (monthInst > LoanAmount)
                 printf("E: installment %Lf < total amount %Lf \n",
                 monthInst, LoanAmount);
            else
                isValid = 1;
        }
        return LoanAmount/monthInst;

    }
    if(!strcmp(toGet, "amount"))
    {

        monthInst = arg1;  months = arg2;
        monthInst =getPosDouble("Monthly loan installment : ");
        months  = getPosDouble("months number: ");

        return  monthInst * months;
    }
    if(!strcmp(toGet, "installment"))
    {
        LoanAmount = arg1; months = arg2;
        LoanAmount = getPosDouble("Loan Total Amount: ");
        months  = getPosDouble("months number: ");

        return  LoanAmount / months;
    }

    return 0;
}
int main(int argc, CCP argv[])
{
    string  options =  " amount , installment , time ",
     msg = "value wanted to be calculated on of <" + options + "> \n then provide other values same order"+
       " example if time is wanted amount 5000 installment 500 type \" time 5000  500 \" ";
       string O = "-h h help -help --help --h";
    if(argv[1])
        if (O.find(argv[1]) != O.npos)
        {
            cout << msg;
            return 0;
        }
    if (argc >= 4)
        {

            if (options.find(argv[1]) == options.npos)
                cout << msg;
            else if (!atoi(argv[2] )|| !atoi(argv[3]))
                cout << msg;
            else
             {
                LD res =
                calcLoan(argv[1],atoi(argv[2]), atoi(argv[3]));
                printf("%s : %Lf\n", argv[1], res);
                return 0;
             };
        }
    LD x  =  calcLoan();
//    cout << "Loan "+ ResType + ": "  << x  <<  "\n" ;
   printf("Loan %s : %Lf \n", ResType.data(), x);
    return 0;
}