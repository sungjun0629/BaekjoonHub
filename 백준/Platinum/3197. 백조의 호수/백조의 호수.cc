#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int r, c;
char lake[1501][1501];
int visited[1501][1501];
// 백조 탐색에서 쓰일 visited
int visited_l[1501][1501];
char t;
queue<pair<int, int>> q;
queue<pair<int, int>> l;
queue<pair<int, int>> q_temp;
queue<pair<int, int>> l_temp;
pair<int, int> loc; int ret;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

void Qclear(queue<pair<int, int>>& q) {
	queue<pair<int, int>> empty;
	swap(q, empty);
}
bool check_meet(int y, int x)
{
	while (l.size())
	{
		tie(y,x) = l.front(); l.pop();
		//cout << y << " : " << x << " 확인" << '\n';
		for (int i = 0; i < 4; i++)
		{
			// 물 근처에 얼음이 있다면 그것을 녹인다.
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= r || nx >= c || nx < 0 || visited_l[ny][nx]) continue;

			visited_l[ny][nx] = true;
			if (lake[ny][nx] == 'L') return true;
			
			// 백조를 탐색할 위치 -> 처음부터 다시 탐색하지 않는다.     
			else if (lake[ny][nx] == 'X') {
				//cout << ny << " : " << nx << " 얼음으로 더이상 탐색 불가" << '\n';
				l_temp.push({ ny,nx });
			}
			else
			{
				l.push({ ny,nx });
			}
		}
	}

	// 다음에 탐색할 물의 좌표
	l = l_temp;
	// 큐 초기화
	Qclear(l_temp);

	return false;
}


void melt()
{
	int y, x;
	while(q.size())
	{
		// q에 들어있는 것은 얼음을 녹일 수 있는 물의 좌표.
		tie(y, x) = q.front(); q.pop();
		//visited[y][x] = true;
		for (int i = 0; i < 4; i++)
		{
			// 물 근처에 얼음이 있다면 그것을 녹인다.
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= r || nx >= c || nx < 0 || visited_l[ny][nx])  continue;

			if(lake[ny][nx]=='X')
			{
				visited[ny][nx] = true;
				//cout << ny << " : " << nx << "의 얼음을 녹인다" << '\n';
				lake[ny][nx] = '.';
				// 다음에 얼음을 녹일 물의 좌표를 넣어준다. 
				q_temp.push({ ny,nx });
			}

		}
	}

	// 다음에 탐색할 물의 좌표
	q = q_temp;
	// 큐 초기화
	Qclear(q_temp);
	ret++;
}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> t;
			lake[i][j] = t;

			// 만약 물 혹은 백조라면 queue에 넣어준다. 
			// 추후 얼음을 녹일 때 사용이 된다. 
			if (t == '.' || t == 'L')
			{
				visited[i][j] = true;
				q.push({ i,j });
			}
			if (t == 'L')
			{
				q.push({ i,j });
				// bfs 탐색을 위해 백조의 위치를 저장해둔다. 
				loc.first = i; loc.second = j;
			}
		}
	}

	// 백조가 서로 만날 수 없다면 -> bfs 탐색
	// 백조 탐색도 마찬가지로 탐색했던 마지막 지점에서 다시 탐색을 한다.
	// 얼음을 녹인다. 
	// -> 얼음이 있는 곳을 위주로만 탐색을 한다. 
	l.push({ loc.first, loc.second });
	visited_l[loc.first][loc.second] = true;
	while (!check_meet(loc.first , loc.second))
	{
		melt();
	/*	q = q_temp;
		l = l_temp;
		Qclear(l_temp);
		Qclear(q_temp);*/

	}
	
	cout << ret;
}