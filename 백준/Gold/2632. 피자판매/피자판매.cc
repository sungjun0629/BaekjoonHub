#include<iostream>
#include<map>


using namespace std;

int k, m, n;
int a_p[1004], b_p[1004];
// 원형이므로 기존의 조각보다 2배를 해준다.
int sum_a[2010], sum_b[2010];
map<int, int> a_cnt, b_cnt;

void sum_pizza(int n, map<int, int>& mm, int sum[])
{
	for (int interval = 1; interval<=n ; interval++)
	{
		// n번만 수행을 한다. 
		for (int start = interval; start <= n + interval - 1; start++)
		{
			int sum_ = sum[start] - sum[start - interval];
			mm[sum_]++;

			if (interval == n) break;
		}
	};
}


int main()
{
	cin >> k >> m >> n;
	// 피자 조각 크기
	// 합 배열을 위해 1부터 시작한다. 
	for (int i = 1; i <= m; i++)
	{
		cin >> a_p[i];
		// 누적 합  
		sum_a[i] = sum_a[i - 1] + a_p[i];
	}

	// 원형 순환 계산을 위해 2배로 늘린다. 
	for (int i = m + 1; i <= 2 * m; i++)
	{
		sum_a[i] = sum_a[i - 1] + a_p[i - m];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> b_p[i];
		sum_b[i] = sum_b[i - 1] + b_p[i];
	}

	for (int i = n + 1; i <= 2 * n; i++)
	{
		sum_b[i] = sum_b[i - 1] + b_p[i - n];
	}

	// 피자 합 배열로부터 모든 구간 합을 구하며 
	// 가능한 피자의 합에 대한 개수를 구한다. 
	sum_pizza(m, a_cnt, sum_a);
	sum_pizza(n, b_cnt, sum_b);

	int ret = 0;
	// 각각 구한 가능한 피자 합으로부터 
	// 경우의 수를 구한다. 
	for (int i = 1; i < k; i++)
	{
		int a = a_cnt[i];
		int b = b_cnt[k - i];

		ret += a * b;
	}

	ret += a_cnt[k] + b_cnt[k];

	cout << ret;

}