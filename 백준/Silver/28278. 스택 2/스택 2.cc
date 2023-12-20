#pragma warning(disable:4996)

#include<iostream>
#include <stack>
using namespace std;


int N; int n, e;
stack<int> stk;
enum stack_command
{
	push = 1,
	popAndPrint,
	printStackNum,
	isStackEmpty,
	printStackTop
};


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &n);

		switch (n)
		{
		case push:
			scanf("%d", &n);
			stk.push(n); break;
		case popAndPrint:
			if (!stk.empty())
			{
				printf("%d\n", stk.top());
				stk.pop();
			}
			else
			{
				printf("-1\n");
			} break;
		case printStackNum:
			printf("%d\n", stk.size());
			break;
		case isStackEmpty:
			if (stk.empty())
				printf("1\n");
			else printf("0\n");
			break;
		case printStackTop:
			if (stk.empty())
				printf("-1\n");
			else printf("%d\n", stk.top());
			break;
		}

	}

	return 0;
}