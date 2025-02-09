#include "header_fs.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
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
int addToFile(string filePath)
{

    string result =  Fread(filePath);
    if (!result.empty()) cout << result;
    else cout << "nullptr\n";
    vector<string> filecontent;
    FileInVector(filePath, filecontent);
    filecontent.push_back("ohohoho");
    VectorToFile(filecontent, filePath, "w");
    return 0;
}
bool startsWith(const string& str, const string& prefix) {
    return str.rfind(prefix, 0) == 0;  // Check if prefix is found at position 0
}
void delW(string& str, const string& sentence) {
    size_t pos;
    while ((pos = str.find(sentence)) != string::npos) {
        str.erase(pos, sentence.length());  // Remove sentence in place
    }
}
int stringTofile(string filePath, string content, string mode="a")
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


    file << content;
    file.close();
    return 0;
}
                                // tokenizeCommand
/**
 * @brief Tokenizes a given command string into a vector of arguments.
 *
 * This function handles:
 * - Space-separated tokens
 * - Quoted strings as single tokens (e.g., `"Hello World"` remains `"Hello World"`)
 *
 * @param command The input string to tokenize
 * @return vector<string> A vector containing the tokens
 */
vector<string> tokenizeCommand(const string &command)
{
    vector<string> tokens;
    string token;
    bool inQuotes = false;
    stringstream ss;

    for (char ch : command)
    {
        if (ch == '"')
        {
            inQuotes = !inQuotes;
            if (!inQuotes && !token.empty()) // Closing quote, push token
            {
                tokens.push_back(token);
                token.clear();
            }
            continue;
        }

        if (ch == ' ' && !inQuotes)
        {
            if (!token.empty()) // Push completed token
            {
                tokens.push_back(token);
                token.clear();
            }
            continue;
        }

        token += ch;
    }

    if (!token.empty()) // Push the last token if exists
        tokens.push_back(token);

    return tokens;
}
                                    //sed_exe
/**
 * @brief
 *
 * @param filePath
 * @param command
 * @return int
 */
int sed_exe(string filePath, string command)
{
    string action, statement ;
    int line_num = 0;
    vector<string> fileContent, TCV;
    FileInVector(filePath, fileContent);
    string help = "\
    -i insert in file optional. for inserting into file otherwise print to terminal\n\
    i<line number> for insert before specific line \n\
    a<line number> for append before specific line \n\
    \n ";
    TCV = tokenizeCommand(command);
    for (string  &s  : TCV)
        cout << ": "  + s + '\t';
    if (TCV.at(1) == "-h" || TCV.at(1) == "help" || TCV.at(1) == "--help")
        {
            cout << help + "\n \a";
            return 0;
        }
    if (TCV.size() <= 2)
    {
        cerr << "to few argument \n ";
        cout << help;
        return 1;

    }
        if (TCV.size() >= 3 )
    {
        if(TCV.size() == 3)
        {
            line_num = atoi(TCV.at(1).substr(1).data());
            action ="cout";
            statement = TCV.at(2);

        }
        if(TCV.size() > 3)
        {
            line_num = atoi(TCV.at(2).substr(1).data());
            action = "ios";
            statement = TCV.at(3);

        }
        // cout << "line: " << line_num <<  "substr(0).data():" << TCV.at(1).substr(1)<< endl;
        if (!line_num || line_num > fileContent.size())
            {
               (!line_num )?  cerr << "invalid line number " + TCV.at(1) + "\n":
                cerr << "line number out of pounders\n";
                return 2;
            }

        // cout << "statement : " + statement + "\n";
        fileContent.insert(fileContent.begin() + line_num ,1,statement);
        cout << endl;
        if (action == "cout")
            for (string &line : fileContent )
                    cout << line + "\n";
        if(action == "ios")
            VectorToFile(fileContent, filePath,"w");

        return 0;
    }
    // cout << TCV.size() << endl;
    // for (string &tok : TCV)
    //     cout << "\n\n\n=>" + tok + "\t";

    return 0;
}

                            // Search
/**
 * @brief
 *
 * @param filePath
 * @param line
 * @return int
 */
int search(string filePath, string line)
{
    string sentence = line.substr(2);
    // string result =  Fread(filePath);
    vector<string>fileContent;
    FileInVector(filePath, fileContent);
    int i = 0, pos,res=0;
    for(string &vline : fileContent)
        {
            ++i;
            int LineRes = vline.find(sentence);
            if(LineRes != vline.npos)
            {
                res = 1;
                pos = LineRes;
                break;
            }
        }
    if(res)
    {
        printf("Line: %i, col: %i",i , pos + 1);
        return 0;;
    }

    cout << "no matching for " + sentence + "\n";
    return 2;
}
int del(string filePath, string line)
{
    string sentence = line.substr(4);
    // cout << sentence + '\n';
    string result =  Fread(filePath);
    if(result.empty())
    {
        cout << "cant find \"" + sentence + "\"\n";
        return 2;
    }
    delW(result, sentence);
    stringTofile(filePath, result, "w");
    return 0;
}

int updateInFile(string filePath, string command)
{
    if (command.substr(0, 4) != "rep:") return 1; // Invalid command format

    size_t firstQuote = command.find('"');
    if (firstQuote == string::npos) return 2;
    size_t secondQuote = command.find('"', firstQuote + 1);
    if (secondQuote == string::npos) return 3;
    size_t thirdQuote = command.find('"', secondQuote + 1);
    if (thirdQuote == string::npos) return 4;
    size_t fourthQuote = command.find('"', thirdQuote + 1);
    if (fourthQuote == string::npos) return 5;

    string target = command.substr(firstQuote + 1, secondQuote - firstQuote - 1);
    string replacement = command.substr(thirdQuote + 1, fourthQuote - thirdQuote - 1);

    vector<string> fileContent;
    FileInVector(filePath, fileContent);

    bool replaced = false;
    for (auto& line : fileContent)
    {
        size_t pos = line.find(target);
        if (pos != string::npos)
        {
            line.replace(pos, target.length(), replacement);
            replaced = true;
            break; // Replace only the first occurrence in the file
        }
    }

    if (!replaced) return 6; // Target word not found

    VectorToFile( fileContent, filePath, "w");
    return 0; // Success
}
                         // appArgsMode
/**
 * @brief
 *
 * @param filePath
 * @param command
 * @return int
 */
int appArgsMode(string filePath ,string command)
{
    if (command == "exit")
        return  0;
if (command == "cat")
    {
        string result =  Fread(filePath);
        if (!result.empty()) cout << result;
        else
            {
                cerr << "error: reading file \"" + filePath + "\" \n";
                return 3;
            }
        return  0;
    }
    if (startsWith(command, "del:"))
    del(filePath, command);

if (startsWith(command, "/:"))
    {
        search(filePath, command);
    }
if (startsWith(command, "sed"))
{
    sed_exe(filePath, command);
}
if(startsWith(command, "rep:"))
{
    updateInFile(filePath, command);
}

    return 0;
}
                            //InterActiveMode
/**
 * @brief
 *
 * @param filePath
 * @return int
 */
int InterActiveMode(string filePath)
{
    string line;

    cout << "☺%";

    while(getline(cin, line))
    {       cout << "☺%";
        if (line == "exit")
            break;
        if (line == "cat")
            {
                string result =  Fread(filePath);
                if (!result.empty()) cout << result;
                continue;
            }
        if (startsWith(line, "del:"))
        {
            del(filePath, line);
            continue;
        }
        if (startsWith(line, "/:"))
            {
                search(filePath, line);
                continue;
            }
        if (startsWith(line, "sed"))
        {
            sed_exe(filePath, line);
            continue;
        }
        if(startsWith(line, "rep:"))
        {
            updateInFile(filePath, line);
        }
    }


    return 0;
}
