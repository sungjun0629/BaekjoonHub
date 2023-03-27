#include<iostream>
using namespace std;

int N, k, temp;
int a[100001];
int psum[100001] = { 0, };
int sum = -10000004;
int main() {

	cin >> N >> k;

	for (int i = 1; i <= N; i++)
	{
		cin >> temp; psum[i] = psum[i - 1] + temp;
	}

	for (int i = 1; i <= N - k + 1; i++) {
		sum = max(sum, psum[i + k - 1] - psum[i - 1]);
	}
	cout << sum;
}