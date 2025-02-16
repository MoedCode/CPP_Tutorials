#include <iostream>
#include <cstring>
#include <string>
using namespace std;

typedef const char* ccp;

struct Hashed {
    ccp data;
    const size_t size;
    const short key;
};

// Simple Hash Function (Shift ASCII Values)
Hashed strHash(ccp str, short key=2) {
    static string word; // Static to persist after function return
    word.clear();

    for (; *str; ++str) {
        word.append(to_string(*str << key)); // Shift ASCII left by 2
        word.push_back('.');
    }

    if (!word.empty()) word.pop_back(); // Remove last '.'

    const Hashed hashedWord = {
        word.c_str(), word.size(), key
    };
    // hashedWord.data = word.c_str();
    // hashedWord.size = word.size();
    // hashedWord.key = key;
    return hashedWord;
}

// Reverse Hash Function (Shift ASCII Values Back)
ccp hashReversal(Hashed hashStruct) {
    static string word;
    word.clear();

    char* copy = new char[hashStruct.size + 1]; // Allocate memory
    strcpy(copy, hashStruct.data);

    char* token = strtok(copy, ".");
    while (token != nullptr) {
        int value = atoi(token) >> hashStruct.key; // Reverse the shift
        word.push_back((char)value);
        token = strtok(nullptr, ".");
    }

    delete[] copy; // Free memory
    return word.c_str();
}

// Main Function
int main(int argc, char* argv[]) {
    if (argc < 3 || !atoi(argv[2])) {
        cout << "Usage: ./program <string><4 digit integer encryption key>\n";
        return 1;
    }
    // short k  = 9999;
    Hashed x = strHash(argv[1], atoi(argv[2]));
    ccp reversed_x = hashReversal(x);

    cout << "Before hashing  => " << argv[1] << endl;
    cout << "After hashing   => " << x.data << endl;
    cout << "After reversal  => " << reversed_x << endl;

    return 0;
}
