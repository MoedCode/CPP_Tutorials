#include  "header_comp.h"



#include "../1-Library/printlib.h"
#include <string>
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



 void vectorMethods(void)
{
	vector <const char *> user = {
		"\"username\":\"mohamed\"",
		"\"email\":\"mohamed_h.gmail.com\"",
	};
	for (const char * &entry : user)cout << entry << endl;

	user.insert(user.begin(),"{");
	cout << "\n---after modifying---\n";
	user.push_back("}");
	for (const char * &entry : user)cout << entry << endl;

	cout << "\n-- more methods ---\n";
	cout << " user.front() " << user.front() << endl;
	cout << " user.back() " << user.back() << endl;
	user.clear() ;
	cout << "\n---after clear---\n";
	for (const char * &entry : user)cout << entry << endl;


}
void  vector_iterate()
{
	// use constant if you just read from vector elements
	// use & to read value from victor directly without coping it first
	vector <string> names {"name1", "name2", "name3"};
	for(const string &name : names)
		cout << name << endl;
	// for(string &name : names)
	// {
	// 	name += "ss";
	// 	cout << name << endl;
	// }
	cout << "names[0]: " << names[0]<<endl;
	cout << "names.at(0): " << names.at(0)<<endl;
	// cout << __FILE__ << " line: "<<__LINE__ << endl;

	// cout << "names[3]: " << names[3]<<endl;
	// cout << __FILE__ << " line: "<<__LINE__ << endl;
	// cout << "names.at(3): " << names.at(3)<<endl;


}