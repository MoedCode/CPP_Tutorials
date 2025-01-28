#include <cstring>
#include <iostream>
#include <vector>


using namespace std;

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

int main(void)
{
	// printMatrixTestCases();
	// testVectores();
 	//  TestGetData();


	const char *questions[] ={
		"Are you interested in our program",
		"your name ","your age ", "Education ","Major",
		"Your LinkedIn Account Link",
		"What is your email address?",
		"What town/city do you live in?",
		"What is your job title",
		"Thanks, you're all set. We will contact you!"

		};
	// getUserAnswer(questions,(size_t) 10);
	string res = getUserAnswer(questions, 10, 'r');

	FILE *f = fopen("out", "a");
	fprintf(f, "%s \n\n", res.data());
	fclose(f);
	cout << res << endl;
	 return 0;

}