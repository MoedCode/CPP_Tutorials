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
/**
 * @brief
 *
 * @param os
 * @param format
 * @param args
 * @return int
 */
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


template<typename PAT>
int printArray(PAT arr, int length, const char* F = nullptr, const char* idx = nullptr)

{
    int i = 0;
    if (!arr)
        return -1;

    // Print opening delimiter
    int c = 0;
    for(; F && F[c] && F[c] != '%'; c++)
        cout << F[c];

    // Iterate through the array
    for (i = 0; i < length; i++) {
        // Print index and value if idx is provided
        if (idx) {
            for (int j = 0; idx[j]; j++) {
                if (idx[j] == '%' && idx[j + 1] == 'i') {
                    cout << i;
                    j++; // Skip the next character ('i')
                } else if (idx[j] == '%' && idx[j + 1] == 'v') {
                    cout << arr[i];
                    j++; // Skip the next character ('v')
                } else {
                    cout << idx[j];
                }
            }
        } else {
            // Print the element directly
            cout << arr[i];
        }

        // Print separator if there is a next element
        if (i < length - 1)
            cout << " ";
    }

    // Print closing delimiter
    if (F) {
        c++;
        for(; F[c]; c++)
            cout << F[c];
    }

    return 0;
}

template<typename PMT>
int printMatrix(PMT arr, int rownum, int colnum, const char* F = nullptr, const char* idx = nullptr, char end = '\n')
{
    int c = 0;
    for(; F && F[c] && F[c] != '%'; c++)
        cout << F[c];
    cout << endl;
    for(int i = 0; i < rownum; i++) {
        printArray(arr[i], colnum, F, idx);
        if (i < rownum )
            cout << end;
    }

    if (F) {
        c++;
        for(; F[c]; c++)
            cout << F[c];
    }
    cout << endl;

    return 0;
}
/**
 * @brief : printf_array - iterate over array print its indexes using printf
 *
 * @tparam PAFT : array type,
 * @param array : array to be print
 * @param size : array size
 * @param idxF : array index format will to be passed to printf
 * @param arrF : array format
 * @Return size_t : (-1) on error , else number of character printed
 */
template<typename PAFT>
size_t printf_array(PAFT array, size_t size, const char *idxF, const char* arrF = "%ar")
{
    size_t i, x = 0;

    if (!array || !idxF)
    {
        (!idxF) ? cerr <<  "NULL format\n" : cerr << "NULL array\n";
        return -1;
    }

    for(i = 0; arrF[i] ; ++i)
    {
        if(arrF[i] == '%' && arrF[i + 1] =='a' && arrF[i + 2] =='r' )
        {
            i +=3;
            for(size_t j = 0; j < size; j++)
                x += printf(idxF, array[j]);

        }

        cout << arrF[i] ;
    }
    return (x + i);
}

template <typename PMFT>
/**
 * @brief printf_matrix - print matrix iterate over row print it using printf_array
 *
 * @param matrix : matrix to be print
 * @param rows : number of row
 * @param cols : number of columns
 * @param idxF : array index format will to be passed to printf to be passed to printf_array
 * @param matF :matrix format
 * @param rowF : to be passed to printf_array as array format
 * @return size_t : number of character printed
 */
size_t printf_matrix(PMFT matrix, size_t rows, size_t cols, const char *idxF, const char *matF = "%Mx", const char *rowF = "%ar")
{

    size_t i, x = 0;

    if (!matrix || !idxF )
    {
        cerr << "NULL argument passed to printf_matrix\n";
        return -1;
    }

    for (i = 0; matF[i]; ++i)
    {
        if (matF[i] == '%' && matF[i + 1] == 'M' && matF[i + 2] == 'x')
        {
            i += 2; // Skip "%Mx"
            for (size_t r = 0; r < rows; r++)
            {
                x += printf_array(matrix[r], cols, idxF, rowF);

            }
        }
        else
        {
            cout << matF[i];
        }
    }
    return (x + i);
}

} // namespace lib0
