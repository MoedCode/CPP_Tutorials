#include <iostream>
#include <string>
typedef const char *  CCP;
typedef long long int LLI;
typedef unsigned long int ULI;

typedef long double  LD;

using namespace std;

namespace promptlib {
    /**
     * @brief
     *
     * @param msg
     * @return long double
     */

     inline LD getPosDouble(const char msg[] = "Type Amount: ") {
        LD Amount;

        while (true) {
            cout << msg;
            cin >> Amount;

            if (cin.fail()) {
                cin.clear();  // Clear error state
                cin.ignore(10000, '\n');  // Ignore invalid input
                cout << "Invalid input! Please enter a positive number.\n";
                continue;
            }

            if (Amount <= 0) {
                cout << "Amount must be a positive number.\n";
            } else {
                return Amount;
            }
        }
    }
    /**
     * @brief
     *
     * @param msg
     * @return long double
     */

     inline ULI getUInt(const char msg[] = "Type Amount: ") {
        ULI Amount;

        while (true) {
            cout << msg;
            cin >> Amount;

            if (cin.fail()) {
                cin.clear();  // Clear error state
                cin.ignore(10000, '\n');  // Ignore invalid input
                cout << "Invalid input! Please enter a positive number.\n";
                continue;
            }

            if (Amount <= 0) {
                cout << "Amount must be a positive number.\n";
            } else {
                return Amount;
            }
        }
    }

}