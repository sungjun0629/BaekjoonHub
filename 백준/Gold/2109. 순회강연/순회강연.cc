#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;


int n, p, d;
vector<pair<int, int>> vec;
int day, ret;
// 오름차순 진행, 루트노드가 제일 작다. 
priority_queue<int, vector<int>, greater<int>> pq;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		vec.push_back({ d,p });
	}

	// d일 안에 와서 강연을 해주면 p만큼의 강연료를 지불한다.
	// d를 기준으로 오름차순을 진행하고 
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
	{

		if (pq.size() < vec[i].first)
		{
			pq.push(vec[i].second);
			ret += vec[i].second;
		}
		// d를 기준으로 강연을 갈 수 있는지 판단을 한다.
		else if (pq.size() >= vec[i].first && pq.top() < vec[i].second)
		{
			ret -= pq.top(); pq.pop();
			ret += vec[i].second; pq.push(vec[i].second);
		}
	}

	cout << ret;

}