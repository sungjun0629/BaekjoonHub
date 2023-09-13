#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, a, t;
int accumT = 0;
vector<pair<int, int>> vec;

int main()
{
	cin>>N;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> t;
		vec.push_back({a,t});
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < N; i++)
	{
		//cout<< "검사 : "<< vec[i].first << '\n';
		if (vec[i].first >= accumT)
		{// 도착시간에 검문을 받을 수 있는 상태
			accumT = vec[i].first + vec[i].second;
		}
		else {
		// accumT 시간에 검문을 받을 수 있는 상태
			accumT += vec[i].second;
		}
	}

	cout<<accumT;
}