#include<iostream>
#include<tuple>
#include<queue>
using namespace std;

int T, M, N, K;
int y, x;
int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, -1, 0, 1};
int cnt = 0;
vector<int> ans;

int main(){
	
	cin >> T;
	
	while (T > 0)
	{
		cin >> M >> N >> K;

		int m[51][51], visited[51][51];
		fill(&m[0][0], &m[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		queue < pair<int, int>> q;

		for (int i = 0; i < K; i++)
		{
			cin >> y;
			cin >> x;
			m[y][x] = 1;
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				//cout << "m["<<i<<"]["<<j<<"] : " << m[i][j] << "visited[i][j]" << visited[i][j] <<'\n';
				if (m[i][j] == 1 && visited[i][j] == 0) {
					if (q.empty()) {
						q.push({ i,j });
						//cout << i << " : " << j << "를 큐에 넣습니다.";
						visited[i][j] = 1;
					}
					//cout << i << " : " << j <<'\n';
					cnt++;
				}
				while (!q.empty())
				{
					//cout << "순회";
					tie(y, x) = q.front(); q.pop();
					for (int k = 0; k < 4; k++)
					{
						int ny, nx;
						ny = y + dy[k];
						nx = x + dx[k];
						if (nx < 0 || ny < 0 || nx > N || ny > M) continue;
						else if (m[ny][nx]== 1 && visited[ny][nx]==0)
						{
							//cout << ny << " : " << nx << '\n';
							visited[ny][nx] = 1;
							q.push({ ny,nx });
						}
					}
				}
			}
		}

	/*	for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << m[i][j];
			}
			cout << '\n';
		}*/
		ans.push_back(cnt);
		//cout << cnt <<'\n';
		cnt = 0;	
		T--;
	}

	for (int i : ans)
	{
		cout << i << '\n';
	}
}
