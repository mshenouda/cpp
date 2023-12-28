#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;


int dfs(int n, vector<int>& vec, map<tuple<int,int>, int>& dp ,int level=0) {
    if (level == n) return 0;
    // int index;
    // int myLevel;
    // std::tie(myLevel, index) = dp->;

    // //if ()
    //if (std::get<0>(dp) && std::get<1>(dp))
    //    return dp[()]
    int result = 0;  
    for (int i = 0; i < 10; i++) {
        if (i == 0 && level == 0) {
            result = 1;
            continue;
        }
        if (std::find(vec.begin(), vec.end(), i) == vec.end()) {
            vec.push_back(i);
            result += 1;
        } 
        else
            continue;

        result += dfs(n, vec, dp, level + 1);
        vec.pop_back();
    }
    return result;
}

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 0;
    if (n == 1) return 10;
    vector<int> v={}; 
    map<tuple<int, int>, int> dp = {};
    return dfs(n, v, dp);
}

void tryMakePair() {
    //map<<tuple<int, string>, std::string>> MyMap = {};
    map<tuple<int, string>, string> MyMap = {};
    tuple<int, string> tmp = make_tuple(0, "Name");
    MyMap[tmp] = "Mina";
    tmp = make_tuple(0, "Job");
    MyMap[tmp] = "Engineer";
    for(auto it = MyMap.begin(); it != MyMap.end(); it++)
    {
        cout<<"it->first->first = "<<std::get<int>(it->first) \
        <<" it->first->second = "<<std::get<string>(it->first) \
        <<" it-second = "<<it->second<<endl;
    }


    // MyMap[1] = "Shenouda";
    // MyMap[2] = "July";
    // map<int, string>::iterator it;
    // for (it = MyMap.begin(); it != MyMap.end(); it++) {
    //     cout << "first " << it->first << " second = " << it->second << endl;
    // }
}


int main() {

    cout << "Hello World" << endl;
    int n = 5;
    //int result = countNumbersWithUniqueDigits(n);
    tryMakePair();
    //cout << "Result = " << result << endl;
    return 0;
}