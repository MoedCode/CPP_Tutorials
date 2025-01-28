#include  "header_comp.h"
#include "get_data.h"
#include <cstddef>
#include <cstdio>
#include <list>
#include <string>

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
	string res = getUserAnswer(questions, 10);

	FILE *f = fopen("out", "a");
	fprintf(f, "%s \n\n", res.data());
	fclose(f);
	cout << res << endl;
	 return 0;

}