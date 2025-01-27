#include  "header_comp.h"
#include "get_data.h"
#include <list>
#include <string>

int main(void)
{
	// printMatrixTestCases();
	// vectores();
    list<string> questions = {"Enter your name", "Enter your age", "Enter your height (in meters)"};

    // Get answers as strings
    vector<string> string_answers = getdata::get_user_data<list<string>, string>(questions);

    // Display the answers
    cout << "\nYour answers:\n";
    size_t i = 0;
    for (const auto& answer : string_answers) {
        cout << "Q" << ++i << ": " << answer << endl;
    }

	 return 0;

}