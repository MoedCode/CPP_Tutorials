#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    int height = 0, width = 0;
    string watermark;

    // Limit argc to a maximum of 4
    int argC = (argc > 4) ? 4 : argc;

    switch (argC) {
        case 1:
            // No arguments provided
            cerr << "Usage: ./ternary <height> [width] [watermark]\n";
            return -1;

        case 2:
            // One argument: height and width are the same, default watermark
            height = width = atoi(argv[1]);
            watermark = argv[0];
            break;

        case 3:
            // Two arguments: height and width specified, default watermark
            height = atoi(argv[1]);
            width = atoi(argv[2]);
            watermark = argv[0];
            break;

        case 4:
            // Three arguments: height, width, and watermark specified
            height = atoi(argv[1]);
            width = atoi(argv[2]);
            watermark = argv[3];
            break;

        default:
            cerr << "Invalid number of arguments.\n";
            return -1;
    }

    // Remove leading "./" from the program name if present
    size_t pos = watermark.find("./");
    if (pos != string::npos) {
        watermark = watermark.substr(pos + 2);
    }

    // Print the matrix
    for (int vh = 0; vh < height; vh++) {
        for (int vw = 0; vw < width; vw++) {
            cout << watermark;
            if (vw < width - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
