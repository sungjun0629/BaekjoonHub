#include<iostream>
#include <queue>
using namespace std;



int N, K; queue<int> origin, rst;
int main()
{
	cin >> N >> K;
	int cnt = 1;
	for (int i = 0; i < N; i++)
	{
		origin.push(i + 1);
	}

	// K번째 있는 사람이라면 pop을 하고 rst로 옮겨준다.
	while (!origin.empty())
	{
		if (cnt == K)
		{
			rst.push(origin.front()); origin.pop(); cnt = 1;
		}
		else
		{
			cnt++; origin.push(origin.front()); origin.pop();
		}
	}

	cout << "<";
	while (rst.size() != 1)
	{
		cout << rst.front() << ", "; rst.pop();
	}
	cout << rst.front() << ">" << endl;

	return 0;
}