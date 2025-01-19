#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

template <typename T>
void print_array(const std::string &format, const T *arr, size_t size) {
    std::string prefix, suffix;
    std::string parsedFormat = "";
    bool insideTicks = false;

    // Parse the format string
    for (size_t i = 0; i < format.size(); ++i) {
        if (format[i] == '`') {
            insideTicks = !insideTicks;
        } else if (insideTicks) {
            parsedFormat += format[i];
        } else if (!insideTicks && format[i] != '`') {
            if (prefix.empty()) {
                prefix += format[i];
            } else {
                suffix += format[i];
            }
        }
    }

    // Loop over the array and print each element
    for (size_t i = 0; i < size; ++i) {
        if (parsedFormat.find("[$]") != std::string::npos) {
            std::string indexedFormat = parsedFormat;
            size_t pos = indexedFormat.find("[$]");
            indexedFormat.replace(pos, 3, "[" + std::to_string(i) + "]");
            printf((prefix + indexedFormat + suffix).c_str(), arr[i]);
        } else {
            printf((prefix + parsedFormat + suffix).c_str(), arr[i]);
        }
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Specialized overload for string arrays
void print_array(const std::string &format, const std::string *arr, size_t size) {
    std::string prefix, suffix;
    std::string parsedFormat = "";
    bool insideTicks = false;

    // Parse the format string
    for (size_t i = 0; i < format.size(); ++i) {
        if (format[i] == '`') {
            insideTicks = !insideTicks;
        } else if (insideTicks) {
            parsedFormat += format[i];
        } else if (!insideTicks && format[i] != '`') {
            if (prefix.empty()) {
                prefix += format[i];
            } else {
                suffix += format[i];
            }
        }
    }

    // Loop over the array and print each element
    for (size_t i = 0; i < size; ++i) {
        if (parsedFormat.find("[$]") != std::string::npos) {
            std::string indexedFormat = parsedFormat;
            size_t pos = indexedFormat.find("[$]");
            indexedFormat.replace(pos, 3, "[" + std::to_string(i) + "]");
            printf((prefix + indexedFormat + suffix).c_str(), arr[i].c_str());
        } else {
            printf((prefix + parsedFormat + suffix).c_str(), arr[i].c_str());
        }
        if (i < size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Test cases
/*
int main() {
    int intArr[] = {1, 2, 3};
    double doubleArr[] = {1.1, 2.2, 3.3};
    std::string stringArr[] = {"username1", "username2", "username3"};

    std::cout << "Integer array:\n";
    print_array("`[$]=%i`", intArr, 3); // Example with indexed format
    print_array("`%i`", intArr, 3);     // Example without indexed format

    std::cout << "\nDouble array:\n";
    print_array("`[$]=%.2f`", doubleArr, 3);
    print_array("`%.2f`", doubleArr, 3);

    std::cout << "\nString array:\n";
    print_array("`[$]=%s`", stringArr, 3);
    print_array("{`[$]=%s`}", stringArr, 3);
    print_array("`%s`", stringArr, 3);

    return 0;
}
*/