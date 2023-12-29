#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include<bits/stdc++.h>
#include <functional>
using namespace std;

int dfs(int n, vector<int>& vec, map<tuple<int,int>, int>& dp ,int level=0, int index=0) {
    if (level == n) return 0;
    tuple<int, int> myTuple = make_tuple(level, index);
    if (dp.find(myTuple) != dp.end())
        return dp[myTuple];

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
        myTuple = make_tuple(level, index);
        dp[myTuple] = result;
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
        std::cout<<"it->first->first = "<<std::get<int>(it->first) \
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


string removeStars(string s) {
    int i=0;
    while (!s.empty() && i< s.length() ) {
        if(s[i] == '*') {
            s.erase(i, 1);
            if (s.empty())
                return s;
            i--;
            s.erase(i, 1);
        } else 
            i++;
    }
    return s;
}   

long long findScore(vector<int>& nums) {

    //min heap
    typedef pair<int, int> pi;
    std::priority_queue<pi, vector<pi>,  greater<pi>> pq;
    for (int i = 0; i < nums.size(); i++)
        pq.push(make_pair(nums[i], i));

    int result = 0;
    while(!pq.empty()) {
        int value = pq.top().first; 
        int index = pq.top().second;
        pq.pop();
       
        if (nums[index] == -1) continue;
        result += value;     
        nums[index] == -1;
        if (index -1 >= 0) nums[index - 1] = -1;
        if (index + 1 < nums.size()) nums[index + 1] = -1;
    };

    return result;
}

long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

    sort(rides.begin(), rides.end(), [](const vector<int> &first, vector<int> &second)
        { return first[0] < second[0]; });

    // for (int i = 0; i<rides.size(); i++) {
    //     for(int j=0; j<rides[i].size(); j++) {
    //         cout << rides[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> dp(rides.size(), 0);
    vector<int> cost(rides.size(), 0);
    //vector<int> maxProfit(rides.size(), 0);

    // int profit = 0;
    // int profitB = 0;
    int maxProfit = 0;
    for (int i = rides.size()-1; i > -1; i--) {
        cost[i] = rides[i][1] - rides[i][0] + rides[i][2];
        for (int j = i + 1; j < rides.size(); j++)
        {
            if (rides[j][0] >= rides[i][1]) {
                cost[i] = cost[i] + cost[j];
            }
            else
                dp[i] = max(dp[i], dp[i + 1]);
        }
        //maxProfit = max(dp[i], maxProfit);
        cout << "maxProfit = " << maxProfit << endl;
        cout << "dp= " << cost[i] << endl;
    }
    return maxProfit;
}

bool equalFrequency(string word) {

    map<char, int> counter{};
    set<int, std::greater<int>> s;
    for(const char& ch: word) {
        if(find(word.begin(), word.end(), ch) == word.end())
            counter[ch] = 1;
        else
            counter[ch] += 1;
    }

    for(const char& ch: word) {
        s.insert(counter[ch]);
    }

    cout << " s = " << s.size() << endl;   
    if (s.size() > 2 || s.size() < 2)
        return false;

    std::sort(s.begin(), s.end(), std::greater<int>());
    for(const int& val: s)
        cout << " val = " << val;
    return false;
}

int main() {

    std::cout << "Hello World" << endl;
    // int result = countNumbersWithUniqueDigits(n);
    // cout << "Result = " << result << endl;
    //tryMakePair();
    //string t = "leet**cod*e";
    // string t = "erase*****";
    // string str = removeStars(t);
    // cout << "Result = " << str << endl;
    // vector<int> nums = {2,1,3,4,5,2};
    // long long val = findScore(nums);
    // cout << "Result = " << val << endl;
    // const int n = 5;
    // vector<vector<int>> rides = {{2, 5, 4 }, {1, 5, 1 }};
    
    
    // const int n = 20;
    // vector<vector<int>> rides = {{1, 6, 1}, {3, 10, 2}, {10, 12, 3}, {11, 12, 2}, {12, 15, 2}, {13, 18, 1}};
    // int result = maxTaxiEarnings(n, rides);
    // std::cout << "Result = " << result << endl;
    const string word = "abcc";
    bool result = equalFrequency(word);
    cout << "Result = " << result << endl;
    return 0;
}