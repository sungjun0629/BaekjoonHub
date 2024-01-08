#include<iostream>
#include<cmath>

using namespace std;

const int MAX_NUMBER = 987654321;

int N, M, H, a, b;
int arr[34][34];
int rst = MAX_NUMBER;


bool checkLadder()
{
	for (int i = 1; i <= N; i++)
	{
		int temp = i;
		for (int j = 1; j <= H; j++)
		{
			if (arr[j][i]) i++;
			else if (arr[j][i - 1]) i--;
		}

		// 조건이 안 맞는 경우 바로 리턴한다.
		if (temp != i) return false;
	}

	// 모든 사다리가 조건에 통과되었을 경우
	return true;
}


void go(int a,  int cnt)
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// 기저 조건 : 추가한 사다리 개수가 4 이상인 경우 
	// 최소 사다리 개수를 구한 경우
	if (cnt > 3 || cnt >= rst) return;

	// 사다리가 조건에 만족하는지 체크를 한다.
	if (checkLadder())
	{
		rst = min(cnt, rst);
		return;
	}

	// 1번부터 N까지의 세로선 
	for (int i = a; i <= H; i++)
	{
		// 1번부터 H번까지의 가로선
		for (int j = 1; j < N; j++)
		{
			// 가로선이 연속되지 않을 경우
			// 기존의 가로선이 존재하지 않을 경우
			// -> 가로선을 추가한다. 
			if (arr[i][j + 1] || arr[i][j - 1] || arr[i][j])
			{
				continue;
			}

			arr[i][j] = 1;
			go(i, cnt+1);
			arr[i][j] = 0;
		}
	}
}


int main()
{
	cin >> N >> M >> H;

	// 가로선의 정보를 체크한다. 
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
	}

	// i번 세로선의 결과가 i번이 나와야 한다. 
	// 최소의 가로선을 추가할 수 있다(<=3) 
	go(1, 0);

	rst = (rst == MAX_NUMBER) ? -1 : rst;
	cout << rst;
	return 0;
}