#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<deque>
#include<vector>
using namespace std;
bool isValid(string str) {
	stack<char>st;
	map<char, char>mp;
	mp['('] = ')';
	mp['{'] = '}';
	mp['['] = ']';
	for (int i = 0;i < str.size();i++) {
		char c = str[i];
		if (c == '(' || c == '{' || c == '[')
			st.push(c);
		else if (!st.empty() && mp[st.top()] == c)
			st.pop();
		else
			return false;
		return st.empty();
	}
}
string reverse_subwords(string line) {
	stack<char>st;
	//deque<char>dq ;
	string r = "";
	for (int i = 0;i < line.size();i++) {
		if (line[i] != ' ')
			st.push(line[i]);
		else {
			while (!st.empty()) {
				//dq.push_front(line[i]);
				r += st.top();
				st.pop();
			}
		}
	}
	return r;
}
int reverse_num(int num) {
	stack<char>st;
	string numtostr = to_string(num);
	for (int i = 0;i < numtostr.length();i++) {
		st.push(numtostr[i]);
	}
	int reversed = 0;
	int multiplier = 1;
	while (!st.empty()) {
		reversed += (st.top() - '0') * multiplier;
		st.pop();
		multiplier *= 10;
	}
	return reversed;
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
int scoreOfParentheses(string s) {
	stack<char>st;
	map<char, char>mp;
	mp['('] = ')';
	mp['{'] = '}';
	mp['['] = ']';
	int score = 0;
	for (int i = 0;i < s.size();i++) {
		char c = s[i];
		if (c == '(' || c == '{' || c == '[')
			st.push(c);
		else if (!st.empty() && mp[st.top()] == c) {
			st.pop();
			score += 1;
		}			
		else
			return -1;
	}
	return score;
}
int main()
{
}
