#include "pch.h"
#include "linkList.h"
#include "MinStack.h"
#include "Tree.h"
#include <algorithm>
#include <stdlib.h>
#include <utility>
#include <set>
#include <iterator>
#include <ctype.h>
#include <list>
#include <functional>
#include <climits>
#include <array>
#include <numeric>
#include <iostream>
#include <queue>
#include <regex>
#include <sstream> 
#include <math.h>
#include <array>
#include <exception>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stack>
#include "Tree.h"

using namespace std;
//Function Declarations

class Node{
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};


template<typename T>
vector<T> getRow(T);

template<typename T>
void printvector(T&);

template<typename T>
void print2Dvector(T&);

string longestCommonPrefix(vector<string>& strs);
bool checkPossibility(vector<int>&);
string toHex(int);
bool isBoomerang(vector<vector<int>>&);
int oddCells(int, int, vector<vector<int>>&);
TreeNode* increasingBST(TreeNode*);
int maxDepth(Node*);
void doMaxDepth(Node*, int, int&);
int maxDepth(TreeNode*);
bool divisorGame(int N);
int sumRootToLeaf(TreeNode*);
bool hasPathSum(TreeNode*, int);
int minDepth(TreeNode* root);
int guessNumber(int);
vector<string> binaryTreePaths(TreeNode*);

int main()
{
	cout << " Hello World " << endl;

	/*
	vector<string> strs{ "reflower", "flow", "flight"};
	string result = longestCommonPrefix(strs);
	cout << result << endl;
	*/

	/*
	vector<int> nums{4, 3, 2};
	cout<<checkPossibility(nums);
	*/

	/*
	int num = -26;
	cout<<toHex(num);
	*/
	
	/*
	vector<vector<int>> points{ {52, 86}, { 12, 65 }, { 24, 71 } };
	cout<<isBoomerang(points);
	*/
	//n = 2, m = 2, indices = [[1, 1], [0, 0]]
	
	/*
	int n = 2;
	int m = 3;
	vector<vector<int>> indices{ {0, 1}, {1, 1} };
	//vector<vector<int>> indices{ {1, 1}, {0, 0} };
	cout<<oddCells(n, m, indices);
	*/

	/*
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);

	TreeNode* leftChild = root->left;
	TreeNode* rightChild = root->right;

	leftChild->left = new TreeNode(2);
	leftChild->right = new TreeNode(4);
	rightChild->left =	NULL;
	rightChild->right = new TreeNode(8);
	TreeNode* newRoot = increasingBST(root);
	*/ 
	
	/*
	vector<Node*> children(4);
	children[0] = NULL;
	children[1] = NULL;
	children[2] = new Node(2);
	children[3] = new Node(4);
	Node *root = new Node(1, children);
	
	vector<Node*> children2(3);
	children2[0] = NULL;
	children2[1] = new Node(5);
	children2[2] = new Node(6);
	Node *_1st = new Node(3, children2);
	root->children[1] = _1st;

	cout << maxDepth(root);
	*/
	
	/*
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);

	TreeNode* leftChild = root->left;
	TreeNode* rightChild = root->right;

	leftChild->left = NULL;
	leftChild->right = NULL;
	rightChild->left = new TreeNode(15);
	rightChild->right = new TreeNode(7);
	cout<<maxDepth(root);
	*/

	/*
	srand((unsigned int)time(NULL));
	int N = 9;
	cout<<divisorGame(N);
	*/
	/*
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	
	TreeNode* leftChild = root->left;
	TreeNode* rightChild = root->right;
	
	leftChild->left = NULL;
	leftChild->right =	NULL;
	
	rightChild->left = new TreeNode(15);
	rightChild->right = new TreeNode(7);
	/*
	TreeNode* _2leftChild = leftChild->left;
	TreeNode* _2rightChild = rightChild->right;

	_2leftChild->left = new TreeNode(7);
	_2leftChild->right = new TreeNode(2);
	_2rightChild->right = new TreeNode(1);
	*/
	//cout << sumRootToLeaf(root);
	/*
	int sum = 22;
	cout << hasPathSum(root, sum);
	*/

	//cout << minDepth(root);
	/*
	int n = 10; 
	int result = guessNumber(n);
	cout<<result;
	*/

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	TreeNode* leftChild = root->left;
	TreeNode* rightChild = root->right;

	leftChild->left = NULL;
	leftChild->right = new TreeNode(5);
		
	rightChild->left = NULL;
	rightChild->right = NULL;

	TreeNode* _2ndChild = leftChild->right;
	_2ndChild->left = NULL;
	_2ndChild->right = NULL;
	vector<string> result = binaryTreePaths(root);
	printvector(result);

	return 0;
}

string longestCommonPrefix(vector<string>& strs)
{
	string result;

	if (strs.empty())
		return result;
	
	if (strs.size() == 1)
		return strs[0];
	
	return result;
}


void doPossibility(vector<int>& nums, int index, int a, int b)
{
	printvector(nums);
	
	for (int i = index; i < nums.size() - 1; i++)
	{
		if (i > -1 && i < nums.size())
		{
			if (nums[i] > nums[i + 1])
			{
				//forward direction
				nums[i+1] = nums[i];
				doPossibility(nums, index + 1, nums[i], nums[i + 1]);
				cout << a << " " << b << endl;

				//backward direction
				nums[i] = nums[i + 1];
				doPossibility(nums, index - 1, nums[i], nums[i+1]);
			}
		}
	}
	return;
}

bool checkPossibility(vector<int>& nums) {

	if (nums.empty())
		return false;

	if (nums.size() == 1)
		return false;

	if (nums.size() == 2)
		return true;

	int counter = 0;
	int index = 0;

	doPossibility(nums, index, 0, 0);
	
	//return (counter == 1);
	return false;
}

void towsComplement(vector<bool>& vec)
{
	bool flag = false;
	int index = 31;
	while(index > -1)
	{
		if (flag)
			vec[index] = !vec[index];
		else if (vec[index] == 1)
			flag = true;
		index--;
	};
	return;
}

char doHexaConversion(vector<int> tmp)
{
	map<char, int> mapHexa;
	mapHexa[10] = 'a';
	mapHexa[11] = 'b';
	mapHexa[12] = 'c';
	mapHexa[13] = 'd';
	mapHexa[14] = 'e';
	mapHexa[15] = 'f';

	printvector(tmp);

	int num = 0;
	int multiply = 3;
	for (const auto& var : tmp)
	{	num = num + var*pow(2, multiply);
		multiply--;
	}

	if (num <= 9)
		return num + '0';
	else
		return mapHexa[num];
}


string convert2Hex(vector<bool>& vec)
{
	vector<int> tmpNum;
	string result;
	for (int j = 0; j < 8; j++)
	{
		int start = 4 * j;
		for (int i = start ; i < start + 4 ; i++)
			tmpNum.push_back(vec[i]);
		
		char ch = doHexaConversion(tmpNum);
		tmpNum.clear();
		result.push_back(ch);
	}
	return result;
}

void remLeadZeros(string& str)
{
	auto it = str.begin();
	while ( it != str.end() && (*it == '0'))
	{	it = str.erase(it);
	};
}

string toHex(int num) {
	
	if (num == 0)
		return to_string(0);

	bool sign = false;
	if (num < 0)
	{	sign = true;
	}
	
	unsigned int n = num;
	const int binNum = 2;
	vector<bool> vecBinary(32, false);
	int index = 31;
	while (n > 0)
	{
		int rem = n % binNum;
		n = n / binNum;
		vecBinary[index] =  rem;
		index--;
	};

for (const auto& var : vecBinary)
cout << var;
cout << endl;

	if (sign)
	{	towsComplement(vecBinary);
		towsComplement(vecBinary);
	}
	string result = convert2Hex(vecBinary);
	remLeadZeros(result);
	return result;
}

bool isBoomerang(vector<vector<int>>& points) {
	
	if (points.empty())
		return false;
	
	set<pair<int, int>> setPoints;
	int counter = 0;
	for (const auto& point : points)
	{
		auto myPair = make_pair(point[0], point[1]);
		setPoints.insert(myPair);	
	}
	
	if (setPoints.size() < 3)
		return false;

	vector<float> slope;
	int i = 0;
	int firstCord = 0;
	int secondCord = 0;
	for (const auto& point : setPoints)
	{
		if (i> 0) 
			 if (point.first != firstCord)
			 {
				float slope1 = (point.second - secondCord) / (1.0*(point.first - firstCord));
				slope.push_back(slope1);
			 }
			 else
				 counter++;

		firstCord = point.first;
		secondCord = point.second;
		i++;
	}

	if (counter > 1)
		return false;

	//check for 0, first coordinate
	if (slope.size() == 2)
		return (slope[0] != slope[1]);
	return true;
}


int oddCells(int n, int m, vector<vector<int>>& indices)
{	
	
	map<pair<int, int>, int> mapKeys;
	for (int i = 0; i < n; i++)
	{	for (int j = 0; j < m; j++)
			mapKeys[make_pair(i, j)] = 0;
	}

	//
	for (const auto& index : indices)
	{
		for (int i = 0; i < n; i++)
		{	
			for (int j = 0; j < m; j++)
			{
				pair<int, int> myPair = make_pair(i, j);
				//if (index[0] == i && index[1] == j)
					//mapKeys[myPair]++;
				
				if (i == index[0])
					mapKeys[myPair]++;
				else if (j == index[1])
					mapKeys[myPair]++;
			}
		}
	}

	//adjust for the indices
	for (const auto& index : indices)
	{
		pair<int, int> myPair = make_pair(index[0], index[1]);
		mapKeys[myPair]++;
	}

	int counter = 0;
	for (const auto& record : mapKeys)
	{
		if (record.second % 2 == 1)
			counter++;
	}
	return counter;
}

/*
TreeNode* increasingBST(TreeNode* root)
{
	
	if (root->left)
	{
		TreeNode *prev = increasingBST(root->left);
		{
			TreeNode *newTree = new TreeNode(root->val);
			prev->right = newTree;
			prev->left = NULL;
			root = newTree;
		}
	}
	if (root->right)
		increasingBST(root->right);

	return root;
}
*/

void doMaxDepth(Node* root, int counter, int& depth)
{
	for (const auto& child : root->children)
	{	if (child)
			doMaxDepth(child, counter + 1, depth);	
	}
	depth = max(depth, counter);
	counter--;
}

int maxDepth(Node* root)
{	
	if (!root)
		return 0;

	int counter = 1;
	int depth = 0;
	doMaxDepth(root, counter, depth);
	return depth;
}

int maxDepth(TreeNode* root) {

	int depth = 0;
	if (!root)
		return 0;

	if (root->left)
		depth = max(depth, maxDepth(root->left));

	if (root->right)
		depth = max(depth, maxDepth(root->right));

	cout << depth << endl;
	return 1 + depth;
}

int doDivisorGame(int N) 
{
	int x = 0;
	int player = 0;

	cout << N << endl;

	if (N <= 0)
		return 0;

	if (N % 2 == 0)
		x = 1;
	else
	{	//cout <<endl;
	}
	player = player + 1 + doDivisorGame(N - x);
	return player;
}


bool divisorGame(int N) {
		
	int player = doDivisorGame(N);
	cout << player << endl;
	bool result = true;
	return result;
}

int convert22Int(stack<int> nums)
{
	int result = 0;
	int i = 0; 
	while (!nums.empty())
	{
		result = result + nums.top() * pow(2, i);
		nums.pop();
		i = i + 1;
	}
	return result;
}

void doSumRootToLeaf(TreeNode* root, stack<int>& myStack, int& sum)
{
	
	myStack.push(root->val);
	if(root->left)
		doSumRootToLeaf(root->left, myStack, sum);
	
	if(root->right)
		doSumRootToLeaf(root->right, myStack, sum);

	if ((!root->left) && (!root->right))
	{
		int result = convert22Int(myStack);
		sum = sum + result;
	}



	myStack.pop();
}


int sumRootToLeaf(TreeNode* root) {

	if (!root)
		return 0;

	stack<int> nums;
	int sum = 0;
	doSumRootToLeaf(root, nums, sum);	
	return sum;
}

bool doHasPathSum(TreeNode* root, int sum, int result)
{
	bool flag = false;
	result = result + root->val;

	if (root->left)
	{	flag = doHasPathSum(root->left, sum, result);
		if (flag)
			return true;
	}

	if (root->right)
	{	flag = doHasPathSum(root->right, sum, result);
		if (flag)
			return true;
	}

	if (root->left == NULL and root->right == NULL)
	{	if (sum == result)
			return true;
		result = result - root->val;
	}
	return false;
}

bool hasPathSum(TreeNode* root, int sum) {

	if (!root)
		return false;
	int result = 0;
	return doHasPathSum(root, sum, result);
}

void doMinDepth(TreeNode* root, int local, int& depth)
{
	if (root->left)
		doMinDepth(root->left, local + 1, depth);

	if (root->right)
		doMinDepth(root->right, local + 1, depth);

	if ((!root->left) && (!root->right))
		depth = min(local, depth);
	
	return;
}

int minDepth(TreeNode* root) {

	if (!root)
		return 0;
	
	int depth = 1000;
	int local = 1;
	doMinDepth(root, local, depth);
	return depth;

}


int guess(int n)
{
	int setPoint = 3;
	if (n == setPoint)
		return 0;
	else if (n > setPoint)
		return -1;
	else
		return 1;
}

int doGuessNumber(int low, int high)
{
	int mid = (low + high) / 2;
	int result = guess(mid);
	int num = 0;
	
	if (result == 0)
		return mid;
	else if (result == -1)
		num = doGuessNumber(low, mid-1);
	else if (result == 1)
		num = doGuessNumber(mid+1, high);

	return num;
}


int guessNumber(int n) {

	int result = doGuessNumber(1, n);
	return result;
}

void convertStack2Vector(stack<int> myStack, vector<vector<int>>& result)
{
	vector<int> tmp;
	while (!myStack.empty())
	{
		tmp.push_back(myStack.top());
		myStack.pop();
	}
	reverse(tmp.begin(), tmp.end());
	result.push_back(tmp);
	tmp.clear();
	return;
}

void doBinaryTreePaths(TreeNode* root, stack<int>& myStack, vector<vector<int>>& result)
{
	myStack.push(root->val);
	if (root->left)
		doBinaryTreePaths(root->left, myStack, result);

	if (root->right)
		doBinaryTreePaths(root->right, myStack, result);

	if ((!root->left) && (!root->right))
	{	convertStack2Vector(myStack, result);
	}
	myStack.pop();
	return;
}

vector<string> binaryTreePaths(TreeNode* root) {
	
	vector<string> str;
	if (!root)
		return str;
	
	vector<vector<int>> result;
	stack<int> myStack;
	doBinaryTreePaths(root, myStack, result);
	for (const auto& elem : result)
	{
		string s;
		for (const auto& letter : elem)
		{
			s = s + to_string(letter);
			s = s + "->";
		}
		auto it = s.length()-2;
		s.erase(it, 2);
		str.push_back(s);
	}
	return str;
}

///Function Definitions
template<typename T>
void printvector(T& xs)
{
	for (const auto& elem : xs)
		cout << elem << " ";
	cout << endl;
}

template<typename T>
void print2Dvector(T& vec2D)
{
	for (const auto& row : vec2D)
	{
		for (const auto& column : row)
			cout << column << " ";
		cout << endl;
	}
}

