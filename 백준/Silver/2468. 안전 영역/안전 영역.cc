#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;


int N;
int m[101][101], visited[101][101];
int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, -1, 0 ,1 };
queue<pair<int, int>> q;
int cnt, ret = 0;
int ip;

void BFS(int y, int x, int max)
{
	q.push({y,x});
	visited[y][x] = 1;

	while(q.size())
	{
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny, nx;
			ny = y + dy[i];
			nx = x + dx[i];

			if (ny < 0 || nx < 0 || nx >= N || ny >= N) continue;
			if (m[ny][nx] > max && visited[ny][nx] == 0)
			{
				visited[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {

	cin >> N;

	//맵 만들기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> ip;
			m[i][j] = ip;
		}
	}

	//물의 높이 정보 바꾸기
	for (int max = 0; max < 101; max++)
	{

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j] == 0 && m[i][j] >max)
				{
					BFS(i, j, max);
					cnt++;
				}
			}
		}

		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << visited[i][j];
			}
			cout << '\n';
		}

		cout << max << "나눠지는 개수" << cnt<< '\n';*/
		if (cnt > ret) ret = cnt;
		//cout << "최대를 갖는 높이는 " << ret << '\n';
		cnt = 0;
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
	}
	// 맵 확인
	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << m[i][j] << ' ';
		}

		cout << '\n';
	}*/

	cout << ret;
	return 0;
}