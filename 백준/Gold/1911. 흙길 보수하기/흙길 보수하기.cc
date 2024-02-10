#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


int n, l;
vector<pair<long long, long long>> pool; long long ret;
int main()
{
	// 널빤지로 다리를 만들어 물웅덩이를 모두 덮는다.
	// 널빤지의 최소 개수
	// n : 웅덩이의 개수 l : 널빤지의 길이
	cin >> n >> l;

	// 웅덩이에 대한 정보 
	for (int i = 0; i < n; i++)
	{
		long long s, e;
		cin >> s >> e;

		// 배열로 10억을 다루기엔 너무 크다. 
		// 웅덩이에 대한 정보만 받는다. 
		pool.push_back({ s,e });
	}

	// 웅덩이의 시작점을 기준으로 오름차순 정렬을 한다.
	sort(pool.begin(), pool.end());

	// 시작범위(s1)부터 끝범위(e1)
	// 시작범위(s2)부터 끝범위(e2)
	// 만약 s2 - e1 < l 이라면 널빤지를 아낄 수도 있다. 

	// 시작부터 계속 덮는다. 
	// l을 기준으로 웅덩이를 탐색한다. 
	int wood_idx = -1;
	long long prev_end = 0;
	for (pair<long long, long long> i : pool)
	{
		long long  start = i.first ;
		long long end = i.second ;

		// 만약 마지막에 널빤지가 남았고
		// 그 다음 웅덩이와 차이가 많이 없다면 널빤지를 아낄 수 있다. 
		if(wood_idx >= end) continue;
		else if (wood_idx >= start)
		{
			int temp;
			temp = (end - wood_idx ) / l;
			if ((end - wood_idx ) % l != 0) temp++;
			ret += temp;

			wood_idx += l * temp;
		}
		// 차이가 없을 때 
		else
		{
			int temp;
			temp = (end - start) / l;
			if ((end - start) % l != 0) temp++;
			ret += temp;

			wood_idx = start + temp*l;
		}

	}

	cout << ret;

}