#include  "header_comp.h"


#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string_view>
#include <vector>
#include <string>

// #include "../1-Library/printlib.h"
// using namespace printlib;


using namespace std;

void Trash_useless(char *buff, size_t r=10, size_t c = 10, const char *F = "%02d ")
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout <<  (i + 1) * (j + 1);

			char temp[15];    // Temporary buffer to hold each formatted string
			sprintf(temp, "%08i ", (i + 1) * (j + 1)); // Format the number
			strcat(buff, temp); // Append the formatted string to the main buffer
		}
		strcat(buff, "\n"); // Append a newline after each row
	}
}

int testVectores(void)
{
	vector< int>vnum;

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			vnum.push_back(((i + 1) *( j +1)));
	for (int &n : vnum )
		 printf(" %i", n);
	cout << endl;
	cout << vnum.size() << endl;
	return 0;
}

#include "get_data.h"
#include <list>
#include <string>
 void TestGetData(void)
{
	list<string> questions = {"Enter your name", "Enter your age", "Enter your height (in meters)"};

	// Get answers as strings
	vector<string> string_answers = getdata::get_user_data<list<string>, string>(questions);

	// Display the answers
	cout << "\nYour answers:\n";
	size_t i = 0;
	for (const auto& answer : string_answers) {
		cout << "Q" << ++i << ": " << answer << endl;
	}
}
/**
 * @brief  - getUserAnswer: get user answer on given questions
 *
 * @param questionArr : (const char **) The array of questions.
 * @param size : (size_t) The size of the array, excluding the closing message.
 * @param action: (char) Determines the output behavior:
 *               'r' - Return the conversation buffer.
 *               'p' - Print the results.
 *               'B' - Both print and return the buffer.
 * @Return: (char*) The conversation buffer.
 */

string getUserAnswer(const char **questionArr, size_t size, char action)
{
    if (!questionArr || !size)
    {
        (!questionArr) ? cerr << "Array nullpointer "
                        : cerr << "Invalid size value";
        return nullptr;
    }

    // Exclude the last index (closing message) from questions
    size_t numQuestions = size - 1;

    vector<string> answerVec; // Store user answers
    string temp;

    // Ask questions and store answers
    for (size_t i = 0; i < numQuestions; ++i)
    {
        cout << questionArr[i];
        if (questionArr[i][strlen(questionArr[i]) - 1] != '?')
            cout << "?";
        cout << endl;

        bool confirmedEmpty = false;
        while (true)
        {
            getline(cin, temp);
            if (temp.empty())
            {
                if (confirmedEmpty)
                {
                    temp = "Not answered";
                    break;
                }
                else
                {
                    cout << "You left this field blank. Press Enter again to confirm, or type your answer: ";
                    confirmedEmpty = true;
                }
            }
            else
            {
                break;
            }
        }

        if (temp == "quit" || temp == "no" || temp == "N")
            return nullptr;

        answerVec.push_back(temp); // Save user answer
    }

    // Print the closing message
    cout << questionArr[numQuestions] << endl;

    // Prepare the result in the requested format
    static string answerBuff = "{";
    for (size_t i = 0; i < answerVec.size(); ++i)
    {
        if (action == 'p' || action == 'B')
            printf("{question: %s,\nAnswer: %s}\n", questionArr[i], answerVec[i].c_str());

        if (action == 'r' || action == 'B')
        {
            answerBuff.append("\"");
            answerBuff.append(questionArr[i]);
            answerBuff.append("\":\"");
            answerBuff.append(answerVec[i]);
            answerBuff.append("\"");
            if (i < (answerVec.size() - 1))
                answerBuff.push_back(',');
        }
    }
    answerBuff.push_back('}');

    return (action == 'r') ? answerBuff : nullptr;
}