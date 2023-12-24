#include<iostream>
#include<vector>
using namespace std;

int N;
int n, k;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> k >> n;
		int rst = 1; 
		int fac = 1;
		for (int i = k + 1; i <= n; i++)
		{
			rst *= i;
			rst /= fac++;
		}

		cout << rst << '\n';
	}

}