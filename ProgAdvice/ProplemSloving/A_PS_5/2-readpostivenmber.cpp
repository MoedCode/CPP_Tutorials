#include "header.h"

    /**
     * @brief
     *
     * @param msg
     * @return long double
     */

      LD getPosDouble(CCP msg )
     {
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


    ULI getUInt(CCP msg)
     {
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
// int main()
// {
//     getPosDouble();
//     getUInt();
//     return 0;
// }