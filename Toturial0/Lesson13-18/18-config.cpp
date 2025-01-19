#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    // Allocate memory for each string
    char name[100], email[100], age[10], gender[10];

    // Input from the user
    cout << "age: "; cin >> age;
    cout << "gender: "; cin >> gender;
    cout << "name: "; cin >> name;
    cout << "email: "; cin >> email;

    // Open the file for appending

    FILE *f = fopen("usersdata.md", "a");
    if (f == nullptr) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Dynamic keys and values
    const char *keys[] = {"name", "email", "age", "gender"};
    const char *values[] = {name, email, age, gender};
    int entryCount = sizeof(keys) / sizeof(keys[0]);

    // Start JSON object
    fprintf(f, "```json \n {\n");

    // Dynamically write keys and values
    for (int i = 0; i < entryCount; i++) {
        fprintf(f, "  \"%s\": \"%s\"", keys[i], values[i]);
        if (i < entryCount - 1) fprintf(f, ",\n"); // Add comma if not the last entry
    }

    // End JSON object
    fprintf(f, "\n}\n```\n");

    fclose(f); // Close the file
    return 0;
}
