#include<iostream>
#include<string>
using namespace std;


int N;
int makeConstructor(int k)
{
	int rst = k;

	while (k > 0)
	{
		rst += k % 10;
		k /= 10;
	}

	return rst;
}

int main()
{
	cin >> N;
	// 자연수 N이 주어졌을 때, 
	// N의 가장 작은 생성자를 구해낸다.
	// 생성자는 N보다 작다. 
	for (int i = 1; i <= N; i++)
	{
		int t = makeConstructor(i);
		if (t == N)
		{
			cout << i << '\n'; return 0;
		}
	}

	cout << 0 << '\n'; return 0;

}