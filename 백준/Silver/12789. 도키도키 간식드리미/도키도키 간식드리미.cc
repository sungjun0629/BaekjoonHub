#include<iostream>
using namespace std;


int N, tmp;
int main()
{
	cin >> N;
	int top = N + 1;
	int cnt = 1;
	for (int i = 0; i < N-1; i++)
	{
		cin >> tmp;
		if (tmp == cnt)
		{
			cnt++; continue;
		}

		// 작은 수가 밑에 들어가면 순서대로 받을 수 없다.
		else if (tmp > top)
		{
			// 순서가 맞다면면 통과
			if (tmp == cnt) continue;
			if (top == cnt) continue;
			cout << "Sad" << endl;
			return 0;
		}

		top = tmp;

	}

	cout << "Nice" << endl;
}