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
#include <valarray>
#include "leetcode.h"
#include <numeric>
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

    if(word.size() == 1) return 0;

    map<char, int> counter{};
    std::set<int> s;
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
    for(const int& val: s)
        cout << " val = " << val<<endl;

    if (s.size() > 2 || s.size() < 2)
        return false;

    if (s.size() == 1) return true;

    auto start = s.begin();
    auto end = s.end();
    return *start == (*end - 1); 

}

void sorting() {
    vector<string> vec = {"shenouda", "hanna", "mina"};
    // std::sort(vec.begin(), vec.end(), [0](const string& a, const string& b){
    //     if (choice == 0)
    //         return a.length() < b.length();
    //     else
    //         return a.length() >= b.length();
    // });
    cout<<"Output = ";
    for(const auto& item: vec) {
        cout<<item<<" ";
    }
    cout<<endl;
}

void handleString() {

    string s1 = "mina shenouda";
    string s2 = s1; //copy by value
    const string& s3(s1);
    string& s4 = s1; //copy by reference
    
    cout<<"s1 = "<<s1<<endl;
    cout<<"s2 = "<<s2<<endl;
    cout<<"s3 = "<<s3<<endl;
    cout<<"s4 = "<<s4<<endl;
    
    s1 = "shenouda";
    //s3 = "shosho";
    cout<<"s1 = "<<s1<<endl;
    cout<<"s2 = "<<s2<<endl;
    cout<<"s3 = "<<s3<<endl;
    cout<<"s4 = "<<s4<<endl;
}

void handleAlgorithms() {
    vector<int> v = {1, 6, 4};
    int x = 3;
    // std::transform(v.cbegin(), v.cend(), v.begin(), [&x](int i){
    //     ++x;
    //     return i*=x;
    // });
    // std::for_each(v.begin(), v.end(), [&x](int i){
    //     ++x;
    //     return i*=x;
    // });
    // for(const auto& i: arr) {
    //     cout<<" i "<<i<<" "<<endl;
    // }
    cout<<"x = "<<x<<endl;
    cout<<endl;
}

void handleArray() {
    std::array<std::size_t, 5> arr{10, 32, 25, 5, 1};
    std::array<std::size_t, 5> xArr;
    xArr.fill(2);
    cout<<"[]  ="<<arr[0]<<endl;
    cout<<"at  ="<<arr.at(0)<<endl;
    cout<<"front  ="<<arr.front()<<endl;
    cout<<"back  ="<<arr.back()<<endl;
    cout<<"data  ="<<*(arr.data()+arr.size()-1)<<endl; 
    cout<<"size  ="<<arr.size()<<endl; 
    cout<<"max_size  ="<<arr.max_size()<<endl; 
    //cout<<"max_size  ="<<arr.max_size()<<endl; 
    
    
    //xArr.swap(arr);
    //arr.swap(xArr);
    std::swap(arr, xArr);
    cout<<"Contents of arr "<<endl;
    for(std::array<std::size_t, 5>::iterator it = arr.begin(); it != arr.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"Contents of xArr"<<endl;
    for(std::array<std::size_t, 5>::iterator it = xArr.begin(); it != xArr.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void handleVector() {
    vector<int> v = {1, 2, 5, 6};
    auto pos = v.begin() + 2; 
    assert(*pos == 5);
    const auto rg = std::list{-1, -2, -3};
    v.insert(pos, v.begin()+1, v.begin()+2);
    for(const auto& i: v) {
        cout<<"i ="<<i<<" "<<endl;
    }
    cout<<endl;
}

struct Sum {
    int sum{0};
    void operator()(int n) {
        sum += n;
    }
}; 

void println(auto const& v)
{
    for (auto count{v.size()}; auto const& e : v)
        std::cout << e << (--count ? "; " : "\n");
}
 
bool contains(const auto& cont, std::string_view s)
{
    // str.find() (or str.contains(), since C++23) can be used as well
    return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
}

void handleLambda() {
    
    // for_each(v.begin(), v.end(), [](const int& i){return i*3;});
    //     for(const auto& i: v) {
    //     cout<<"i ="<<i<<" "<<endl;
    // }
    
    // for_each(v.begin(), v.end(), [&x](const int& i){
    //     ++x;
    //     cout<<i*x<<' ';
    // });
    
    // for(const auto& i: v) {
    //     cout<<"i ="<<i<<" "<<endl;
    // }
    // Sum s = for_each(v.begin(), v.end(), Sum());
    // cout<<"Sum = "<<s.sum<<endl;
    // cout<<endl;

    std::vector<int> vi {1, 2, 3, 4, 5};
    println(vi);
 
    std::for_each_n(vi.begin(), 2, [](auto& n) { n *= 2; });
    println(vi);

    // std::remove(vi.begin(), vi.end(), [](int i){
    //     return i % 2 == 0;
    // });

    // std::vector<int> v(5, 2);
    // std::partial_sum(v.cbegin(), v.cend(), v.begin());
    // std::cout << "Among the numbers: ";
    // std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, ","));
    // std::cout << '\n';

    // if (std::all_of(v.cbegin(), v.cend(), [](int i) { return i % 2 == 0; }))
    //     std::cout << "All numbers are even\n";
 
    // if (std::none_of(v.cbegin(), v.cend(), std::bind(std::modulus<>(),
    //                                                  std::placeholders::_1, 2)))
    //     std::cout << "None of them are odd\n";
 
    // struct DivisibleBy
    // {
    //     const int d;
    //     DivisibleBy(int n) : d(n) {}
    //     bool operator()(int n) const { return n % d == 0; }
    // };
 
    // if (std::any_of(v.cbegin(), v.cend(), DivisibleBy(7)))
    //     std::cout << "At least one number is divisible by
    
    // const auto v = {1, 2, 3, 4};
    // for (const int n : {3, 5})
    //     (std::find(v.begin(), v.end(), n) == std::end(v))
    //         ? std::cout << "v does not contain " << n << '\n'
    //         : std::cout << "v contains " << n << '\n';

    // auto is_even = [](int i) { return i % 2 == 0; };
 
    // for (auto const& w : {std::array{3, 1, 4}, {1, 3, 5}})
    //     if (auto it = std::find_if(w.begin(), w.end(), is_even); it != std::end(w))
    //         std::cout << "w contains an even number " << *it << '\n';
    //     else
    //         std::cout << "w does not contain even numbers\n";

    // constexpr std::array v{1, 2, 3, 4, 4, 3, 7, 8, 9, 10};
    // std::cout << "v: ";
    // std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << '\n';
 
    // // Determine how many integers match a target value.
    // for (const int target : {3, 4, 5})
    // {
    //     const int num_items = std::count(v.cbegin(), v.cend(), target);
    //     std::cout << "number: " << target << ", count: " << num_items << '\n';
    // }
 
    // // Use a lambda expression to count elements divisible by 4.
    // int count_div4 = std::count_if(v.begin(), v.end(), [](int i) { return i % 4 == 0; });
    // std::cout << "numbers divisible by four: " << count_div4 << '\n';
 
    // // A simplified version of `distance` with O(N) complexity:
    // auto distance = [](auto first, auto last)
    // {
    //     return std::count_if(first, last, [](auto) { return true; });
    // };
    // static_assert(distance(v.begin(), v.end()) == 10);

    // const auto str{"why waste time learning, when ignorance is instantaneous?"sv};
    // assert(contains(str, "learning"));
    // assert(not contains(str, "lemming"));

    // std::string str1{"Text with some   spaces"};
    // auto noSpaceEnd = std::remove(str1.begin(), str1.end(), ' ');
 
    // // The spaces are removed from the string only logically.
    // // Note, we use view, the original string is still not shrunk:
    // std::cout << std::string_view(str1.begin(), noSpaceEnd) 
    //           << " size: " << str1.size() << '\n';
 
    // str1.erase(noSpaceEnd, str1.end());
 
    // // The spaces are removed from the string physically.
    // std::cout << str1 << " size: " << str1.size() << '\n';
 
    // std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
    // str2.erase(std::remove_if(str2.begin(), 
    //                           str2.end(),
    //                           [](unsigned char x) { return std::isspace(x); }),
    //            str2.end());
    // std::cout << str2 << '\n';

    // std::array<int, 10> s {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
 
    // auto print = [&s](std::string_view const rem)
    // {
    //     for (auto a : s)
    //         std::cout << a << ' ';
    //     std::cout << ": " << rem << '\n';
    // };
 
    // std::sort(s.begin(), s.end());
    // print("sorted with the default operator<");
 
    // std::sort(s.begin(), s.end(), std::greater<int>());
    // print("sorted with the standard library compare function object");
 
    // struct
    // {
    //     bool operator()(int a, int b) const { return a < b; }
    // }
    // customLess;
 
    // std::sort(s.begin(), s.end(), customLess);
 
    // print("sorted with a custom function object");
    // std::sort(s.begin(), s.end(), [](int a, int b) {
    //     return (a > b);
    // });
    // print("sorted with a lambda expression");

    //std::vector<int> v {3, 1, -14, 1, 5, 9};
 
    // namespace ranges = std::ranges;
    // auto result = ranges::max_element(v.begin(), v.end());
    // std::cout << "Max element at pos " << ranges::distance(v.begin(), result) << '\n';
 
    // auto abs_compare = [](int a, int b) { return std::abs(a) < std::abs(b); };
    // result = ranges::max_element(v, abs_compare);
    // std::cout << "Absolute max element at pos "
    //           << ranges::distance(v.begin(), result) << '\n';

    // std::vector<int> v{4, 5, 6};
    // auto it = v.begin();
    // auto nx = std::next(it, 2);
    // std::cout << *it << ' ' << *nx << '\n';
 
    // it = v.end();
    // nx = std::next(it, -2);
    // std::cout << ' ' << *nx << '\n';

//     std::vector<int> v{3, 1, 4};
//     assert(std::ranges::distance(v.begin(), v.end()) == 3);
//     assert(std::ranges::distance(v.end(), v.begin()) == -3);
//     assert(std::ranges::distance(v) == 3);
 
//     std::forward_list<int> l{2, 7, 1};
//     // auto size = std::ranges::size(l); // error: not a sizable range
//     auto size = std::ranges::distance(l); // OK, but aware O(N) complexity
//     assert(size == 3);
    vector<int> v { 1 , -3, 5};
    Multiplier multiplier(5);
    

    // cout<<" Multipler "<<multiplier(10);
    for_each(v.begin(), v.end(), multiplier);
    for(const auto i: v) {
        cout<<" i "<<i<<endl;
    }
    std::cout<<std::endl;
}

int main() {

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
   
    // const string word = "abcc";
    // bool result = equalFrequency(word);
    // cout << "Result = " << (result ? "True": "False") << std::endl;   
    //sorting();

    // handleString();
    //handleVector();
    //handleAlgorithms();
    //handleArray();
    //handleVector();   
    handleLambda();
    return 0;
}