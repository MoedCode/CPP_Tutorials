#include "main.h"
#include <iterator>

string  strjoin(string str1,   string str2)
{   string buff = "";
    buff.append("str1: ");buff.append(str1);
    buff.append("\n");
    buff.append("str2: ");buff.append(str2);
    buff.append("\n");

    string appended = str1.append(str2) ;
    // cout  << "str2.assign(str1);"<<str2.assign(str1) << endl;
    buff.append(": 1-str1.append(str2) : \n " );
    buff.append(appended );
    buff.append("\n");

    buff.append(": str1.assign(str2); : \n " );
    buff.append(str1.assign(str2));

    buff.append("\n\n ------end-----\n\n").append("str1: ").append(str1)
    .append("\n str2: ").append(str2);

    return buff;
}
int str_pract1(void)
{
    string X, str1 = "mohamed " ,str2= "mahmoud", str3="";
    char charp1[] = "mohamed ", charp2[] =  "mahmoud", charp3[]="";

    // use c style string that allocated memory
    /*
    char *x =  c_strjoin("mohamed ", "mahmoud") ;
    X = x;
    free(x);
    */
    // X = strjoin("mohamed ", "mahmoud");
    cout << X << endl;
    printf(", X.size()[%li]\n", X.size());
    printf(", X.size()[%li]\n", X.size());
    printf(", int('A')=[%i], char(65)[%c]\n", int('A'), char(65));
    char xy[20] = "mohamed ";
    strcat(xy, "mahmoud");
    printf("C style [%s]\n", xy);
    string XY = "mohamed " ;
    XY.append( "mahmoud");
    cout << "c++ style => " << XY << endl;
    cout << "c++ concat string in cout => " << str1 + '\t' + str2<< endl;
    cout << "c++ concat string in cout => " << str1 + "\t" + str2<< endl;
    cout << "c++ concat string in cout => " << str1 + "\t"  +  charp2 << endl;
    cout << "size(str1) " <<size(str1) << endl;
    cout << "size(charp1) " <<size(charp1) << endl;
    cout << "size(intarr) " << size({1, 2, 3}) << endl;
    cout << std::size("sdasd") << endl;
    return 0;
}