#include<iostream>
#include<set>
using namespace std;


int N; string str; set<string> s;
int main()
{
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "ENTER")
		{// 초기화 
			s.clear();
		}
		else {
			if (s.find(str) != s.end())
			{
				continue;
			}
			else
			{
				cnt++; s.insert(str);
			}
		}

	}

	cout << cnt << endl;
}