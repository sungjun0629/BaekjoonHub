#include<iostream>
using namespace std;

int N, M, i ,j, temp;
int arr[103];
int main()
{
	cin >> N >> M;
	for (int e = 0; e < M; e++)
	{
		cin >> i >> j;
		if (arr[i-1] == 0 ) arr[i-1] = i;
		if (arr[j-1] == 0) arr[j-1] = j;

		temp = arr[i-1];
		arr[i-1] = arr[j-1];
		arr[j-1] = temp;

	}

	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 0) cout << i+1 <<" ";
		else cout << arr[i]<< " ";
	}
}