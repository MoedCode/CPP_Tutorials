#include<iostream>
#include <typeinfo>
using namespace std;

int main()
{

    auto i (0);
     auto numb(5);
     cout <<++i <<"- number : " <<numb << " number type: " << typeid(numb).name()<< endl;
     auto numb2 (5.5);
     cout <<++i <<"- number : " <<numb2 << " number type: " << typeid(numb2).name()<< endl;
     auto numb3 (0xf);
     cout <<++i <<"- number : " <<numb3 << " number type: " << typeid(numb3).name()<< endl;
     auto c ('H');
     cout <<++i <<"- char : " <<c << " number type: " << typeid(c).name()<< endl;
     auto cp ("HI!");
     cout <<++i <<"- char p : " <<cp << " number type: " << typeid(cp).name()<< endl;

}