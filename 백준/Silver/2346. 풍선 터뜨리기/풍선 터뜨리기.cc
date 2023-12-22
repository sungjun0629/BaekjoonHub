#include<iostream>
#include<deque>
using namespace std;


struct BallonInfo
{
	int move;
	int index;
};

int N, temp; deque<struct BallonInfo> dq; int arr[1005];
int cnt = 1;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		BallonInfo ballonInfo = {temp,i+1};
		dq.push_back(ballonInfo);
	}

	int move = 0;

	while (!dq.empty())
	{
		cout << dq.front().index << " ";
		move = dq.front().move; dq.pop_front();

		if (move > 0)
		{
			move--;
			while (!dq.empty() && move > 0)
			{
				move--; dq.push_back(dq.front()); dq.pop_front();
			}
		}
		else
		{
			while (!dq.empty() && move < 0)
			{
				move++; dq.push_front(dq.back()); dq.pop_back();
			}
		}
	}


	return 0;
}