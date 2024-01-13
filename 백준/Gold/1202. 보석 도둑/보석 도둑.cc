#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;


int n, k; int m, v, c;
vector<pair<int, int>> d;
vector<int> b;
long long ret;
// 내림차순-> 제일 큰 것이 루트 노드에 들어간다.
priority_queue<int, vector<int>> pq;

int main()
{
	// n: 보석의 개수 , k: 가방의 개수
	cin >> n >> k;

	// 보석에 대한 정보
	for (int i = 0; i < n; i++)
	{
		// m : 무게 , v : 가격
		cin >> m >> v;
		// 보석을 담을 자료 구조
		// 무게를 기준
		d.push_back({ m,v });
	}

	// 가방 최대 무게에 대한 정보
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		// 가방의 최대 무게를 담을 자료 구조
		b.push_back(c);
	}

	sort(d.begin(), d.end());
	sort(b.begin(), b.end());

	// 크기가 가장 작은 가방에 
	// 크기에 맞는 보석을 넣어준다.
	// 가방을 기준으로 순회
	int idx = 0;
	for (int i = 0; i < k; i++)
	{
		// 보석을 순회하며 제일 큰 값을 큐에 넣어준다.
		// 이로써 제일 큰 보석을 가방의 크기에 맞게 넣을 수 있게된다. 
		for (int j = idx; j < n; j++)
		{
			// 만약 보석의 크기가 가방보다 더 크다면 보석의 순회를 멈춘다.
			if(d[j].first > b[i]) break;
			// idx는 이미 순회한 보석을 다시 순회하지 않도록 한다.
			// 가격을 pq에 넣어주므로 다시 할 필요가 없다. 
			idx++;
			pq.push(d[j].second);
		}

		// 제일 비싼 보석을 결과 값에 더해주고, pq에서 제외시킨다. 
		if (!pq.empty())
		{
			ret += pq.top(); pq.pop();
		}
	}

	cout << ret;
	return 0;
}