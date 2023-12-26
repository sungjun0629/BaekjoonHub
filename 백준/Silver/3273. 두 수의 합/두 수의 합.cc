#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, x; 
vector<pair<int,int>> vec;
int main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		vec.push_back({x,i});
	}
	cin >> x; 

	// 오름차순으로 만들어준다. 
	sort(vec.begin(), vec.end());
	auto left = vec.begin(); 
	auto right = vec.end() -1;
	int sum = 0; int count = 0;

	while (left < right)
	{
		sum = left->first + right->first;
		if (sum > x)
		{
			sum -= right->first;
			right--; sum += right->first;
		}
		else if (sum < x)
		{
			sum -= left->first;
			left++; sum += left->first;
		}
		else if (sum == x)
		{
			count++; 
			sum -= left->first;
			left++; sum += left->first;
		}
	}
	
	cout << count << endl;
	

}