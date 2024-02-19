#include<iostream>

using namespace std;

int n, m; int arr[1030][1030];
int psum[1030][1030];
int x1, y11, x2, y2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	// 2차원 배열의 구간합은
	// 1차원 배열의 확장이므로 

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			psum[i][j] = psum[i][j-1] + arr[i][j];
		}
	}

	for (int t = 0; t < m; t++)
	{
		cin >> y11 >> x1 >> y2 >> x2;
		int sum = 0;
		for (int i = y11; i <= y2; i++)
		{
			sum += psum[i][x2] - psum[i][x1 - 1];
		}

		cout << sum << '\n';
	}
}