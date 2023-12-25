#include<iostream>
#include<string>
using namespace std;


int N;
int makeConstructor(int k)
{
	string str = to_string(k);
	int rst;
	if (str.size() != 1) rst = k;
	else {
		rst = 0;
		return k + k; 
	}
	for (int i = 0; i < str.size(); i++)
	{
		rst += (int)(str[i])- 48;
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