#include<iostream>

using namespace std;


int n, m; int arr[100040];
int sum; int mm = -1;
int lo, hi, mid; int ret;

bool check_mid(int mid)
{
	// 만약, 최대 강의 시간 > 블루레이 강의 시간 이라면
	// 블루레이 시간에 담을 수 없기 때문에 false 
	if (mm > mid) return false;

	// 모든 강의를 순회하며 
	// 블루레이 시간으로 담을 수 있는 강의를 확인한다.
	int temp = mid;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (mid - arr[i] < 0)
		{
			mid = temp;
			cnt++;
		}

		mid -= arr[i];
	}

	// 채워지는게 후불이므로 
	// 마지막 강의도 확인을 해준다.
	if (mid != temp) cnt++;

	if (cnt <= m) return true;
	else return false;

}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		// 강의 시간 > 최대의 강의 크기를 비교하기 위해서 
		mm = max(mm, arr[i]);
	}

	// 초기값 세팅, 0 부터 최대의 크기
	lo = 0; hi = sum;

	while (true)
	{
		mid = (lo + hi) / 2;
		
		// mid 값이 조건에 만족하는지 확인을 한다.
		if (check_mid(mid))
		{
			hi = mid - 1;
			ret = mid;
		}
		else
		{
			lo = mid + 1;
		}

		if (lo > hi) break;
	}
	
	cout << ret;


}