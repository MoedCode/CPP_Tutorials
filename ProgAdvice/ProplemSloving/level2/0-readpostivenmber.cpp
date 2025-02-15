#include "headerLev2.h"

    /**
     * @brief
     *
     * @param msg
     * @return long double
     */

      ld getPosDouble(ccp msg )
     {
        ld Amount;

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


    llu getUInt(ccp msg)
     {
        llu Amount;

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
// int main()
// {
//     getPosDouble();
//     getUInt();
//     return 0;
// }