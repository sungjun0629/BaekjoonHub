#include<iostream>
#include<deque>
using namespace std;


int N, cmd; deque<int> dq;
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;

		if (cmd == 1)
		{
			cin >> cmd;
			dq.push_front(cmd);
		}
		else if (cmd == 2)
		{
			cin >> cmd;
			dq.push_back(cmd);
		}
		else if (cmd == 3)
		{
			if (dq.empty()) cout << "-1" << '\n';
			else {
				cout << dq.front() << '\n'; dq.pop_front();
			}
		}
		else if (cmd == 4)
		{
			if (dq.empty()) cout << "-1" << '\n';
			else
			{
				cout << dq.back() << "\n"; dq.pop_back();
			}
		}
		else if (cmd == 5)
		{
			cout << dq.size() << '\n';
		}
		else if (cmd == 6)
		{
			cout << dq.empty() << '\n';
		}
		else if (cmd == 7)
		{
			if (dq.empty()) cout << "-1" << '\n';
			else cout << dq.front() << '\n';
		}
		else if (cmd == 8)
		{
			if (dq.empty()) cout << "-1" << '\n';
			else cout << dq.back() << '\n';
		}
	}

	return 0;
}