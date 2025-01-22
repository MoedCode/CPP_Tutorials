#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>
#include <vector>

namespace printlib {

template <typename T>
std::string to_string(const T& value) {
    if constexpr (std::is_pointer_v<T>) {
        if (value == nullptr) {
            return "nullptr";
        }
        std::ostringstream oss;
        oss << value;
        return oss.str();
    } else if constexpr (std::is_array_v<T>) {
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < std::extent_v<T>; ++i) {
            if (i > 0) oss << ", ";
            oss << to_string(value[i]);
        }
        oss << "]";
        return oss.str();
    } else if constexpr (std::is_same_v<T, char>) {
        return std::string(1, value);
    } else {
        std::ostringstream oss;
        oss << value;
        return oss.str();
    }
}

inline int print_helper(std::ostream& os, const std::string& format, const std::vector<std::string>& args) {
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
    os << std::endl;
    char_count++; // For the newline character
    return char_count;
}

template <typename... Args>
int print(const char* format, Args... args) {
    std::vector<std::string> arg_strings = {to_string(args)...};

    if (format == nullptr || std::string(format).empty()) {
        // Print all arguments without formatting
        int char_count = 0;
        for (size_t i = 0; i < arg_strings.size(); ++i) {
            if (i > 0) {
                std::cout << ", ";
                char_count += 2;
            }
            std::cout << arg_strings[i];
            char_count += arg_strings[i].size();
        }
        std::cout << std::endl;
        char_count++; // For the newline character
        return char_count;
    } else {
        // Print with format
        return print_helper(std::cout, format, arg_strings);
    }
}

} // namespace lib0
