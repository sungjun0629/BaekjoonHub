#include<iostream>
#include<vector>
#include<cmath>
#include <cstdint>
#include <cstring>

using namespace std;

int n, m;
int map_info[10][10];
int map_copy[10][10];
int map_min[10][10];
vector<pair<int, int>> cctv;
int ret = 987654321;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };

int checkCantSee()
{
	int rst = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 사각지역
			if (map_info[i][j] == 0) rst++;
		}
	}

	return rst;
}

vector<pair<int, int>> cctvCheck(int y, int x, int dir)
{
	vector<pair<int, int>> rst;
	// cctv_num에 따라서 확인 범위를 다르게 준다.
	// dir에 따라 확인 범위를 다르게 준다.
	// cctv_num == 1 이고 dir == 0 이라면, 오른쪽으로만 탐색.
	// nx = x + dx[0] 
	int cctv_num = map_info[y][x];
	//cout<< cctv_num << " check"<<endl;
	// cctv 감시 범위 횟수
	int cnt = 0;
	// enum으로 변경?
	if (cctv_num == 1) cnt = 1;
	else if (cctv_num == 2) cnt = 2;
	else if (cctv_num == 3) cnt = 2;
	else if (cctv_num == 4) cnt = 3;
	else if (cctv_num == 5) cnt = 4;

	int nx = x + dx[dir], ny = y + dy[dir];

	for (int i = 0; i < cnt; i++)
	{
		//cout << cctv_num << "의 cctv 확인 방향은 " << dir <<  endl;
		//cout << "탐색 ny : " << ny << " nx : " << nx << endl;
		while (true)
		{
			if ((ny < 0 || nx < 0 || nx >= m || ny >= n)) break;
			if (map_info[ny][nx] == 6) break;
			//cout<< ny << " : " << nx <<"변경"<<endl;
			// cctv의 감시 범위라는 것으로 값을 변경해준다.
			if (map_info[ny][nx] == 0) {
				map_info[ny][nx] = -1;
				rst.push_back({ ny,nx });
			}
			nx = nx + dx[dir], ny = ny + dy[dir];
		}
		if (cctv_num == 2) {
			dir += 2; if (dir > 3) dir -= 4;
			nx = x + dx[dir], ny = y + dy[dir];
		}
		else if (cctv_num >= 3) {
			dir += 1; if (dir > 3) dir = 0;
			nx = x + dx[dir], ny = y + dy[dir];
		}
	}

	return rst;
}

void cctv_on(int cctv_idx)
{
	// 기저조건은 마지막 cctv까지 확인을 했을때
	if (cctv_idx == cctv.size())
	{
		// map 전체를 순회하고 사각지대의 개수를 확인한다. 
		int cantSeeCnt = checkCantSee();
		// 최소가 되는 사각지대를 결과값에 넣는다.
		if (ret > cantSeeCnt)
		{
			memcpy(map_min, map_info, sizeof(map_min));
		}
		ret = min(ret, cantSeeCnt);

		/*cout << "--- 카메라 범위 체크 --- " << cctv_idx<<   endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << map_info[i][j] << " ";
			}
			cout << endl;
		}*/
		return;
	}

	// cctv를 순회하며 방향을 바꿔준다.
	/*for (int i = cctv_idx; i < cctv.size(); i++)
	{*/
	// 현재 cctv 정보
	int x = cctv[cctv_idx].second; int y = cctv[cctv_idx].first;
	//int cctv_num = map_info[y][x];
	// 	4방향으로 cctv를 확인할 수 있다. 
	for (int j = 0; j < 4; j++)
	{
		// cctv 번호와 방향에 따라 map의 정보를 바꿔준다.  
		vector<pair<int, int>> wonbok = cctvCheck(y, x, j);
		// 배열이므로 원본이 바뀌기 때문에 원복이 필요하다.
		cctv_on(cctv_idx + 1);
		for (auto b : wonbok) map_info[b.first][b.second] = 0;
	}
	//}
}


int main()
{
	cin >> n >> m;

	// 맵의 정보를 입력 받는다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map_info[i][j];
			map_copy[i][j] = map_info[i][j];
			// 해당 정보가 cctv라고 한다면 
			if (map_info[i][j] && map_info[i][j] < 6)
			{
				// cctv의 좌표를 넣어준다.
				cctv.push_back({ i,j });
			}
		}
	}

	// cctv를 순회하며 
	// map에서의 사각지대를 관찰한다.
	// cctv 순서를 통해 확인을 한다. 
	cctv_on(0);

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map_min[i][j] << " ";
		}cout << endl;
	}*/

	// 최소값을 출력한다.
	cout << ret;
}