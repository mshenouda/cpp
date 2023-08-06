// binary_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "linkList.h"
#include "MinStack.h"
#include "Tree.h"

using namespace std;

//function definitions here
int romanToInt(std::string);
bool isValid(std::string s);
bool isPalindrome(int);
list<int> mergeTwoLists(list<int>&, list<int>&);
int removeDuplicates(vector<int>& nums);
int removeElement(vector<int>&, int);
int strStr(std::string, std::string);
int searchInsert(vector<int>&, int);
std::string countAndSayRecursively(int);
std::string countAndSay(int);
int lengthOfLastWord(string s);
vector<int> plusOne(vector<int>& digits);
string addBinary(string a, string b); 
int climbStairs(int n);
int climbStairsRecursively(int);
int climbStairsIteratively(int n);
int towersOfHanoi(int, char, char, char);
std::string frequency(std::string);
int makeEqualLength(string &, string &);
ListNode* deleteDuplicates(ListNode*);
ListNode* mergeTwoLists(ListNode*, ListNode*);
int sqrt(int);
int reverse(int);
void merge(vector<int>&,int, vector<int>&, int);
bool isSameTree(ListNode*, ListNode*);
void training();
bool symmetricQueue(deque<int>&);
int maxSubArray(vector<int>&);
int singleNumber(vector<int>&);
bool hasCycle(ListNode *);
bool isPalindrome(string s);
void printListNode(ListNode*);
int maxProfit(vector<int>&);
int maxProfit2(vector<int>& prices);
vector<int> findErrorNums(vector<int>&);
vector<int> twoSum(vector<int>& numbers, int target);
void tryVector(void);
string convertToTitle(int n);
void rotate(vector<int>& nums, int k);
int majorityElement(vector<int>& nums);
int titleToNumber(string& s);
ListNode* removeElements(ListNode* head, int val);
bool isHappy(int n);

//namespace std
using namespace std;

//main function


	//build a tree
	/*
	cout << " Enter the max depth of the tree " << endl;
	int depth;
	cin>>depth;
	tree binTree;
	binTree.buildTree(2, depth);
	binTree.printTree();
	binTree.traverseTreeRecursiverly();
	*/

	/*
	int result = romanToInt("IX");
	cout << result << endl;
	*/

	/*
	std::vector<std::string> strs; 
	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("flight");
	string ans = longestCommonPrefix(strs);
	cout << "Longest match = " << ans << endl;
	*/ 
	
	/*
	string s = isValid("[(]){}") ? "True" : "False";
	cout<<s<<endl;
	*/ 
	
	/*
	string s=isPalindrome(21515)? "True":"False";
	cout<<s<< endl;
	*/

	/*
	list<int> l1{  1,100 };
	list<int> l2{ 4, 5, 90, 800 };
	l1 = mergeTwoLists(l1, l2);
	for (const auto& elem : l1)
		cout << elem << endl;
	*/

	/*
	vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	std::cout<<removeDuplicates(nums);
	*/

	/*
	vector<int> nums = { 3};
	std::cout<<endl<<removeElement(nums, 3);
	*/
	
	//cout << strStr("hello", "ll");
	/*
	vector<int> nums{ 1,3,5,6 };
	cout<<searchInsert(nums, 0)<<endl;
	*/
	
	/*
	string s = "a";
	cout<<lengthOfLastWord(s);
	*/
	/*
	vector<int> nums{0,0,9,9,9};
	plusOne(nums);
	*/

	/*
	string a{ "01"};
	string b{ "1" };
	cout << addBinary(a, b);
	*/

	/*
	cout << climbStairsIteratively(44);
	*/
	
	//cout<<countAndSay(6);
	//cout<<addBinary("1010", "1101");

	/*
	vector<int> nums{ 9, 9, 9};
	plusOne(nums);
	*/
	//cout<<endl<<"No. of steps " << towersOfHanoi(15, 'A', 'C', 'B') << endl;
	
	/*
	vector<int> nums{1,1,2,3, 3};
	vector<int>::iterator it = nums.begin();
	ListNode *prev = new ListNode(*it);
	ListNode *head = prev;
	for (it = it+1; it<nums.end(); it++)
	{
		ListNode *curr = new ListNode(*it);
		prev->next = curr;
		prev = curr;
	}
	head = deleteDuplicates(head);
	ListNode* curr = head;
	while (curr)
	{
		cout << curr->val << " ";
		curr = curr->next;
	};
	*/
	
	/*
	vector<int> l1{ 1,80};
	vector<int>::iterator it = l1.begin();
	ListNode *prev = new ListNode(*it);
	ListNode *headl1 = prev;
	for (it = it + 1; it < l1.end(); it++)
	{
		ListNode *curr = new ListNode(*it);
		prev->next = curr;
		prev = curr;
	}
	
	vector<int> l2{ 1,3,100 };
	it = l2.begin();
	prev = new ListNode(*it);
	ListNode *headl2 = prev;
	for (it = it + 1; it < l2.end(); it++)
	{
		ListNode *curr = new ListNode(*it);
		prev->next = curr;
		prev = curr;
	}
	
	headl1 = mergeTwoLists(headl1, headl2);
	*/
	
	/*
	int x = 35;
	int y = sqrt(x);
	cout << y << endl;
	*/
	
	/*
	int x = -2147483412;
	cout << reverse(x);
	*/

	/*
	vector<int> nums1{ 1,2,3,0,0,0};
	vector<int> nums2{ 2,5,6 };
	merge(nums1, 3, nums2, 3);
	*/
	

	
	/*
	ListNode *b = new ListNode(0);
	b->left = new ListNode(-8);
	b->right = new ListNode(1);
	cout<<isSameTree(a, b)?"True\n":"False\n";
	*/
	
	//Training function to try lambda and function pointers
	//training();

	/*
	deque<int> dummyQueue{ 4,3,2,1,2,3,4 };
	cout << (symmetricQueue(dummyQueue)?"True\n" : "False\n");
	*/
	
	/*
	vector<int> nums{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout<<"The maximum is = "<<maxSubArray(nums);
	*/

	/*
	vector<int> nums{ 2,2,1 };
	cout<<"single Number = "<<singleNumber(nums);
	*/
	
	/*
	ListNode *head;
	vector<int> nums{ 3, 2, 0, -4};
	vector<int>::iterator it = nums.begin();
	ListNode *prev = new ListNode(*it);
	ListNode *head = prev;
	for (it = it + 1; it < nums.end(); it++)
	{


		ListNode *curr = new ListNode(*it);
		prev->next = curr;
		prev = curr;
	}
	cout << (hasCycle(head) ? "True\n" : "False\n");
	*/

	/*
	string s = "A man, a plan, a canal: Panama";
	cout<< (isPalindrome(s) ? "True\n" : "False\n");
	*/
	
	/*
	//Build list A
	vector<int> numsA{ 0,1,4,8,5 };
	linkList A, B;
	ListNode* headA = A.buildList(numsA);
	A.printList();

	
	/*
	vector<int> numsA{7,1,5,3,6,4};
	maxProfit(numsA);
	*/

	/*
	vector<int> nums{ 5,3,6,1,5,4,7,8 };
	vector<int> result = findErrorNums(nums);
	for (const auto& elem : result)
		cout << elem << " ";
	*/
	/*
	vector<int> nums{ 3,2,6,5,0,3 };
	cout<<endl<<maxProfit(nums);
	*/

	/*
	vector<int> nums{ 2,1,1,2};
	cout << endl << maxProfit2(nums);
	*/
	
	/*
	vector<int> nums{1,5,7,10};
	vector<int> result = twoSum(nums, 15);
	*/

	//cout << convertToTitle(703);
	
	/*
	vector<int> numbers{ 1,2 };
	rotate(numbers, 1);
	*/
	
	/*
	vector<int> nums{ 3,2,3 };
	cout<<" majority element "<<majorityElement(nums);
	*/
	
	/*
	string s = "ZY";
	cout<<" value "<<titleToNumber(s)<<endl;
	*/

	/*
	vector<int> numsA{ 2,2,2,2,4,5,2 };
	linkList A;
	ListNode* headA = A.buildList(numsA);
	A.printList();	
	removeElements(headA, 2);
	*/

	/*
	vector<int> nums{114,117,207,117,235,82,90,67,143,146,53};
	cout<<" rob = "<<rob(nums);
	*/
		
	//cout <<" is happy = "<<isHappy(52);
	
	/*
	tryVector();
	*/


		

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

int romanToInt(string s)
{
	int result = 0;
	bool flag1 = false; 
	bool flag10 = false;
	bool flag100 = false;
	
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == 'M')
		{
			flag100 = true;
			result += 1000;
		}
		else if (s[i] == 'D')
		{
			flag100 = true;
			result += 500;
		}
		else if (s[i] == 'C')
		{
			flag10 = true;
			if (flag100)
			{
				flag100 = false;
				result -= 100;
			}
			else
				result += 100;
		}
		else if (s[i] == 'L')
		{
			flag10 = true;
			result += 50;
		}
		else if (s[i] == 'X')
		{
			flag1 = true;
			if (flag10)
			{
				flag10 = false;
				result -= 10;
			}
			else
				result += 10;
		}
		else if (s[i] == 'V')
		{
			result += 5;
			flag1 = true;
		}
		else if (s[i] == 'I')
		{
			if (flag1)
			{	flag1 = false;
				result--;
			}
			else
				result++;
		}
	}
	return result;
};


std::string commonPrefixUtil(std::string str1, std::string str2)
{
	std::string result;
	int n1 = str1.length(), n2 = str2.length();

	// Compare str1 and str2 
	for (int i=0, j=0; i<=n1-1 && j<=n2-1; i++, j++)
	{
		if (str1[i] != str2[j])
			break;
		result.push_back(str1[i]);
	}
	return (result);
}

std::string commonPrefix(vector<string>& strs)
{
	string prefix = strs[0];
	for (int i = 0; i < strs.size(); i++)
		prefix = commonPrefixUtil(prefix, strs[i]);
	return (prefix);
}

bool isValid(std::string str)
{
	if (str == "")
		return true;
	else
	{
		std::stack<char> s;
		for (const auto& ch : str)
		{
			if (s.empty())
				s.push(ch);
			else 
			{	
				string tmp = "";
				tmp+=s.top();
				tmp+=ch;
				if (tmp.compare("[]") == 0 || tmp.compare("()") == 0 || tmp.compare("{}") == 0)
					s.pop();
				else
					s.push(ch);
			}
		}

		if (s.empty())
			return true;
		return false;
	}
}

bool isPalindrome(int x)
{

	std::string s = std::to_string(x);
	int j = s.size()-1;
	for (int i=0;i<j;i++)
	{
		if (s[i] != s[j])
			return false;
		j--;
	}
	return true;
}


std::list<int> mergeTwoLists(list<int>& l1, list<int>& l2)
{
	list<int>::iterator it1 = l1.begin();
	list<int>::iterator it2 = l2.begin();
	list<int> result;

	if (l1.empty())
		return l2;
	
	if (l2.empty())
		return l1;

	if (result.empty())
		result.push_back(-1000);


	while ((it1 != l1.end()) && (it2 != l2.end()))
	{
		if (l1.front() >= result.back())
		{
			result.push_back(l1.front());
			it1 = l1.erase(it1);
		}
		else if (l2.front() >= result.back())
		{
			result.push_back(l2.front());
			it2 = l2.erase(it2);
		}
	};

	result.erase(result.begin());
	if (l1.empty())
	{
		result.merge(l2);
		return result;
	} else if (l2.empty())
	{
		result.merge(l1);
		return result;
	}

	return result;	
}


int removeDuplicates(vector<int>& nums) {

	vector<int>::iterator it = nums.begin();
	vector<int>::iterator it2;

	while (it != nums.end())
	{
		it2 = it + 1;
		while (it2 != nums.end() && (*it == *it2))
		{it2 = nums.erase(it2);
		};
		it++;
	};

	for (const auto& elem : nums)
	{cout << elem << " ";}
	return nums.size();
}


int removeElement(vector<int>& nums, int val) {

	vector<int>::iterator it = nums.begin();
	while (it != nums.end())
	{
		if (val == *it)
			it = nums.erase(it);
		else
			it++;
	}
	return nums.size();
}

int strStr(string haystack, string needle) 
{

	if (needle == "")
		return 0;

	std::size_t found = haystack.find(needle);
	if (found != std::string::npos)
		return found;
	else
		return -1;
}

int searchInsert(vector<int>& nums, int target) {

	if (target > nums.back())
		return nums.size();
	else
	{
		for (vector<int>::iterator it = nums.begin(); it<nums.end(); it++)
		{	
			if (*it > target)
				it = nums.insert(it, target);
			
			if (*it == target)
				return distance(nums.begin(), it);
		}
		return -1;
	}
}

std::string frequency(std::string source)
{
	std::string::iterator it = source.begin();
	string result = "";
	char code = source[0];
	
	vector<pair<char, int>> codesToFrequency;
	while (it<source.end())
	{
		int counter = 0;
		while (it<source.end() && *it == code)
		{	counter++;
			it++;
		};
		codesToFrequency.push_back(make_pair(code, counter));
		if (it != source.end())
			code = *it;
	};
	for (const auto& freq : codesToFrequency)
	{
		result.push_back('0' + freq.second);
		result.push_back(freq.first);
	}
	return result;
}
std::string countAndSay(int n) {

	//too specific case 
	if ((n < 1) || (n > 30))
		return "";

	string words[31];
	words[0] = "";
	words[1] = "1";
	words[2] = "11";
	words[3] = "21";
	words[4] = "1211";
	words[5] = "111221";
	words[6] = "312211";

	
	if (n >= 1 && n<=6)
		return words[n];

	for (int i=7; i <= n; i++)
	{	string tmp = words[i-1];
		words[i] = frequency(tmp);
	}
	//last word only
	return words[n];
}
std::string countAndSayRecursively(int n) {

	string pattern;

	if (n >= 30)
		return "";
	else if (n == 1)
		 pattern = "1";
	else
	{
		pattern = countAndSayRecursively(n - 1);
		pattern = frequency(pattern);
	}
	return pattern;
}

int lengthOfLastWord(string s) {

	if (s.length() == 1)
	{	if (s[0] == ' ')
			return 0;
		return 1;
	}

	//last element
	int i = s.length() - 1;
	int startLastWord = i;
	//word should be beginner than 1 letter;
	while (i > 0)
	{
		//eat leading white spaces
		while ((i>0) && (s[i]==' '))
		{	i--;
		};
		
		//leading white spaces
		if (i < startLastWord)
			startLastWord = i;

		//start of the last word
		while ((i>0) && (s[i] != ' '))
		{	i--;
		};

		//Words before 
		if (s[i] == ' ')
			return (startLastWord - i);
		else // lastword = firstword
			return (startLastWord - i)+1;

	};
	return 0;
}

string findSum(string str1, string str2)
{
	// Before proceeding further, make sure length 
	// of str2 is larger. 
	if (str1.length() > str2.length())
		swap(str1, str2);

	// Take an empty string for storing result 
	string str = "";

	// Calculate length of both string 
	int n1 = str1.length(), n2 = str2.length();

	// Reverse both of strings 
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i = 0; i < n1; i++)
	{
		// Do school mathematics, compute sum of 
		// current digits and carry 
		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');

		// Calculate carry for next step 
		carry = sum / 10;
	}

	// Add remaining digits of larger number 
	for (int i = n1; i < n2; i++)
	{
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	// Add remaining carry 
	if (carry)
		str.push_back(carry + '0');

	// reverse resultant string 
	reverse(str.begin(), str.end());

	return str;
}




vector<int> plusOne(vector<int>& digits) {

	string a;
	string b = "1";
	for (const auto& var : digits)
		a.push_back('0' + var);
	a = findSum(a, b);
	digits.clear();
	for (const auto& var : a)
	{digits.push_back(var-'0');}

	return digits;
}
int makeEqualLength(string &str1, string &str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 < len2)
	{
		for (int i = 0; i < len2 - len1; i++)
			str1 = '0' + str1;
		return len2;
	}
	else if (len1 > len2)
	{
		for (int i = 0; i < len1 - len2; i++)
			str2 = '0' + str2;
	}
	return len1; // If len1 >= len2 
}


string addBinary(string a, string b) {
	string result;  // To store the sum bits 

	// make the lengths same before adding 
	int length = makeEqualLength(a, b);

	int carry = 0;  // Initialize carry 

	// Add all bits one by one 
	for (int i = length - 1; i >= 0; i--)
	{
		int firstBit = a.at(i) - '0';
		int secondBit = b.at(i) - '0';

		// boolean expression for sum of 3 bits 
		int sum = (firstBit ^ secondBit ^ carry) + '0';

		result = (char)sum + result;

		// boolean expression for 3-bit addition 
		carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
	}

	// if overflow, then add a leading 1 
	if (carry)
		result = '1' + result;

	return result;
}

int climbStairs(int n) {
	
	static bool enterOnce = false;
	int result = 0; 

	if (!enterOnce)
	{	enterOnce = true;
		if (n <= 1)
			return n;
	}
	
	if (n == 0)
		return 1;

	if (n >= 2)
		result = result + climbStairs(n - 2);
	
	if (n>= 1)
		result = result + climbStairs(n - 1);

	return result;
}


int climbStairsRecursively(int n) {

	if ((n == 0) || (n == 1))
		return  1;
	else if (n == 3)
		return 3;
	else if (n == 4)
		return 5;
	else
		return climbStairsRecursively(n - 1) + climbStairsRecursively(n - 2);
}

int climbStairsIteratively(int n) {
	
	vector<int> table;
	table.push_back(1);
	table.push_back(1);
	table.push_back(2);
	table.push_back(3);
	for (int i = 4; i <= n; i++)
	{	table.push_back(table[i - 1] + table[i - 2]);
	}
	return table.back();
}

int towersOfHanoi(int n, char from, char to, char aux)
{
	int counter = 0;
	if (n == 1)
	{	//cout << "Move disk "<<n<<" from " <<from<<" to "<<to<<endl;
		return 1;
	}
	else
	{
		counter+= towersOfHanoi(n - 1, from, aux, to);
		//cout << "Move disk " << n << " from " << from << " to " << to << endl;
		counter+= towersOfHanoi(n - 1, aux, to, from);
	}
	return ++counter;
}

ListNode* deleteDuplicates(ListNode* head) {

	ListNode *prev = head;
	while (prev != NULL)
	{
		int val = prev->val;
		ListNode *curr = prev->next;
		while ((curr!=NULL)&&(val == curr->val))
		{
			prev->next = curr->next;
			delete curr;
			curr = prev->next;
		};
		prev = curr;
	};
	return head;
}

ListNode* insertListNode(ListNode* prev)
{
	ListNode *curr = new ListNode(prev->val);
	return curr;
}

ListNode* deleteListNode(ListNode* prev)
{
	ListNode *curr = prev->next;
	prev->next = NULL;
	delete prev;
	return curr;
}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;

	ListNode *prevl1 = l1;
	ListNode *prevl2 = l2;
	ListNode *result= NULL;

	if (prevl1->val < prevl2->val)
	{	result = new ListNode(prevl1->val);
		prevl1 = deleteListNode(prevl1);
	}
	else if (prevl1->val >= prevl2->val)
	{	result = new ListNode(prevl2->val);
		prevl2 = deleteListNode(prevl2);
	}
	
	ListNode *head = result;

	while (prevl1 && prevl2)
	{
		if (prevl1->val < prevl2->val)
		{ 	result->next = insertListNode(prevl1);
			prevl1 = deleteListNode(prevl1);
			result = result->next;
		}
		else if (prevl1->val > prevl2->val)
		{
			result->next = insertListNode(prevl2);
			prevl2 = deleteListNode(prevl2);
			result = result->next;
		}
		else if (prevl1->val == prevl2->val)
		{
			result->next = insertListNode(prevl1);
			result = result->next;
			result->next = insertListNode(prevl2);
			result = result->next;
			prevl1 = deleteListNode(prevl1);
			prevl2 = deleteListNode(prevl2);
		}	
	};

	//If L1 empty and L2 still 
	if (!prevl1 && prevl2)
	{	result->next = prevl2;
	} else if (prevl1 && !prevl2)
	{	result->next = prevl1;
	}

	result = head;
	while(result)
	{ 
		cout << result->val<<" ";
		result = result->next;
	};
	return head;
}

//Square function
int sqrt(int x)
{
	int i = 0;
	while(pow(i, 2)<x && i<10000000)
	{	i++;
	};

	if(pow(i,2)==x)
		return i;
	return --i;
}



void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {


	if (m == 0 || n == 0)
		return;

	vector<int> result;
	vector<int>::iterator it1 = nums1.begin();
	vector<int>::iterator it2 = nums2.begin();
		
	while (m>0 && n>0)
	{
		if (nums1.front() <= nums2.front())
		{	result.push_back(nums1.front());
			it1 = nums1.erase(it1);
			m--;
		} else if (nums1.front() >= nums2.front())
		{	result.push_back(nums2.front());
			it2 = nums2.erase(it2);
			n--;
		}
	};
	
	//merge first
	while (n == 0 && m > 0)
	{	result.push_back(nums1.front());
		it1 = nums1.erase(it1);
		m--;
	};
	   
	//merge second
	while (m == 0 && n > 0)
	{	result.push_back(nums2.front());
		it2 = nums2.erase(it2);
		n--;
	};

	nums1.clear();
	nums1 = result;
	for (int i = 0; i < nums1.size(); i++)
	{	cout << nums1[i];
		if (i < nums1.size() - 1)
			cout << ",";
	}
}

bool isSameTree(TreeNode* p, TreeNode* q) {
	
	bool result = true;
	if (!p && !q)
		return result;
	else if ((p && !q) || (q && !p))
		result = false;
	else if (p->val != q->val)
		result = false;
	else if (p->val == q->val)
	{
		cout << p->val << " " << q->val << endl;
		result = result & isSameTree(p->left, q->left);
		if(result)
			result = result & isSameTree(p->right, q->right);
	}
	return result;
}

//Do Nothing function
void doNothing(int i)
{	std::cout<<i<<" ";
}

//Training function 
void training()
{
	vector<int> nums{ 1,2,3,4,5};
	auto print = [](const auto& i) {cout << i<<" "; };
	
	
	void(*funcPtr)(int) = NULL;
	funcPtr = doNothing;
	
	//print vector using print lambda
	std::for_each(nums.begin(), nums.end(), print);
	std::cout << endl << "Function pointer " << endl;
	//print vector using function ptr doNothing
	for(const auto& i : nums)
		(*funcPtr)(i);
	std::cout<<"End of the function " << endl;
}

bool symmetricQueue(deque<int>& dummyQueue)
{
	if (dummyQueue.empty())
		return true;

	bool result = false;
	while (!dummyQueue.empty())
	{
		result = dummyQueue.front() == dummyQueue.back();
		if (result)
		{
			std::cout << dummyQueue.front() << " ";
			if (dummyQueue.size() > 1)
			{	dummyQueue.pop_front();
				dummyQueue.pop_back();
			} else if (dummyQueue.size() == 1)
				dummyQueue.pop_front();
		} else
			break;
	};
	return result;
}


//Maximal subarray vector of integers
int maxSubArray(vector<int>& nums) {

	if (nums.size() == 1)
		return nums[0];
	return 0;
}
//Single number function
int singleNumber(vector<int>& nums) {
	
	if (nums.empty())
		return 0;
	else if (nums.size() == 1)
		return nums[0];

	vector<int>::iterator first = nums.begin();
	vector<int>::iterator last = nums.end();
	vector<int>::iterator second = first + 1;	
	sort(first, last);
	
	while(first<last && second<last && (*first == *second))
	{	
		first+=2;
		second += 2;
	};
	return *first;
}

bool hasCycle(ListNode *head) {
	return false;
}

bool isPalindrome(string s) {

	if (s == "")
		return true;

	int i = 0;
	int l = s.length() - 1;
	bool result = true;
	while (i<l)
	{
		if (!isalnum(s[i]))
		{   i++;
			continue;
		}

		if (!isalnum(s[l]))
		{	l--;
			continue;
		}

		if (std::tolower(s[i]) != std::tolower(s[l]))
			return false;
		
		i++;
		l--;
	};

	return result;
}



void printListNode(ListNode* head)
{
	if (head == NULL)
	{
		cout << " Head is NULL, can't print " << endl;
		return;
	} 
	while (head != NULL)
	{	cout<<head->val<<" ";
		head = head->next;
	};
	return;
}


//Greater predicate
bool greater(int a, int b)
{	return a > b;}

int maxProfit(vector<int>& prices) {

	if (prices.empty() || prices.size() == 1)
		return 0;


	int max = 0;
	for (int i = prices.size()-1; i>=0; i--)
		for (int j=i-1; j>=0; j--)
		{
			if ((prices[i]- prices[j]) > max)
				max = prices[i] - prices[j];
				
		}
	return max;
}

vector<int> findErrorNums(vector<int>& nums) {

	if (nums.empty() || nums.size() == 1)
		return nums;

	vector<int>::iterator first = nums.begin();
	vector<int>::iterator last = nums.end();
	vector<int>::iterator second = first + 1;
	sort(first, last);
	int size = nums.size();
	while ((first < last) && (second < last) && (*first != *second))
	{	first++;
		second++;
	};
	int repeat = *first;
	first = nums.erase(first);
	std::set<int> mySet (nums.begin(), nums.end());

	int missing = 0;
	for (int i = 1; i <= size; i++)
	{	auto it = mySet.find(i);
		if (it == mySet.end())
			missing = i;
	}

	vector<int> result;
	result.push_back(repeat);
	result.push_back(missing);
	return result;
}

void tryVector(void)
{
		
	//initalizer list
	vector<int> v = { 1,2,3,4,5,6 };
	vector<int> n;
	n.assign(5, 42);
	vector<int>::iterator it = n.end();
	n.emplace(it, 56);
	it = n.begin();
	it += 3;
	n.insert(it, 88);
	n.emplace_back(89);
	n.reserve(16);
	n.swap(v);
	n.resize(8);
	cout << n.capacity()<<" "<<n.size() << endl;
	cout << " max size " << n.max_size() << endl;
	n.pop_back();

	std::cout << *(n.data()) << endl;
	for (const auto& var : n)
		cout << var << " ";
	cout << endl;

	cout << "Details " << n.back() << " " << n.front() << endl;
}

int maxProfit2(vector<int>& prices) {

	if (prices.empty() || prices.size() == 1)
		return 0;

	int max = 0;
	vector<int>::iterator first = prices.begin();
	vector<int>::iterator second = first + 1;
	vector<int>::iterator prev = second;

	while (first != prices.end())
	{
		second = first + 1;
		if (second == prices.end())
			break;

		if  ((second != (prev-1)) && (*second - *first) > 0)  
		{	
			prev = second;
			max+= *second - *first;
		}
		first++;
	};
	return max;
}

struct uniqueNumber
{	int counter = 0;
	

} func;

vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int> result;
	if (numbers.empty() || numbers.size() == 1)
		return result;
	
	for (int i= 0; i<numbers.size()-1; i++)
	{
		for (int j = i+1; j < numbers.size(); j++)
		{
			if (numbers[i] == numbers[j])
			{
				if (target == (numbers[i] + numbers[j]))
				{
					result.push_back(i + 1);
					result.push_back(j + 1);
					return result;
				}
				else while ((j < numbers.size()) && (numbers[i] == numbers[j]))
				{	j++;};
				//assign i
				i = j - 1;
			}
			
			if (target == (numbers[i] + numbers[j]))
			{
				result.push_back(i + 1);
				result.push_back(j + 1);
				return result;
			}
		}
	}
	return result;
}

char returnChar(int n)
{	return (char)('A' + n);
};

forward_list<int> convertToBinary(int radix, int n)
{
	forward_list<int> result;
	while (n > 0)
	{	int rem = n % radix;
		if (rem == 0)
		{	rem = 26;
			n--;
		}
		n = n / radix;
		result.push_front(rem);
	};
	return result;
} 

string convertToTitle(int n) {

	string str = "";
	const int radix = 26;
	//auto findChar = [](int n)->char{return (char)('A' + n-1);};
	
	if (n == 0)
		return "";
	
	map<int, char> mapToChar;
	for (int i = 0; i < radix; i++)
		mapToChar[i + 1] = (char)('A' + i);

	if (n <= radix)
	{	str = mapToChar[n];
		return str;
	}

	//convert to binary using radix 26
	forward_list<int> result = convertToBinary(radix, n);
	for (const auto& elem : result)
	{	str = str + mapToChar[elem];}
	return str;
}

void rotate(vector<int>& nums, int k) {


	if (nums.empty() || nums.size() == 1)
		return;
	else if (k <=0 )
		return;

	vector<int>::iterator first = nums.begin();
	vector<int>::iterator last = nums.end()-1;
	int size = nums.size();
	for (int i = 0; i < k; i++)
	{
		int tmp = *last;
		last = nums.erase(last);
		first = nums.insert(nums.begin(), tmp);
		last = nums.end() - 1;
	}
	nums.resize(size);

	for (const auto& elem : nums)
		cout << elem;
}

int majorityElement(vector<int>& nums) {

	if (nums.empty() || nums.size() == 1)
		return nums.size();

	vector<int>::iterator first = nums.begin();
	vector<int>::iterator last  = nums.end();
	int size = nums.size();
	int majority = 0;
	set<int> unique;
	
	for (const auto elem : nums)
		unique.emplace(elem);

	for (const auto elem : unique)
	{	int majority = std::count(first, last, elem);
		if (majority > (int)floor(size / 2))
			return elem;
	}
	return 0;
}

int titleToNumber(string& s) {

	string str = "";
	const int radix = 26;

	if (s== "")
		return 0;

	map<char, int> charToNum;
	for (int i = 0; i < radix; i++)
		charToNum[(char)('A' + i)] = i+1;

	int result = 0;
	int counter = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		//cout << s[i] << " ";
		result += charToNum[s[i]]*pow(radix, counter);
		++counter;
	}
	return result;
}

ListNode* removeElements(ListNode* head, int val) {

	ListNode* curr = head;
	ListNode* prev = NULL;

	while (curr)
	{
		if ((curr == head) && (curr->val == val)) 
		{	prev = curr;
			curr = curr->next;
			head = curr;
			prev->next = NULL;
			delete prev;
		}
		else if ((curr->val == val))
		{
			prev->next = curr->next;
			curr->next = NULL;
			delete curr;
			curr = prev->next;
		}
		else 
		{	prev = curr;
			curr = curr->next;
		}
	};
	return head;
}

vector<int> getDigits(int n)
{
	const int radix = 10;
	vector<int> result;
	while (n > 0)
	{
		int rem = n % radix;
		result.push_back(rem);
		n = n / radix;
	};
	return result;
}

int pow2(vector<int>& digits)
{
	int result = 0;
	for (const auto i : digits)
		result += (int)pow(i, 2);
	return result;
}

bool checkNumber(int n)
{
	const int radix = 10;
	if (n < radix)
		return false;
	return true;
}

bool isHappy(int n) {
	
	int result;
	int counter = 0;

	while (n != 1 && counter <= 10)
	{	
		vector<int> digits = getDigits(n);
		result = pow2(digits);
		n = result;
		cout << " result = " << result << endl;
		digits.clear();
		++counter;
	}; 

	return (result == 1);
}
