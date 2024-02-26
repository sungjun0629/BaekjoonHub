#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, t; 
vector<int> a, b;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t; a.push_back(t);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> t; b.push_back(t);
	}

	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());
	
	int sum = 0;
	for (int i = 0 ; i<a.size();  i++)
	{
		sum += a[i] * b[i];
	}
	cout << sum;
}