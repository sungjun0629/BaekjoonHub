#include<iostream>
using namespace std;

int N = 9; int maxn =1-1;
int cnt, n;
int main()
{
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		if (maxn < n)
		{
			maxn = n;
			cnt = i+1;
		}
	}

	cout << maxn << endl; cout << cnt << endl;
}