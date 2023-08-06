       
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <utility>
using namespace std;
class stockprice {
    private:
        set<pair<int,int>> s; //{price ,-time}
        map<int,int> m; // -time : price
public:
    stockprice();
    void update(int timestamp, int price);
    int current();
    int maximum();
    int minimum();
};
