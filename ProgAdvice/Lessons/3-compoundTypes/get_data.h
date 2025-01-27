#include <iostream>
#include <vector>
using namespace std;
namespace getdata
{

template <typename Container, typename T>
vector<T> get_user_data(const Container& questions)
{
    vector<T> answers;

    for (const auto& question : questions) {
        T temp;
        cout << question << ": ";
        cin >> temp;
        answers.push_back(temp);
    }

    return answers;
}

}