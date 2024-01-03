#include<iostream>
#include<queue>
#include<tuple>
using namespace std;


int R, C, K; char arr[6][6];
char G; int visited[6][6];
int dx[4] = { 0,1,0,-1 }; int dy[4] = { 1, 0, -1,0 };
queue<pair<int, int>> q; int cnt;



bool check(int y, int x)
{
	if (arr[y][x] == 'T') return false;
	if (y < 0 || x < 0 || y >= R || x >= C || visited[y][x]) return false;

	return true;
}

void Route(int y ,int x, int dist)
{
	// 기저조건
	if (y == 0 && x == C - 1)
	{
		if (dist == K) cnt++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i]; int nx = x + dx[i];

		// 갈 수 있는 길인지 체크를 한다. 
		if (check(ny, nx))
		{
			visited[ny][nx] = 1;
			Route(ny, nx, dist + 1);
			visited[ny][nx] = 0;
		}

	}
}


int main()
{
	cin >> R >> C >> K;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> G;
			arr[i][j] = G;
		}
	}

	// 도착지점에 도착하면 그 경우를 제외한 
	// 한 개씩 원복하여 다시 길을 찾는다. 
	visited[R - 1][0] = true;
	Route(R - 1, 0, 1);
	cout << cnt << endl;

	return 0;
}