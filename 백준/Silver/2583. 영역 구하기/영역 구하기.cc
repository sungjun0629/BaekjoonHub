#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


int M, N, K, input, nx,ny;
int m[104][104], visited[104][104];
int xy[4];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int cnt = 0;
vector<int> vec;

void makeMap()
{
	cin >> M >> N >> K;

	//map 및 visited에 정보 집어넣기
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> input;
			xy[j] = input;
		}

		for (int x = xy[0]; x < xy[2]; x++)
		{
			for (int y = xy[1]; y < xy[3]; y++)
			{
				m[y][x] = 1;
			}
		}

	}
}

int DFS(int y, int x) {
	
	visited[y][x] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
		if (visited[ny][nx] == 0 && m[ny][nx] != 1)
		{
			ret += DFS(ny, nx);
		}
	}

	return ret;
}

int main() {

	makeMap();

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			
			if (visited[i][j] == 0 && m[i][j] != 1)
			{
				vec.push_back(DFS(i, j));
			}
			
		}
	}

	sort(vec.begin(), vec.end());
	cout << vec.size()<<'\n';
	for (int num : vec)
	{
		cout << num << ' ';
	}

	return 0;
}