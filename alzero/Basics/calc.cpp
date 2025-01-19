#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath> // For std::sin, std::cos, std::log, std::pow

using namespace std;

// Typedefs for function pointers
typedef long long int (*BinaryFun)(int, int);
typedef double (*UnaryFun)(double);

// Binary function for power
long long int power(int base, int exp) {
    long long int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Unary functions for sine, cosine, and logarithm
double sine(double value) {
    return std::sin(value);
}

double cosine(double value) {
    return std::cos(value);
}

double logarithm(double value) {
    if (value <= 0) {
        cerr << "Logarithm domain error (value must be > 0)!\n";
        return NAN;
    }
    return std::log(value);
}

// Structs to map operators to functions
struct BinarySignsFunctions {
    const char* sign;
    BinaryFun function;
};

struct UnarySignsFunctions {
    const char* sign;
    UnaryFun function;
};

// Array of supported binary operations
BinarySignsFunctions binary_sign_fun[] = {
    {"pow", power}
};

// Array of supported unary operations
UnarySignsFunctions unary_sign_fun[] = {
    {"sin", sine},
    {"cos", cosine},
    {"log", logarithm}
};

// Function to find and execute a binary function
long long int execute_binary_function(const char* sign, int num1, int num2) {
    for (const auto& sf : binary_sign_fun) {
        if (string(sf.sign) == sign) {
            return sf.function(num1, num2);
        }
    }
    return LLONG_MIN; // Return an invalid result if not found
}

// Function to find and execute a unary function
double execute_unary_function(const char* sign, double num) {
    for (const auto& sf : unary_sign_fun) {
        if (string(sf.sign) == sign) {
            return sf.function(num);
        }
    }
    return NAN; // Return an invalid result if not found
}

int main(int argc, char** argv) {
    if (argc < 3 || argc > 4) {
        cerr << "Usage: ./program num1 [operator num2]\n";
        return -1;
    }

    string op = argv[2];

    // Handle unary operators (e.g., sin, cos, log)
    if (argc == 3) {
        double num = atof(argv[1]);
        double result = execute_unary_function(op.c_str(), num);
        if (isnan(result)) {
            cerr << "Invalid unary operator: " << op << "\n";
            return -5;
        }
        cout << "Result: " << result << endl;
        return 0;
    }

    // Handle binary operators (e.g., +, -, *, pow)
    if (argc == 4) {
        int num1 = atoi(argv[1]);
        int num2 = atoi(argv[3]);

        // Check for binary operators
        if (op == "+") {
            cout << "Result: " << (num1 + num2) << endl;
        } else if (op == "-") {
            cout << "Result: " << (num1 - num2) << endl;
        } else if (op == "*") {
            cout << "Result: " << (num1 * num2) << endl;
        } else if (op == "/") {
            if (num2 == 0) {
                cerr << "Division by zero error!\n";
                return -3;
            }
            cout << "Result: " << (num1 / num2) << endl;
        } else if (op == "%") {
            if (num2 == 0) {
                cerr << "Modulo by zero error!\n";
                return -4;
            }
            cout << "Result: " << (num1 % num2) << endl;
        } else {
            // Check for custom binary operators (e.g., pow)
            long long int result = execute_binary_function(op.c_str(), num1, num2);
            if (result == LLONG_MIN) {
                cerr << "Invalid binary operator: " << op << "\n";
                return -5;
            }
            cout << "Result: " << result << endl;
        }
    }

    return 0;
}
