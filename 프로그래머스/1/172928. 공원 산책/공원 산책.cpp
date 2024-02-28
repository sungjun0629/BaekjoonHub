#include <string>
#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

char park_[55][55]; pair<int, int> here;
int  dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
int w, h;

pair<int,int> dfs(int y, int x, char dir, int dist)
{
	int dir_n = -1;
	if (dir == 'N') dir_n = 0;
	else if (dir == 'S') dir_n = 1;
	else if (dir == 'W') dir_n = 2;
	else dir_n = 3;

	int y_ = y;
	int x_ = x;

	// 거리만큼 해당 방향으로 이동한다.
	while (dist)
	{
		int ny = y_ + dy[dir_n];
		int nx = x_ + dx[dir_n];
		
		// 범위를 벗어날 경우 
		if (ny < 0 || nx < 0 || nx >= w || ny >= h) return{ y,x };
		// 장애물을 만날 경우
		if (park_[ny][nx] == 'X')
		{
			return{ y,x };
		}

		//cout << ny<< " : " << nx << "에서"<< park_[ny][nx] << endl;;
		dist--;
		y_ = ny; x_ = nx;
	}
	
	return { y_, x_ };
	
}

vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int> answer;

	// park를 2차원 배열의 형태로 만들어준다.
	int idx = 0;
	for (string s : park)
	{
		h = park.size();
		w = s.size();
		for (int i = 0; i < s.size(); i++)
		{
			park_[idx][i] = s[i];
			// 시작지점의 좌표를 넣어준다.
			if (s[i] == 'S') {
				here.first = idx, here.second = i;
			}
		}
		idx++;
	}

	// route를 순회하며 강아지를 이동시킨다.
	for (string s : routes)
	{
		//cout << "움직임" <<  here.first << " : " << here.second << endl;
		// routes parsing
		char dir = s[0]; int dist = s[2] - '0';
		// 현재 위치와 움직일 정보를 넣어준다.
		int ny, nx;
		tie(ny, nx) = dfs(here.first, here.second, dir, dist);

		here.first = ny, here.second = nx;
	}

	answer.push_back(here.first), answer.push_back(here.second);
	return answer;
}