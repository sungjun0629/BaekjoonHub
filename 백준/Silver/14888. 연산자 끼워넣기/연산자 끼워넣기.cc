#include<iostream>
#include<vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, t; 
vector<int> num; vector<int> oper;
vector<int> operForPermu; int min_ret = 9876543210; int max_ret = -9876543210;


int calculate_num()
{
	int ret = 0;
	// 입력 받은 num을 순회하며
	// 연산자 입력 순서에 따라 연산을 한다.
	for (int i = 0; i < num.size()-1; i++)
	{
		int oper_ = operForPermu[i] / 100 ;
		// num[0] (operForPermu[0]) num[1]
		// ret (opernForPermu[1]) num[2]
		int pioper;
		if (i == 0) pioper = num[i];
		else pioper = ret;

		if (oper_ == 1)
			ret = pioper + num[i + 1];
		else if (oper_ == 2)
			ret = (pioper - num[i + 1]);
		else if (oper_ == 3)
			ret = (pioper * num[i + 1]);
		else ret = (pioper / num[i + 1]);

	}

	return ret;
}



int main()
{
	cin >> n;

	// 피연산자 입력
	for (int i = 0; i < n; i++)
	{
		cin >> t; num.push_back(t);
	}

	// 연산자 개수 입력
	for (int i = 0; i < 4; i++)
	{
		cin >> t; oper.push_back(t);
	}

	// 연산자가 a,a,b,c 형태로 나오면 완전 탐색 가능
	// 순열은 숫자가 겹치니깐 100, 200, 300, 400 번대로 구분을 해준다
	for (int i =0 ; i<oper.size() ; i++)
	{
		int d = 100 * (i + 1);
		for (int j = 0; j < oper[i]; j++)
		{
			operForPermu.push_back(d++);
		}
	}

	
	do {

		// 연산자 순열에 따라 계산을 수행한다. 
		int ret = calculate_num();
		min_ret = min(ret, min_ret);
		max_ret = max(ret, max_ret);
	} while (next_permutation(operForPermu.begin(), operForPermu.end()));

	cout << max_ret << '\n';
	cout << min_ret << '\n';

	return 0;
}