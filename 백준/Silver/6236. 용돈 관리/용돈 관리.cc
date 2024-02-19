#include<iostream>
#include<cmath>

using namespace std;

int n,m;
int day_use[100004]; int ret=987654321;

bool check_left(int cost)
{
	// 하루 사용량을 순회하며 
	// 인출 금액 cost에 대한 인출 횟수를 확인한다. 
	int cnt = 0;
	int left_cost = 0;
	int use_cost = 0;
	for(int i = 0 ; i<n; i++)
	{
		use_cost = day_use[i];

		// 사용해야 할 금액이 현재 남아있는 금액보다 크다면 
		// 인출을 해야한다. 
		if(left_cost <  use_cost) {
			left_cost = cost;
			cnt++;
		}
		
		// 현재 갖고 있는 금액에서 사용할 금액을 빼준다.
		left_cost -= use_cost;
	}

	// 모든 순회가 끝나고 원하는 인출 횟수와 같으면 참을 반환한다.
	if(m >= cnt) return true;
	else return false;
}


int main()
{
	cin >> n >> m;
	int max_cost = -1;
	// 하루 사용하는 금액을 넣는다. 
	for(int i = 0; i<n; i++)
	{
		cin >> day_use[i];
		max_cost = max(day_use[i], max_cost);
	}

	// 초기값 설정 
	int lo = max_cost ;
	int hi = 1000000004;
	int mid = 0;
	while(lo <= hi)
	{
		mid = (lo + hi) /2 ;
		if(check_left(mid))
		{
			// 더 작은 금액으로 확인을 해본다.
			hi = mid -1 ; 
			//cout << "더 작은 금액" <<mid<< endl;
			ret = mid;
		}
		else
		{
			// 더 큰 금액으로 확인을 해본다.
			lo = mid +1;
			//cout << "더 큰 금액" <<mid << endl;
		}
	}

	// 결과값을 도출한다.
	cout<< ret;
}