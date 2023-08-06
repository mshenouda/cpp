#pragma once
#ifndef CCODE_H
#define CCODE_H
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

class T {
	private:
		int n;

	public:
		T();
		std::string welcome(std::string&);
		void findMax(std::vector<int> &);
		void useMap(int);
		std::vector<int> returnFunction(int); 
		std::vector<int> diffWaysToCompute(std::string);
		std::vector<int> solve(std::string);
		std::string manipulateString(std::string);
		vector<int> divisibilityArray(std::string word, int m);
		std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges);
};
#endif
