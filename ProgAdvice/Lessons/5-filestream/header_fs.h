#ifndef HEADER_FS_H
#define HEADER_FS_H


#include <iostream>
// #include <cstring>
#include <string>
#include<fstream>
#include <vector>
// #include <vector>
using namespace std;
using namespace std;
typedef int I;
typedef unsigned int UI;
typedef long int LI;
typedef unsigned long int ULI;

typedef long long int LLI;
typedef unsigned long long int ULLI;

typedef double  F;
typedef double  D;
typedef long double  LD;
typedef char C;
typedef const char CC;
typedef char * CP;
typedef const char *  CCP;
typedef const char * strLtr;
// typedef vector<I>::iterator  VII ;
// Function declarations with default arguments

int Fwrite(string file_path, string mode,  string data);
string Fread(string file_path);
int FileInVector(string filePath, vector<string>& fileContent);
int VectorToFile( vector<string>& fileContent, string filePath = "vOut.txt", string mode = "a");
int editInterActive(string filePath);
int appArgsMode(string filePath ,string command);


#endif