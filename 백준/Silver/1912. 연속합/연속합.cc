#include<iostream>
#include<cmath>

using namespace std;

int n; 
int arr[100100];
int psum[100100];
int so_far_min = 987654321; int ret;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}

	// 연속된 몇 개의 수를 선택해서
	// 가장 큰 합을 구한다. 

	// 구간 합 
	// 10 -4 3 1 5 6 -35 12 21 -1 
	// 10 6 9 10 15 21 -14 -2 19 18
	// 구간 합을 순회하며 원소와 제일 작은 수를 빼준 값의 크기가 
	// 제일 큰 수를 저장한다. -> O(n)
	for (int i = 0; i <= n; i++)
	{
		// 현재 원소와 제일 작은 수를 빼준 값과
		// 제일 큰 변수를 비교하여 큰 수를 대입한다.
		if (i == 1) ret = psum[1];
		else ret = max(ret, psum[i] - so_far_min);

		// 현재 원소를 포함하여 제일 작은 값을 넣어준다.
		so_far_min = min(so_far_min, psum[i]);
	}

	// -1 -3 -6 -10 -15
	//  100 -200 

	cout << ret;
}