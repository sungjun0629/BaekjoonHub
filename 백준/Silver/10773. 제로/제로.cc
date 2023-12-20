#include<iostream>
#include <stack>
#pragma warning(disable:4996)
using namespace std;


int K, tmp; 
int cnt;
stack<int> stk;
int main()
{
	scanf("%d", &K);

	for (int i = 0; i < K; i++)
	{
		scanf("%d", &tmp);
		if (tmp == 0) stk.pop();
		else stk.push(tmp);
	}

	while(!stk.empty())
	{
		cnt += stk.top();
		stk.pop();
	}
	

	printf("%d\n", cnt);


	return 0;
}