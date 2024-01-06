#include <iostream>
#include <string>
using namespace std;


vector<string> dfs(string s, vector<string> results, int index = 0, string tmp = "", int counter = 0) {
    if (index == s.size()) return true;

    for(int i=index; i<s.size(); i++) {
        for(int j=1; j<=3; j++) {
            tmp = s.substr(i, j);
            if (tmp.size() > 1 && tmp[0] == '0' && tmp[1] == '0')
                break;
            if (stoi(tmp) > 255)
                break;            
            counter += 1;    
            result.push_back(tmp);
            if (counter < 4)
                result.push_back('.');
            if (dfs(s, results, index + 1, tmp)) {

            }

        }
    }
}

vector<string> restoreIpAddresses(string s) {
    if (s.size() < 4)  return "";

    vector<string> results = {};
    int index = 0;
    return dfs(s, results);
}

int main() {

    string s = "25525511135";
    vector<string> results = restoreIpAddresses(s);
    for(const auto& result: results) {
        cout<<" result = "<<result<<" ";
    }
    cout<<endl;
    return 0;
} 


