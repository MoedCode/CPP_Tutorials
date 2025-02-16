

#include "headerLev2.h"


// Dummy password to crack
const char *thePWD = "A$D@Z";

bool check_PWD(ccp PWD) {
    return !strcmp(PWD, thePWD);
}

ccp crackPWD(size_t size , bool useMaxTrial, size_t maxTrial) {

    static string word; // Start with all spaces
    static string msg;
    if(!msg.empty()) msg.clear();
    if(!word.empty()) word.clear();
    word = string(size, ' ');
    size_t trials = 0;

    while (true) {
        trials++;

        // Check if the generated password is correct
        // cout << word ;  (trials % 20 == 0) ?cout <<  '\n':cout <<'\t';
        if (check_PWD(word.data())) {
            putchar(10);
            msg = "Password is " + word + "\nFound after " + to_string(trials) + " Trial(s)" +
            "\n maxTrial:"+to_string(maxTrial);
            return msg.data();
        }
        if(trials == maxTrial && useMaxTrial)
        {
            msg ="reached ma trial " + to_string(maxTrial) + "lastword[" + word + ']';
            return msg.data();
        }
        // Generate the next sequence (like counting in base-95)
        size_t pos = size - 1;
        while (true) {
            if (word[pos] < 126) { // Increment character
                word[pos]++;
                break;
            } else { // Reset current position and move to the left
                word[pos] = 32;
                if (pos == 0) return "Password not found"; // Shouldn't happen unless length is insufficient
                pos--;
            }
        }
    }
}

// int main() {
//     cout << crackPWD(5) << endl; // Trying to crack a 3-character password
//     return 0;
// }
