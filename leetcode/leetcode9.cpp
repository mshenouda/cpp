#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    vector<string> words {"hELLO", "World"};
    for(auto& w: words) {
        for(auto& chr: w)
            chr = toupper(chr);
    };
    for(const auto& w: words)
        cout<<w<<" ";
    cout<<endl;
    return 0;
}