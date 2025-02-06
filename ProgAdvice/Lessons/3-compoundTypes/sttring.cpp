#include "header_comp.h"

void stringMethods()
{
    char w[] = "object";
    string str0 = "just a string for practice cpp string object/";
    cout << "string str0:\t" << str0 << endl;
    str0.pop_back();
    str0.append(" methods");
    str0.push_back('.');
    int idx =str0.find("cpp string");
    str0.insert(idx, "the ");
    cout << "string str0:\t" << str0 << endl;
    cout << "str0.at(0): " << str0.at(0)<<endl;
    //  searching about word does not exist like `Object` with upper case `O`
    cout <<"str0.find(\"Object\"): " << str0.find("Object")<< endl;
    // check if the word is exist
    LLI res = str0.find(w);
    if ( res == str0.npos) printf("word `%s` is not  exist ", w);
    else printf("word `%s` exist at index `%lli`", w, res);

    char c1 ;
    char c2 ;
    c1 = toupper('a');
    c2 = tolower('A');
    cout << "converting a to A: " << c1 << endl;
    cout << "converting A to a: " << c2 << endl;
    // Digits (A to Z)
    // returns zero if not, and non zero of yes
    cout << "isupper('A') " << isupper( 'A') << endl;
    // lower case (a to z)
    // returns zero if not, and non zero of yes
    cout << "islower('A') " << islower('A') << endl;
    // Digits (0 to 9)
    // returns zero if not, and non zero of yes
    cout << "isdigit('A') " << isdigit ('A') << endl;
    // punctuation characters are !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
    // returns zero if not, and non zero of yes
    cout << "ispunct('A') " << ispunct('A') << endl;
}
void lessStrMethods()
{
    string S1= "My Name is Mohammed Abu-Hadhoud, I Love\
    Programming.";
    //Prints the length of the string
    cout << S1.length() << endl;
    //Returns the letter at position 3
    cout << S1.at(3) << endl;
    //Adds @ProgrammingAdvices to the end of string
    S1.append(" @ProgrammingAdvices");
    cout << S1 << endl;
    //inserts Ali at position 7
    S1.insert(7, " Ali ");
    cout << S1 << endl;
    //Prints all the next 8 letters from position 16.
    cout << S1.substr(16,8) << endl;
    //Adds one character to the end of the string
    S1.push_back('X');
    cout << S1 << endl;
    //Removes one character from the end of the string
    S1.pop_back();
    cout << S1 << endl;
    //Finds Ali in the string
    cout << S1.find("Ali") << endl;
    //Finds ali in the string
    cout << S1.find("ali") << endl;
    if (S1.find("ali") == S1.npos)
    {
    cout << "ali is not found";
    }
    //clears all string letters.
    S1.clear();
    cout << S1 << endl;

}