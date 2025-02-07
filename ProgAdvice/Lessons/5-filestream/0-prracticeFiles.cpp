#include "header_fs.h"

int Fwrite(string filePath="out.txt", string mode="a" ,  string data="")
{
    fstream file;
    if (mode == "a")
        file.open(filePath,  ios::app);
    if (mode == "w")
        file.open(filePath,  ios::out);
    if (!file.is_open()) {
        cerr << "Cannot open file " << filePath << endl;
        return(-1);
    }
    file << data;

    file.close();
    return 0;
}
string Fread(string filePath)
{
    fstream file;
    file.open(filePath, ios::in);
    if (!file.is_open()) {
        cerr << "Error opening file " << filePath + "!\n";
        return string("");
    }
    string buffer, line;
    while (getline(file, line))
        buffer.append(line + "\n");
    file.close();
    return buffer;

}
int  FileInVector(string filePath, vector<string>& fileContent)
{
    fstream file;
    file.open(filePath, ios::in);
    if (!file.is_open()) {
        cerr << "Error opening file " << filePath + "!\n";
        return -1;
    }
    string line;
    while(getline(file, line))
        fileContent.push_back(line );
    file.close();
    return 0;
}
int VectorToFile( vector<string>& fileContent, string filePath,  string mode)
{
    fstream file;
    if (mode == "a")
        file.open(filePath,  ios::app);
    if (mode == "w")
        file.open(filePath,  ios::out);
    if (!file.is_open()) {
        cerr << "Error opening file " << filePath + "!\n";
        return -1;
    }
    for (string &idx : fileContent)
        file << idx + "\n";
    return 0;
}