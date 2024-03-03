#include <iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

bool valid(string s) {
	stack<char>st;
	for (int i = 0;i < s.size();i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			st.push(s[i]);
		else {
			if (st.empty())
				return false;
			if (s[i] == ')' || s[i] == '}' || s[i] == ']')
			if(!st.empty())
			{
				char top = st.top();
				if ((s[i] == ')' && top != '(') ||
					(s[i] == '}' && top != '{') ||
					(s[i] == ']' && top != '[')) {
					return false;
				}
				st.pop();
			}			
		}
	}
	return st.empty();
}
bool containsDuplicate(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	for (int i = 1;i < nums.size();i++) {		
		if (nums[i] == nums[i-1])
			return true;		
	}
	return false;
}
string removeDuplicates(string s) {
	stack<char>st;
	for (int i = 0;i < s.size();i++) {
		if (st.empty())
			st.push(s[i]);
		if (s[i] != st.top())
			st.push(s[i]);
		else
			st.pop();
	}
	string result = "";
	while (!st.empty()) {
		result = st.top() + result;
		st.pop();
	}
	return result;
}
string removeDuplicates(string s) {
	string str;
	for (int i = 0;i < s.size();i++) {
		if (!str.empty()) {
			if (str.back() == s[i])
				str.pop_back();			
		}
		else
			str.push_back(s[i]);
	}
	return str;
}
int strStr(string haystack, string needle) {
	int theindex = haystack.find_first_of(needle);
	return 0;
}
int main()
{
	string s = "shahd ibrahim";
	cout << s.find_first_of("a");
	cout << "\n";
	string haystack = "leetcode";
	string needle = "leeto";
	int theindex = haystack.find(needle);
	cout << theindex;
	return 0;
}
