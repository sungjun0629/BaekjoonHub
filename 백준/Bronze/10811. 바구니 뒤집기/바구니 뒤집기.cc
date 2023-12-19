#include<iostream>
using namespace std;

int arr[103], N, M;
int i, j;

void reverse(int begin, int end, int arr[])
{
	int n = (end - begin + 1)/2;
	int k = 0;
	while (n--> 0)
	{
		swap(arr[begin + k -1], arr[end - k - 1]);
		k++;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) arr[i] = i+1;
	for (int e = 0; e < M; e++)
	{
		cin >> i >> j;
		reverse(i, j, arr);
	}

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
}