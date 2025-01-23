#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <type_traits>
#include <vector>
#include <bitset>
#include <cstdint>
#include <limits>
#include <cmath>
using namespace std;

namespace printlib {
template <typename T>
string to_string(const T& value) {
    if constexpr (is_pointer_v<T>) {
        if (value == nullptr) {
            return "nullptr";
        }
        ostringstream oss;
        oss << value;
        return oss.str();
    } else if constexpr (is_array_v<T>) {
        ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < extent_v<T>; ++i) {
            if (i > 0) oss << ", ";
            oss << to_string(value[i]);
        }
        oss << "]";
        return oss.str();
    } else if constexpr (is_same_v<T, char>) {
        return string(1, value);
    } else {
        ostringstream oss;
        oss << value;
        return oss.str();
    }
}

inline int print_helper(ostream& os, const string& format, const vector<string>& args) {
    size_t pos = 0;
    size_t arg_index = 0;
    int char_count = 0;

    while (pos < format.size()) {
        if (format[pos] == '{' && pos + 1 < format.size() && format[pos + 1] == '}') {
            if (arg_index < args.size()) {
                os << args[arg_index];
                char_count += args[arg_index].size();
                arg_index++;
            } else {
                os << "{}"; // Leave as-is if no corresponding argument
                char_count += 2;
            }
            pos += 2; // Skip past {}
        } else {
            os << format[pos];
            char_count++;
            pos++;
        }
    }
    os << endl;
    char_count++; // For the newline character
    return char_count;
}

template <typename... Args>
int print(const char* format, Args... args) {
    vector<string> arg_strings = {to_string(args)...};

    if (format == nullptr || string(format).empty()) {
        // Print all arguments without formatting
        int char_count = 0;
        for (size_t i = 0; i < arg_strings.size(); ++i) {
            if (i > 0) {
                cout << ", ";
                char_count += 2;
            }
            cout << arg_strings[i];
            char_count += arg_strings[i].size();
        }
        cout << endl;
        char_count++; // For the newline character
        return char_count;
    } else {
        // Print with format
        return print_helper(cout, format, arg_strings);
    }
}
inline string Binary(uint64_t number, int systemType=64) {
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

} // namespace lib0
