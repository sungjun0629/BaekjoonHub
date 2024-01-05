#include<iostream>
#include <cmath>
#include <vector>
using namespace std;


int K, a; int arr[1100];
vector<int> v[15];

void go(int start, int end, int level)
{
	// 예외처리
	if (start > end) return;
	if (start == end)
	{
		v[level].push_back(arr[start]);
		return;
	}

	int t = (start+end) / 2;
	v[level].push_back( arr[t]);

	go(start, t - 1, level+1);
	go(t + 1, end, level+1);
	return;
}

int main()
{
	cin >> K;

	for (int i = 0; i < pow(2, K) - 1; i++)
	{
		cin >> a;
		arr[i] = a;
	}

	go(0, pow(2, K) - 1, 1);

	for (int i = 1; i <= K; i++)
	{
		for (int j : v[i])
			cout << j << " ";
		cout << endl;
	}
}


/*
문제 로직
1. 전위 순회를 한 결과를 보고 
2. 트리로 만들어준다. 

// 배열의 가운데를 출력
// 왼쪽, 오른쪽으로 나눠주고
// 왼쪽, 오른쪽의 가운데를 또 출력
-> 재귀

자료구조를 만들어 
level에 넣어줌으로써 해결!!



 */