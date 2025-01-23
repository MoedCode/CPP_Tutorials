#include <iostream>

using namespace std;
namespace scanlib
{
template <typename T>

T getInput(const string& message) {
    T value;
    cout << message; // Display the message
    cin >> value;    // Get user input
    return value;         // Return the input
}
}