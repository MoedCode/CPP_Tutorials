#include <iostream>
#include <bitset>
#include <string>
#include <cstdint>
using namespace std;

// Function to return binary representation as a std::string
string Binary(uint64_t number, int systemType) {
    // Validate system type
    if (systemType != 8 && systemType != 16 && systemType != 32 && systemType != 64 && systemType != 128) {
        cerr << "Error: Invalid system type. Must be 8, 16, 32, 64, or 128." << endl;
        return "";
    }

    // Calculate the number of bits required
    int bitWidth = systemType;

    // Mask the number to the specified bit width (prevent overflow display)
    uint64_t mask = (1ULL << bitWidth) - 1;
    number &= mask;

    // Create a binary string representation using bitset
    bitset<128> binary(number); // Use 128 bits to handle all system types
    string binaryStr = binary.to_string().substr(128 - bitWidth);

    return binaryStr;
}

int main() {
    // Test cases
    cout << "8-bit: " << Binary(255, 8) << endl;
    cout << "16-bit: " << Binary(65535, 16) << endl;
    cout << "32-bit: " << Binary(4294967295, 32) << endl;
    cout << "64-bit: " << Binary(1844674407370955161, 64) << endl;
    // cout << "128-bit: " << Binary(340282366920938463463374607431768211455ULL, 128) << endl;

    return 0;
}