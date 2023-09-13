#include<iostream>
#include<vector>
#include <queue>
#include<algorithm>
using namespace std;


int d, c, ret, N;
vector<pair<int,int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin>>N;
	for (int i = 0; i < N; i++)
	{
		cin>>d>>c;
		vec.push_back({d,c});
	}
	
	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++)
	{
		pq.push(vec[i].second);
		
		if (vec[i].first < pq.size())
		{
			pq.pop();
		}
	}

	while (pq.size())
	{
		ret += pq.top();
		pq.pop();
	}

	cout<<ret;
}