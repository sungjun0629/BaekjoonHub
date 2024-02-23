#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int n, m, t;
vector<int> a, b;
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) 
	{
		cin >> t; a.push_back(t);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> t; b.push_back(t);
	}

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
	int cnt_a = 0;
	// a를 순회하며 b와 같은 원소가 있는지 확인을 한다.
	for (int i : a)
	{
		// 이진 탐색을 통해 시간 복잡도를 줄인다.
		if (binary_search(b.begin(), b.end(), i)) cnt_a++;
	}

	// 예외 : 중복되는 원소가 있을 수 있다.
	// A,B 각각 공집합을 구한다. 

	int cnt_b = 0;
	for (int i : b)
	{
		// 이진 탐색을 통해 시간 복잡도를 줄인다.
		if (binary_search(a.begin(), a.end(), i)) cnt_b++;
	}


	int rst = n + m  - cnt_a -cnt_b;

	cout << rst;
}