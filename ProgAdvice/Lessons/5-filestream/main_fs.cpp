#include "header_fs.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


int main(int argc, char **argv) {
    cout << " ______ File Stream _______ \n\n\a";
    string filePath= "test.txt", appName, command ;

    // InterActiveMode(filePath);
    if (argc >= 3 )
    {
        appArgsMode(argv[2], argv[1]);
        // cout << "command:\t" + command + "\n";
        // for(int i = 0; i < argc ; ++i)
        //     cout << i << " - " <<  argv[i] << "\n";

    }

    return 0;

}
