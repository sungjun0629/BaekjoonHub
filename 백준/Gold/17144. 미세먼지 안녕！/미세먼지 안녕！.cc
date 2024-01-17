#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;


int r, c, t; int dust; int ret;
int room[55][55];
int dust_spread[55][55];
// 좌표 값과 미세먼지 양까지 넣어준다. 
queue<tuple<int,int, int>> dust_area;
pair<int, int> upper_fresher, lower_fresher;
bool check_fresh_order = false;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
vector<pair<int, int>> upper_xy;
vector<pair<int, int>> lower_xy;


void find_route_xy(bool is_upper)
{
	int nx, ny;
	// 반시계 방향 
	if (is_upper)
	{
		nx = upper_fresher.second, ny = upper_fresher.first;
	}
	else 
	{
		nx = lower_fresher.second, ny = lower_fresher.first;
	}


	for (int i = 0; i < 4; i++)
	{
		int nyy = 0 , nxx = 0;
		while (true)
		{
			if (is_upper) nyy = ny + dy[i];
			else nyy = ny + -1 * dy[i];
			nxx = nx + dx[i];

			if (nyy < 0 || nxx<0 || nyy >= r || nxx>=c) break;
			if (nxx == upper_fresher.second && nyy == upper_fresher.first) break;
			if (nxx == lower_fresher.second && nyy == lower_fresher.first) break;

			//cout << nyy << " : " << nxx << endl;
			if (is_upper) upper_xy.push_back({ nyy, nxx });
			else lower_xy.push_back({ nyy,nxx });

			ny = nyy; nx = nxx;

		}

		//cout << endl;
	}
}



int main()
{
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> dust;
			room[i][j] = dust;

			// 공기청정기의 위치
			if (dust == -1)
			{
				// 제일 먼저 나온 순으로 upper, lower를 갖는다.  
				if (!check_fresh_order)
				{
					upper_fresher.first = i; upper_fresher.second = j;
					check_fresh_order = true;
				}
				else
				{
					lower_fresher.first = i; lower_fresher.second = j;
				}
			}
			// 미세먼지의 위치
			else if (dust>=5)
			{
				// 미세먼지가 존재하는 좌표를 넣어준다. 
				// 동시 확산을 위해 dust를 넣어준다. room[][]에 영향을 미치지 않음.
				dust_area.push({ i,j, dust });
			}

			if (dust > 0) ret += dust;
		}
	}

	find_route_xy(true); find_route_xy(false);
	while(t--)
	{
		// 미세먼지의 확산
			// 미세먼지는 상하좌우로 확산이 된다. 
		while (dust_area.size())
		{
			int x, y, room_dust;
			tie(y, x, room_dust) = dust_area.front(); dust_area.pop();
			int spread_gross = room_dust / 5;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
				// 공기청정기일 경우 
				if (room[ny][nx] == -1) continue;

				// 확산이 된다. 
				room[ny][nx] += spread_gross;
				room[y][x] -= spread_gross;
			}

		}


		// 공기청정기를 기준으로 반시계, 시계방향으로 움직여야 한다. 
		// 미세먼지양도 계속 변화한다. -> 직접 값을 바꿔주는게 구현이 편하다
		// 최대 300번 연산 -> T = 1000 이므로 300,000번 연산 
		// 공기청정기 순환 좌표를 만들어준다. 
		// 좌표를 순환하며 값을 바꿔준다. 
		
		for (int i = upper_xy.size() - 1; i >= 0; i--)
		{
			if (i == upper_xy.size() - 1)
			{
				//cout << "위의 공기청정기 : " << room[upper_xy[i].first][upper_xy[i].second] << endl;
				ret -= room[upper_xy[i].first][upper_xy[i].second];
				room[upper_xy[i].first][upper_xy[i].second] = room[upper_xy[i - 1].first][upper_xy[i - 1].second];
			}
			else if (i == 0)
			{
				room[upper_xy[i].first][upper_xy[i].second] = 0;
			}
			else
			{
				room[upper_xy[i].first][upper_xy[i].second] = room[upper_xy[i - 1].first][upper_xy[i - 1].second];
			}

		}

		for (int i = lower_xy.size() - 1; i >= 0; i--)
		{
			if (i == lower_xy.size() - 1)
			{
				//cout << "아래 공기청정기 : " << lower_xy[i].first << " : " << lower_xy[i].second << " : " << room[lower_xy[i].first][lower_xy[i].second] << endl;
				ret -= room[lower_xy[i].first][lower_xy[i].second];
				room[lower_xy[i].first][lower_xy[i].second] = room[lower_xy[i - 1].first][lower_xy[i - 1].second];
			}
			else if (i == 0)
			{
				room[lower_xy[i].first][lower_xy[i].second] = 0;
			}
			else
			{
				room[lower_xy[i].first][lower_xy[i].second] = room[lower_xy[i - 1].first][lower_xy[i - 1].second];
			}

		}


		


		// 미세먼지 부분을 다시 room_dust에 넣어준다.
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (room[i][j] >= 5)
				{
					dust_area.push({ i,j,room[i][j] });
				}

				//cout << room[i][j] << " ";
			}
			//cout << endl;
		}
		//cout << endl;
	}

	 
	cout << ret;
}