#include <iostream>
#include <stack>
using namespace std;


int N; string str;
int main()
{
	cin>>N;
	for (int i = 0; i < N; i++)
	{
		stack<char> stk;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (!stk.empty())
			{
				if (str[j] == '(')
				{
					stk.push(str[j]);
				}
				if (str[j] == ')')
				{
					if (stk.top() == '(') stk.pop();
					else stk.push(str[j]);
				}
			}
			else
			{
				stk.push(str[j]);
			}
		}

		//cout<<stk.size()<<'\n';
			if(!stk.empty()) cout<<"NO"<<'\n';
			else cout<<"YES"<<"\n";
	}

}