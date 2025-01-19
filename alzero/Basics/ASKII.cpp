#include <cstdlib>
#include <iostream>
using namespace std;

int print_ascii(int start = 0, int end = 127, int indent = 0) {
    const char* non_printable[] = {
        "NUL || \\0", "SOH || ^A", "STX || ^B", "ETX || ^C", "EOT || ^D", "ENQ || ^E", "ACK || ^F", "BEL || \\a",
        "BS || \\b", "TAB || \\t", "LF || \\n", "VT || \\v", "FF || \\f", "CR || \\r", "SO || ^N", "SI || ^O",
        "DLE || ^P", "DC1 || ^Q", "DC2 || ^R", "DC3 || ^S", "DC4 || ^T", "NAK || ^U", "SYN || ^V", "ETB || ^W",
        "CAN || ^X", "EM || ^Y", "SUB || ^Z", "ESC || ^[", "FS || ^\\", "GS || ^]", "RS || ^^", "US || ^_"
    };

    int i = 0;
    cout << "ASCII From " << start << " to " << end << ":\n{\n";

    for (int code = start; code <= end; ++code) {
        if (i == indent && indent > 0) {
            cout << endl;
            i = 0;
        }

        if (code < 32) {
            cout << "[" << code << "]= " << non_printable[code] << ", ";
        } else if (code == 127) {
            cout << "[" << code << "]= DEL || ^?, ";
        } else {
            printf("[%d]= %c, ", code, code);
        }
        i++;
    }

    if (indent > 0)
        cout << endl;

    cout << "}\n";
    return 0;
}

int main(int argc, char **argv) {
    int start = 0, end = 127, indent = 0;

    if (argc > 1)
        start = atoi(argv[1]);
    if (argc > 2)
        end = atoi(argv[2]);
    if (argc > 3)
        indent = atoi(argv[3]);

    cout << "Start: " << start << ", End: " << end << ", Indent: " << indent << endl;
    print_ascii(start, end, indent);

    return 0;
}
