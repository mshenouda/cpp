#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    int num1 = 10;
    int num2 = 5 ;
    int sum = num1 + num2;
    cout << sum<< endl;
}
