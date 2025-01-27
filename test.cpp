#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
vector<T> get_user_data(const vector<string>& questions) {
    vector<T> answers;

    for (const string& question : questions) {
        T temp;
        cout << question << ": ";
        cin >> temp;
        answers.push_back(temp);
    }

    return answers;
}

int main() {
    vector<string> questions = {"Enter your name", "Enter your age", "Enter your height (in meters)"};

    // For strings
    vector<string> string_answers = get_user_data<string>(questions);

    // Display string answers
    cout << "\nYour answers:\n";
    for (size_t i = 0; i < string_answers.size(); ++i) {
        cout << questions[i] << ": " << string_answers[i] << endl;
    }

    return 0;
}
