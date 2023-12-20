#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<stack>
using namespace std;
#pragma warning(disable:4996)


string check(char s[])
{
	string rst;
	stack<char> stk;
	for (int i = 0; i < 100; i++)
	{
		if (s[i] == '.')
		{
			if (stk.empty()) rst = "yes";
			else rst = "no";
			return rst;
		}

		if(s[i] == ')')
		{
			if (!stk.empty() && stk.top() == '(') stk.pop(); 
			else {
				rst = "no"; return rst;
			}
		}
		else if (s[i] == ']')
		{
			if (!stk.empty() && stk.top() == '[') stk.pop();
			else {
				rst = "no"; return rst;
			}
		}
		else if (s[i] == '(' || s[i]== '[')
		{
			stk.push(s[i]);
		}
		
	}

	return rst;
}



int main()
{
	// 띄어쓰기도 같이 입력 받기 
	char s[104];
	cin.getline(s, 104, '\n');
	string str;

	while(true)
	{
		if (s[0] == '.') {
			break;
		}
		else
		{
			str = check(s);
			cout << str << endl;
			cin.getline(s, 104, '\n');
		}
	}
	return 0;
}