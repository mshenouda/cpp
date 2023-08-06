#include "./ccode.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <queue>
#include <set>
using namespace std;

int main() {
  cout<<"Hello World Again"<<std::endl;
  T t;
  std::vector<std::vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
  auto result = t.findRedundantConnection(edges);
  cout<<"Result "<<result[0]<<" "<<result[1]<<endl;
  return 0;
}
