#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N; int k; vector<int> vec; pair<int, int> rst;
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int min = 2000000000;
	for (int i = 0; i < N; i++)
	{
		cin >> k;
		vec.push_back(k);
	}

	// 0에 가장 가까운 용액을 만든다. 
	// 산성용액과 알칼리성 용액 둘 다 있다면 
	// -99, -2, -1, 4, 25 -> -1, -2 

	// 오름차순으로 정렬을 한다.
	// 원소*-1을 찾고 각각 앞,뒤로 더해준다.
	sort(vec.begin(), vec.end());
	auto left = vec.begin();
	auto right = vec.end() - 1;
	
	while (left < right)
	{
		int sum = *left + *right; 
		
		if (abs(sum) < min)
		{
			min = abs(sum);
			rst.first = *left;
			rst.second = *right;
		}

		if (sum > 0) {
			if (right - 1 == left) break;
			sum -= *right;
			right--;
		}
		else if (sum < 0)
		{
			if (left+1 == right) break;
			sum -= *left;
			left++;
		}
		else if (sum == 0)
		{
			cout << *left << " " << *right << endl;
			return 0;
		}

	}

	cout << rst.first << " " << rst.second << endl;
}