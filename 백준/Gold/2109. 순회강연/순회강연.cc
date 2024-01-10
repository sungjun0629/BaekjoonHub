#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,d,p; 
vector<pair<int, int>> vec;
priority_queue<int , vector<int>, greater<int>> pq; 
int ret;

int main()
{
	cin>>n; 
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d; 
		// day를 기준으로 정렬할 것이므로 day를 가장 먼저 넣어준다. 
		vec.push_back({d, p});
	}

	// day를 기준으로 오름차순을 진행한다. 
	sort(vec.begin(), vec.end());

	// priority_queue를 이용하여, pay가 가장 작은 것을 빼준다. 
	for (pair<int, int> e : vec)
	{
		pq.push(e.second);
		//cout<< e.second << "를 넣어줍니다." << endl;
		ret += e.second; 
		if (pq.size() > e.first)
		{// 만약, 지금 넣고 있는 pay에 대한 day가 pq 사이즈보다 작다면
		 // pq에서 가장 작은 것을 하나 빼준다. 
			ret -= pq.top();
			//cout<< "사이즈를 초과하여 " << pq.top() << "을 빼줍니다." <<endl;
			pq.pop();
		}
	}
	// 위의 for문을 모두 순회하면
	// day일정에 맞게 최대한으로 큰 pay를 가져온 결과를 확인할 수 있다. 
	
	cout<< ret;


}