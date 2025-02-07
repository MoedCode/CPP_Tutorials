#include "header_fs.h"
#include <iostream>

int main() {
    cout << " ______ File Stream _______ \n\n\a";
    char filePath[] = "test.txt";
    // string result =  Fread(filePath);
    // if (!result.empty()) cout << result;
    // else cout << "nullptr\n";
    vector<string> filecontent;
    FileInVector(filePath, filecontent);
    filecontent.push_back("ohohoho");
    VectorToFile(filecontent, filePath, "w");
    return 0;

}
