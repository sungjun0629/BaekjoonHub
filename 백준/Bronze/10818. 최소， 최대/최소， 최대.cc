#include<iostream>
using namespace std;


int N, n, minn = 1000001, maxn = -2000000;
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> n;

		if (minn > n) minn = n;
		if (maxn < n) maxn = n;
	}

	cout << minn << " " << maxn;
}