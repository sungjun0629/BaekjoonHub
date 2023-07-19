#include<iostream>
#include<queue>
#include <tuple>
using namespace std;

int N, L, R;
int map[54][54];
int visited[54][54];
int dx[4] = {1, 0 , -1 , 0};
int dy[4] = {0, -1, 0 ,1 };
int BFS_count = -1; int result = -1;

void BFS(int y, int x)
{
	int union_population = 0;
	int union_count = 0;
	queue<pair<int, int>> q; q.push({y,x});
	visited[y][x] = 1; union_count++;
	union_population += map[y][x];
	vector<pair<int, int>> union_cities; 
	union_cities.push_back({y,x});
	
	while (q.size())
	{
		tie(y,x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y+ dy[i];
			int nx = x + dx[i];

			if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
			if(visited[ny][nx]) continue;
			// 이웃 도시 조건에 만족하는 경우 
			if (abs(map[y][x] - map[ny][nx]) >= L && abs(map[y][x] - map[ny][nx]) <= R)
			{
				// 연합의 인구 수를 구한다. 연합을 이루는 도시의 개수를 구한다.
				union_population += map[ny][nx]; union_count++;
				// 방문 여부 체크 
				visited[ny][nx] = 1; 
				// queue에 넣어준다. 
				q.push({ny, nx});
				// 좌표를 가져오기 위해 union_cities에 넣어준다.
				union_cities.push_back({ny, nx});
				BFS_count ++;
			}
		}

		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout<< visited[i][j]<<" ";
			}
			cout<<'\n';
		}*/

	}

	// 모든 순회가 끝나면 
	// 연합 도시가 있는 경우 (union_count>1)
	if (union_count > 1)
	{
		// 연합 도시의 좌표를 가져온다. 
		for (pair<int, int> city : union_cities)
		{
			//cout<<map[city.first][city.second]<<',';
			//cout<<"좌표는?" << city.first << city.second << ' ';
			// 연합 도시의 인구수를 union_population/union_count 로 바꿔준다. 
			map[city.first][city.second]  = int(union_population/union_count);
		}

		//cout<<'\n';
	}

}

int main() {

	cin>> N;
	cin>> L>> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin>>map[i][j];
		}
	}

	// 맵을 순회한다.
	while(BFS_count!=0)
	{
		BFS_count = 0; 
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// BFS를 실행하고, 이웃 도시를 찾는다.
				if(!visited[i][j]) BFS(i, j);
			}
		}
		

		// 디버그용
		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout<<map[i][j]<<' ';
			}
			cout<<'\n';
		}*/
	
		// 모든 순회가 끝나면 다시 순회를 한다. 
		// 언제까지? -> BFS_count == 0 일때까지 
		// 다시 순회해주기 위해 visited를 0으로 초기화 해준다.
		fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
		// 전체 순회 횟수 증가
		result ++;
	}
	cout<<result;

}