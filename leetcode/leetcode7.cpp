#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <utility>
#include <map>
#include <limits.h>
using namespace std;

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    
    unordered_map<int, int> map;
    for(const auto& barcode : barcodes)
        ++map[barcode];

    set<pair<int, int>> s;  
    for(const auto& row : map)
        s.insert({row.second, row.first});
    
    int pos = 0;
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        for (int cnt = it->first; cnt > -1; --cnt, pos+=2) {
            if (pos >= barcodes.size()) pos = 1;
           barcodes[pos] = it->second; 
        }
    }

    return barcodes;
}

int countCompleteSubarrays(vector<int>& nums) {
    set<int> s;
    for(const auto& num: nums)
        s.insert(num);

    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        set<int> n;
        for (int j = i; j < nums.size(); j++) {
            n.insert(nums[j]);
            if (s.size() == n.size()) {
                result += (nums.size()- j);
                break;
            }
        }
    };
    return result;
}

int totalFruit(vector<int>& fruits) {
    
    int maxResult = 0;
    set<int> n;
    int start = 0;
    for (int i = 0; i < fruits.size(); ++i)
    {
        n.insert(fruits[i]);
        if (n.size() > 2) {
            n.erase(fruits[start]);
            start = i - 1;
        }
        maxResult = max(maxResult, i-start+1);
    }
    return maxResult;
}



// int dfs(vector<vector<int>>& grid, const int m, const int n, int row, int column, vector<vector<int>> dp)
// {
//     if (dp[row][column] != -1) return dp[row][column];

//     int result = 0;
//     if ((row-1 >= 0 && column+1 < n) && grid[row-1][column+1] > grid[row][column]) {
//         dp[row][column] = result = max(result, 1 + dfs(grid, m, n, row - 1, column + 1, dp));
//     }
//     if ((column+1 < n) && grid[row][column+1] > grid[row][column]) {
//         dp[row][column]  = result = max(result, 1 + dfs(grid, m, n, row, column + 1, dp));
//     }
//     if ((row+1 < m && column+1 < n) && grid[row+1][column+1] > grid[row][column]) {
//         dp[row][column]  = result = max(result, 1 + dfs(grid, m, n, row + 1, column + 1, dp));
//     }
//     return result;
// };

int maxMoves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int result = 0;

    vector<vector<int>> dp(m, vector<int>(n, -1));
    // for (int j = 0; j < m; j++) {
    //     int val = dfs(grid, m, n, j, 0, dp);
    //     result = max(result, val);  
    // }
    return result;
}

int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    map<char, int> Map;
    for (char i = 'a'; i <= 'z'; ++i)
        Map[i] = (i-'a')+1;

    for (int i = 0; i < chars.length(); i++)
        Map[chars[i]] = vals[i];
    
    for (char i = 'a'; i <= 'z'; ++i)
        cout << Map[i] << endl;

    vector<int> dp(s.size(), 0);
    dp[0] = (dp[0] >= Map[s[0]]) ? dp[0] : Map[s[0]];
    cout << "dp" << dp[0] << endl;
    for (int i = 1; i < s.size(); i++)
    {
        dp[i] = dp[i] >= Map[s[i]] ? dp[i] : Map[s[i]];
        if (dp[i] >=0 && dp[i-1] > 0)
            dp[i] += dp[i - 1];
    }

    for (int i = 0; i < s.size(); i++)
        cout << dp[i] << " ";
    cout << endl;
    return dp[s.size() - 1];
}

bool dfs(vector<int>& piles, vector<vector<int>>& dp, int i, bool alice=true, int aliceCount=0, int bobCount=0) {
   
    if (i == piles.size()) return (aliceCount > bobCount);
    int val = alice ? 1 : 0;
    if (dp[i][val] != -1) return dp[i][val];
    bool result = false;
    if(alice)
        dp[i][val] = result = (dfs(piles, dp, i+1, !alice, aliceCount+piles[i], bobCount) || dfs(piles, dp, i+1, !alice,  aliceCount+piles[piles.size()-1-i], bobCount));
    else
        dp[i][val] = result = (dfs(piles,dp, i+1, !alice, aliceCount, bobCount+piles[i]) || dfs(piles, dp, i+1, !alice, aliceCount, bobCount+piles[piles.size()-1-i]));
    return result;
}

int maximumTastiness(vector<int>& price, int k) {

    sort(price.begin(), price.end());
    int low = price[0];
    //int high = price[price.size()];
    int high = INT_MAX;

    auto check = [&price, &k](int mid)
    {
        int cnt = 1;
        int prev = price[0];
        for (int i = 1; i < price.size(); i++)
        {
            if (price[i]-prev >= mid) {
                ++cnt;
                prev = price[i];
            }
        }
        return cnt >= k;
    };

    int result = 0;
    while (low <= high) {
        int mid = low + (high-low)/2;
        if (check(mid)) {
            result = mid;
            cout << "mid" << mid << endl;
            low = mid + 1;
        } else
            high = mid - 1;
    };
    return result;
}

int maximumGroups(vector<int>& grades) {
    
    sort(grades.begin(), grades.end());
    int low = grades[0];
    int high = INT_MAX;

    auto check = [&grades](int mid)
    {
        int sum = 0;
        int groups = 0;
        int prev = 0;
        int cnt = 0;
        int prevCnt = 0;
        for (int i = 0; i < grades.size(); i++)
        {
            ++cnt;
            sum += grades[i];
            if (sum >= mid && sum > prev && cnt > prevCnt ) {
                prev = sum;
                prevCnt = cnt;
                cout << "sum= " << sum <<"prev= "<<prev<<"prevCnt= "<<prevCnt<<endl;
                sum = 0;
                cnt = 0;
                ++groups;
            }
        }
        cout << "groups " << groups <<sum<<" "<<cnt<<endl;
        return groups;
    };

    int maxResult = 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int groups = check(mid);
        if (groups >= maxResult) {
            maxResult = groups;
            cout << " result " << maxResult << endl;
            high = mid - 1;
        } else
            low = mid + 1;
    };
    return maxResult;
}

int minimumSize(vector<int>& nums, int maxOperations) {
    int low = 1;
    int n = nums.size();
    int high = *max_element(nums.begin(), nums.end());

    auto check = [&nums, &maxOperations](int mid)
    {
        int cnt = 0;
        int num = 0;
        cout << "mid = " << mid << endl;
        for(auto& num : nums) {
            if (num > mid) { 
                cnt += num / mid;
                if (num % mid == 0) --cnt;
                cout << "cnt" << cnt << endl;
                if (cnt > maxOperations)
                    return false;
            }
        }
        return true;
    };

    int lowest = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(check(mid)) {
            lowest = mid;
            high = mid - 1;
        } else
            low = mid + 1;
    };
    return lowest;
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    if (n == 1) return 0;
    int result = 0;

    unordered_map<int, vector<int>> Map;
    return result;
}


    // queue<int> q;
    // q.push(headID);
    // int maxResult = 0;
    // while (! q.empty()) {
    //     int parent = q.front();
    //     q.pop();
    //     if (manager[parent] > -1)
    //         result = informTime[manager[parent]];

    //     int result = 0;
    //     for(int i =0; i<n; i++) {
    //         int child = manager[i];
    //         if (child == -1) continue;
    //         if (child == parent) {
    //             q.push(child);
    //         }             
    //     }

    // };
   

//int main(){

    //cout << "Hello World"<<endl;
    // vector<int> barcodes = {1, 1, 1, 2, 2, 2};
    // vector<int> results = rearrangeBarcodes(barcodes);
    // cout << "results";
    // for(const auto& i: results)
    //     cout << i<<',';
    // cout << endl;
    //vector<int> nums = {1, 3, 1, 2, 2};
    //vector<int> nums = {5, 5, 5, 5};
    // vector<int> nums = {459, 459, 962, 1579, 1435, 756, 1872, 1597};
    // int result = countCompleteSubarrays(nums);
    // cout << "results "<<result<<endl;
    //vector<int> fruits = {1, 2, 1};
    //vector<int> fruits = {0, 1, 2, 2};
    //vector<int> fruits = {1, 2, 3, 2, 2};
    //vector<int> fruits = { 3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4 };
    //vector<int> fruits = {1, 1};
    //vector<int> fruits = {0};
    // vector<int> fruits = {0, 1, 6, 6, 4, 4, 6};
    // int result = totalFruit(fruits);
    // cout << "results "<<result<<endl;
    //vector<vector<int>> grid{{2,4,3,5},{5,4,9,3},{3,4,2,11},{10,9,13,15}};
    // vector<vector<int>> grid{{3,2,4},{2,1,9},{1,1,7}};
    //vector<vector<int>> grid {{ 2, 4, 3, 5 }, { 5, 4, 9, 3 }, { 3, 4, 2, 11 }, { 10, 9, 13, 15 } };
    // int result = maxMoves(grid);
    // string s = "adaa";
    // string chars = "d";
    // vector<int> vals = {-1000};
    // string s = "kqqqqqkkkq";
    // string chars = "kq";
    // vector<int> vals = {-6,6};
    // int result = maximumCostSubstring(s, chars, vals);
    // cout << "Result = " << result << endl;
    //vector<int> piles = {5, 3, 4, 5};
    // vector<int> price = {13, 5, 1, 8, 21, 2};
    // int k = 3;
    // vector<int> price = {7, 7, 7, 7};
    // int k = 2;
    // int result = maximumTastiness(price, k);
    //vector<int> grades{10, 6, 12, 7, 3, 5};
    //vector<int> grades{8, 8 };
    //vector<int> grades{2, 31, 41, 31, 36, 46, 33, 45, 47, 8, 31, 6, 12, 12, 15, 35};
    // vector<int> grades{471, 661, 234, 1353, 1684, 526, 65, 497, 422, 948, 1290, 1541, 1645, 878, 640, 1904, 1825, 1693, 652, 1623, 1623, 271, 1860, 933, 994, 1726, 1687, 1374, 1353, 974, 1422, 826, 667, 652, 652, 570, 1766, 695, 1530, 147, 948, 195, 974, 441, 1010, 1967, 1149, 1272, 1667, 844, 825, 244, 1093, 740, 349, 144, 216, 1224, 1780, 1667, 879, 1768, 783, 1416};
    // int result = maximumGroups(grades);
    // vector<int> nums = {9};
    // int maxOperations = 2;
    //vector<int> nums = {2, 4, 8, 2};
    // int maxOperations = 4;
    // int result = minimumSize(nums, maxOperations);
    // cout << "Result = " << result << endl;
    // int n = 6;
    // vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    // int result = countCompleteComponents(n, edges);
    // cout << "Result = " << result << endl;

//     int n = 6, headID = 2;
//     vector<int> manager = {2,2,-1,2,2,2}, informTime = {0,0,1,0,0,0};
//     int result =  numOfMinutes(n, headID, manager, informTime);
//     cout << "Result = " << result << endl;
//     return 0;
// }