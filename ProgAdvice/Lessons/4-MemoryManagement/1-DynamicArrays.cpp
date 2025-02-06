#include "header_MM.h"
#include <cstddef>
#include <cstdlib>

int get_students_grades()
{
	size_t length = 0, i = 0;
	float *Fptr ;

	cout << "students number: ";
	cin >> length;

	Fptr =new float[length];
	//Fptr = (float *)malloc(length * sizeof(float));// it also can work
	CCP names[length] ;
	for (; i < length; ++i)
	{

		cout << "Enter student grade number" << (i +1) <<": ";
		cin >> *(Fptr + i);

	}
	for (i = 0; i < length; ++i)
	{
		cout << "students grades";
		printf("student %zu gread %f \n", (i + 1), *(Fptr + i));
	}
	delete []Fptr;
	// free(Fptr);
	return 0;
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

	cout << "\n---iterate using pointers---\n";
	vector <string > :: iterator VSptr;
	for (VSptr = names.begin();  VSptr != names.end(); ++VSptr)
		cout << *VSptr << endl;

}