#include "header_fs.h"


int main()
{
    cout << " ______ File Stream _______ \n\n\a";
    char file_path[] = "test.txt";
    fstream file0;
    file0.open(file_path, ios::out);
    if (!file0.is_open())
        {
            cerr << "cant open file " << file_path << endl;
            exit(-1);

        }

        file0 << "just a statement  to practice file stream in C++\n";
        file0 << "other statement  to practice file stream in C++\n";
        file0.close();



    return 0;
}