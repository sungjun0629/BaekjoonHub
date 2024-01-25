#include<iostream>
#include<vector>
#include<algorithm>

typedef long long ll;
using namespace std;

ll n, m; int t;
// 보석의 개수를 담는다.
vector<int> j_cnt;
int low = 1, hi = -1; ll rst = 987654321;


// 학생 수 이내로 분배할 수 있는지 확인을 한다.
// -> mid 값으로 각각의 보석을 나눠준 후 학생 수(n)보다 작으면 조건에 부합한다.
bool check_con(long long mid)
{
	int cnt = 0; 
	for (int i = 0; i < j_cnt.size(); i++)
	{
		cnt += j_cnt[i] / mid;
		// 만약 나누어 떨어지지 않는 경우 나머지 값을 가져갈 학생 인원을 추가한다.
		// 7/2 -> 2,2,2,1 이 되는 경우
		if (j_cnt[i] % mid) cnt++;
	}

	return n >= cnt;
}


int main()
{
	// n은 학생의 수 , m은 색상의 가지수 
	cin >> n >> m;
	

	for (int i = 0; i < m; i++)
	{
		// 각각의 보석을 개수를 담는다. 
		cin >> t;

		j_cnt.push_back(t);
		// 최대의 보석 개수를 찾는다. 
		hi = max(hi, t);
	}


	// 학생은 항상 같은 색상의 보석만 가져간다. 
	// 질투심이 최소가 되어야 한다 -> 한 명이 갖는 최대의 보석 개수
	// 최소 1개의 보석에서 보석의 크기가 제일 큰 개수만큼 분배할 수 있다. 
	
	// 7 4 개의 보석이 있다면 
	// 1개의 보석부터 최대 7개의 보석까지 나눠줄 수 있다. 
	// 1개의 보석을 나눌 때 7 -> 7명, 4-> 4명
	// 7개의 보석을 나눌 때 7 -> 1명, 4-> 1명 이 나온다. 

	// 따라서, 이분탐색을 통해 질투심이 최소가 되는 경우를 찾는다. 
	while (low <= hi)
	{
		ll mid = (low + hi) / 2;
		//cout << "탐색 범위 low : " << low << " mid : " << mid  << " hi : " << hi << endl;
		if (check_con(mid))
		{// 학생 인원 수 이내로 분배할 수 있을 때
			
			// mid가 최소 값이라면 결과 값에 넣어준다.
			rst = min(rst, mid);

			// 더 작은 mid 값이 있는지 확인을 한다.
			hi = mid - 1;
		}
		// 그렇지 못할 때
		// 더 많은 보석을 분배해야 한다.
		else low = mid + 1;
	}

	cout << rst;
}

