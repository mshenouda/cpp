#include <iostream>
#include <string>
#include <vector> 
#include <functional>
#include <unordered_set>
#include <algorithm>
#include <limits.h>
#include <map>
#include <unordered_map>
#include <time.h>
#include <set>
#include <stdlib.h>
#include <array>
#include <iterator>
#include <queue>

using namespace std;

class DisjointSet{
    public:
        std::vector<int> parent, size;
        DisjointSet (int n){
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i=0; i<=n; i++) parent[i] = i;
        }
        int findUPar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        bool findParEqual (int u, int v){
            return findUPar(u)==findUPar(v);
        }
        void unionBySize (int u, int v){
            int ulp_u = findUPar(u), ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
std::vector<int> T::findRedundantConnection(std::vector<std::vector<int>>& edges) {
    int n = edges.size();
    DisjointSet ds(n);
    std::vector<std::vector<int>> ans;
    for(auto it: edges){
        if(ds.findParEqual(it[0], it[1])) ans.push_back(it);
        ds.unionBySize(it[0], it[1]);
    }
    return ans.back();
}


class Functor {
        int val;
    public:
        Functor(int x): val(x) {};
        int operator()(int x) {
            return val * x;
        }
};


class MultiplyBy {
private:
    int factor;

public:
    MultiplyBy(int x) : factor(x) {
    }

    int operator () (int other) const {
        return factor * other;
    }
};

class Multiplier {  
    public:  
      Multiplier(int factor) : factor_(factor) {}  
      
      int operator()(int x) const {  
        return x * factor_;  
      }  
      
    private:  
      int factor_;  
    };  

// int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    
//     //std::function<int(int,vector<vector<int>>,int)> dfs;
//     const std::function<int(int,vector<vector<int>>,int)> dfs = [&dfs, &forbidden, &a, &b, &x](int pos, vector<vector<int>>& dp, bool move) {
//         if (pos == x) return 0;
//         if (pos > 6000 || pos < 0) return 6001;
//         if (find(forbidden.begin(), forbidden.end(), pos) != forbidden.end()) return 6001;  
//         if (dp[pos][move] != -1) return dp[pos][move]; 

//         int stepA = 6001;
//         int stepB = 6001;
//         dp[pos][move] = stepA = 1 + dfs(pos + a, dp, 0);        
//         if (move == 0 && (pos - b > 0))
//             dp[pos][move] = stepB = 1 + dfs(pos-b, dp, 1);
//         return dp[pos][move] = min(stepA, stepB);
//     };

//     int start = 0;
//     vector<vector<int>> dp(6001, vector<int>(2, -1));
//     bool move = false;   
//     int result = dfs(start, dp, move);
//     return (result > 6000) ? -1 : result;
// }

// int dfs(int pos, vector<vector<int>>& dp, int move, vector<int>& forbidden,int a, int b, int x) {
    
//     if (pos == x) return 0;
//     if (pos > 6000 || pos < 0) return 6001;
//     if (find(forbidden.begin(), forbidden.end(), pos) != forbidden.end()) return 6001;  
//     if (dp[pos][move] != -1) return dp[pos][move]; 

//     int stepA = 6001;
//     int stepB = 6001;
//     dp[pos][move] = stepA = 1 + dfs(pos + a, dp, 0, forbidden, a, b, x);        
//     if (move == 0 && (pos - b > 0))
//         dp[pos][move] = stepB = 1 + dfs(pos-b, dp, 1, forbidden, a, b, x);
//     return dp[pos][move] = min(stepA, stepB);
// };


// int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    
//     int start = 0;
//     vector<vector<int>> dp(6001, vector<int>(2, -1));
//     bool move = false;   
//     int result = dfs(start, dp, move, forbidden, a, b, x);
//     cout<<result<<endl;
//     return (result > 6000) ? -1 : result;
// }

// int dfs(int n, vector<int>& nums, vector<int>& dp, int target, int pos=0) {
    
//     if(pos == n-1) return 0;
//     if (dp[pos] != -1) return dp[pos];

//     int cnt = INT_MIN;
//     for(int i=pos+1; i<n; ++i) {
//         if (abs(nums[i] - nums[pos]) <= target) {
//             int val = dfs(n, nums, dp, target, i);
//             if(val >= 0)
//                 ++val;
//             cnt = max(val, cnt);
//         }
//     }
//     return dp[pos] = cnt;
// }   


// int maximumJumps(vector<int>& nums, int target) {
    
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     dp[n-1] = 0;
//     int result = dfs(n, nums, dp, target);
//     return (dp[0] == INT_MIN) ? -1 : result;
// }

//     int dp[100005];
//     int mod = 1e9+7;
//     int solve(string &str, int idx) {
//         if(idx == str.length()) return 1;
//         if(dp[idx] != -1) return dp[idx];
//         int maxKeyPress = (str[idx] == '7' || str[idx] == '9') ? 4 : 3;
//         long long currIndex = idx, pressFrequency = 1, ans = 0;
//         while(pressFrequency <= maxKeyPress && str[currIndex] == str[idx]) {
//             ++currIndex;
//             ++pressFrequency;
//             ans += solve(str, currIndex) % mod;
//         }
//         return dp[idx] = ans%mod;
//     }


// int countTexts(string pressedKeys) {
//     return solve(pressedKeys, 0) % mod;
// }

    // for(int i=pos; i<n; i++) {
    //     for(int j= i+minJump; j<=min(n-1, i+maxJump); ++j) {
    //         if (s[j] == '0')
    //             result = result || dfs(n, s, dp, minJump, maxJump, j);
    //     }
    // }

// bool dfs(int n, string& s, unordered_map<int, bool>& dp, int minJump, int maxJump, int pos=0) {
//     if (pos == n-1) return dp[pos] = true;
//     if (pos >= n ) return false;
//     if (dp.find(pos) != dp.end()) return dp[pos];
//     bool result = false;
//     for(int i=pos+minJump; i<=min(n-1, pos+maxJump); ++i) {
//         if (s[i] == '0') {
//             result = result || dfs(n, s, dp, minJump, maxJump, i);
//         }
//     }
//     return dp[pos] = result;
// }

// bool canReach(string s, int minJump, int maxJump) {
//     int n = s.size();
//     unordered_map<int, bool> dp;
//     bool result = dfs(n, s, dp, minJump, maxJump);
//     for(const auto& item: dp) 
//         cout<<item.first<<" "<<item.second<<endl;
//     return result;
// }

// int dfs(int n, vector<int>& days, vector<int>& costs, int pos=0) {
//     if(pos >= n) return 0;
    

//     int cost = 0;
//     int op1, op2, op3 = 0;
//     for(int i=pos; i<days[n-1]+1; i++) {
//         //if(option ==)
//         if(find(days.begin(), days.end(), i) != days.end()) {
//             op1 = costs[0] + dfs(n, days, costs, i); 
//         }
//         op2 = costs[1] + dfs(n, days, costs, i+7-1);
//         op3 = costs[2] + dfs(n, days, costs, i+20-1);
//     }
        

// } 

// int mincostTickets(vector<int>& days, vector<int>& costs) {
//     int n = days.size();
//     int result = dfs(n, days, costs);s
//     return result;
// }

bool dfs(int maxInteger, int total, vector<vector<int>>& dp, int player, int num=0, set<int> visited = {}) {

    if(total == 0) return true;
    if(num > total) return false;
    if (dp[num][player] != -1) return dp[num][player];

    bool result = false;
    int i=0;
    for(i=1; i<= maxInteger; ++i) { 
        if (find(visited.begin(), visited.end(), i) == visited.end()) { 
            visited.insert(i);
            result = result || dfs(maxInteger, total-i, dp,  player = (player == 0) ? 1 : 0, i, visited);
            result = (player == 0) ? result : !result;
            dp[i][player] = result ? 1 : 0;
            visited.erase(i);
            //total+=i;
        }
    }
    return dp[num][player];
    //return result;
}

bool canIWin(int maxInteger, int total) {

    vector<vector<int>> dp(maxInteger+1, vector<int>(2, -1));
    enum Player {
        player1 = 0,
        player2 
    };

    //dp[0][0] = 0;
    bool result = dfs(maxInteger, total, dp, 0);  
    for(int i=0; i<dp.size(); i++) {
        cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    return result;
}

void handleSetsMaps () {

    enum Player {
        left,
        right,
        up,
        down
    };
    typedef pair<Player, int> pii;
    map<pii, int> MyMap;
    for(int i=0; i<4; ++i) {
        switch(i) {
            case 0:
                MyMap[{Player::left, i}] = i;
                break;
            case 1:
                MyMap[{Player::right, i}] = i;
                break;
            case 2:
                MyMap[{Player::up, i}] = i;
                break;
            case 3:
                MyMap[{Player::down, i}] = i;
                break;
        }   
    }
    // cout<<"Item\t"<<"Key\t"<<"Value"<<endl;
    // for(const auto& item: MyMap)
    //     cout<<item.first.first<<"\t"<<item.first.second<<"\t"<<item.second<<endl; 

    vector<int> v{1, 1, 1, 5, 5, 7, 6,4};
    // set<int, greater<int>> s(v.begin(), v.end());
    // cout<<s.size()<<endl;
    // for(auto it = s.begin(); it != s.end(); ++it) 
    //     cout<<*it<<"\t";
    set<int> s(v.begin(), v.end());
    for(auto it = s.begin(); it != s.end(); ++it) 
        cout<<*it<<"\t";
    
    auto it = s.rbegin(); 
    cout<<*it<<endl;

    auto i = s.lower_bound(3);
    cout<<*i<<endl;
    cout<<endl;        
    
}

void handlePriority() {
    typedef pair<int, int> pii;
    vector<pii> v{{2,5}, {1,6}, {1,8}, {2,4}};
    priority_queue<pii, vector<pii>, greater<pii>> pq(v.begin(), v.end());
    while (!pq.empty()) {
        pii val = pq.top(); 
        cout<<val.first<<"\t"<<val.second<<endl;
        pq.pop();
    } 
    cout<<endl;
}

  
void handleAlgorithms() {

    typedef pair<int, int> pii;
    struct Functor {
        //template <typename T>  
        bool operator()(pii a, pii b){return b.second < b.first;};
    };

    vector<pii> items{{2,5}, {1,6}, {1,8}, {2,4}};
    vector<string> strs{"egypt", "usa", "france"};
    //auto custom = [](pii a, pii b){return b.second < b.first;};
    //sort(items.begin(), items.end(), greater<pii>());
    // sort(items.begin(), items.end(), Functor());
    // for(const auto& item: items)
    //     cout<<item.first<<"\t"<<item.second<<endl;

    auto custom = [](string a, string b){
        set<char> s = {'a','b','c','d','e'};
        if(s.find(a[0]) != s.end())
            return a.size() < b.size();
        return b.size() < a.size();
    };

    sort(strs.begin(), strs.end(),custom);
    for(const auto& str: strs)
        cout<<str<<"\t"<<endl;
}

void handleIterators() {

    vector<int> vec{2, 5, 8, 9};
    vector<int>::iterator itr = vec.begin();
    cout<<*(++itr)<<" "<<*(++itr)<<endl;
    itr = vec.begin();
    ++itr;
    // sort(vec.begin()+1, vec.end(), less<int>());
    // while(itr != vec.end()) {
    //     cout<<*itr<<"\t";
    //     itr++;
    // };

    // itr = find(vec.begin(), vec.end(), 8);
    // vec.insert(itr, {5,10,12});
    // for(const auto& v: vec)
    //     cout<<v<<"\t";
    // cout<<endl;

    vector<int> vec1{4, 5};
    vector<int> vec2{4, 5, 12, 16};
    vector<int>::iterator it = find(vec2.begin(), vec2.end(), 16);
    //insert_iterator<vector<int>> i_itr(vec2, it);
    back_insert_iterator<vector<int>> i_itr(vec2);
    copy(vec1.begin(), vec1.end(), i_itr);
    for(const auto& v: vec2)
        cout<<v<<" ";
    cout<<endl;

    vector<string> vec4;
    cout<<"Type string"<<endl;
    // copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(vec4));
    // copy(vec4.begin(), vec4.end(), ostream_iterator<string>(cout, "\t"));
    // for(const auto& n : vec4)
    //     cout<<n<<" ";
    // cout<<endl;
    reverse_iterator<vector<int>::iterator> r_itr; 
    for(r_itr = vec2.rbegin(); r_itr!= vec2.rend(); r_itr++)
        cout<<*r_itr<<" ";
    cout<<endl;

}

void review() {
    //vector<int> nums = {5, 6, 7, 8};
    std::array nums = {50,60,70, 80};
    // for(const auto& num : nums) 
    //     for(int i=0; i<5; i++)
    //         cout<<(num<<i)<<" "<<(num>>i)<<endl;

    // int val = 2;
    // int* const p = &val; //const pointer
    // val = 4;

    // int &ref = nums[0];
    // int *p = &ref;

    // ref = 10;
    // for(int i=0; i<nums.size(); ++i) {
    //     cout<<*p<<endl;
    //     ++p;
    // }
    //p++;
    // cout<<*p<<endl;
    // int c = 5;
    // int &var = c;
    // c++;
    // cout<<var<<endl; 

    // for(int i=0; i<5; ++i)
    //     p[i] = i;
    // cout<<endl;
    // int* ptr = p;
    // for(int i=0; i<5; ++i)
    //     cout<<*(ptr+i)<<endl;
    // val = 4;
    // ptr = &val;

    //const int* ptr = new int;
   
    // for(const auto& num : nums) {
    //     ptr = &num;
    //     cout<<*(ptr++)<<endl;
    // } 
        
}

int main() {

    cout<<"Hello World"<<endl;

    // vector<int> forbidden = {14,4,18,1,15};
    // int a = 3, b = 15, x = 9;

    // vector<int> forbidden = {8,3,16,6,12,20};
    // int a = 15, b = 13, x = 11;

    // vector<int> forbidden = {1,6,2,14,5,17,4};
    // int a = 16, b = 9, x = 7;

    // vector<int> forbidden = {162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98};
    // int a = 29, b = 98, x = 80;
    
    // int result = minimumJumps(forbidden, a, b, x);
    // cout<<"Result = "<<result<<endl;
    // vector<int> nums = {1,3,6,4,1,2};
    // int target = 2;
    // vector<int>nums = {1,3,6,4,1,2};
    // int target = 3;

    // vector<int> nums = {1,3,6,4,1,2};
    // int target = 0;
    // int result = maximumJumps(nums, target);
    // cout<<"Result = "<<result<<endl;
    
    // string pressedKeys = "22233"
    // int result = countTexts(string pressedKeys);
    // cout<<"Result = "<<result<<endl;

    // string s = "011010";
    // int minJump = 2, maxJump = 3;

    // string s = "01101110";
    // int minJump = 2, maxJump = 3;    
    // bool result = canReach(s, minJump,maxJump);
    // cout<<"Result = "<<(result ? "True":"False")<<endl;
    // vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
    // int result = mincostTickets(days, costs);
    // cout<<"Result = "<<result<<endl;
    //int maxInteger = 10, total = 11;
    // int maxInteger = 3, total = 5;
    // bool result = canIWin(maxInteger, total);    
    // cout<<"Result = "<<(result?"True":"False")<<endl;
    //review();
    //handleSetsMaps();
    //handlePriority();
    //handleAlgorithms();
    handleIterators();
    return 0;
}
