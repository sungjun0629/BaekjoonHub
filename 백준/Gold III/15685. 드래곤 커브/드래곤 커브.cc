#include<iostream>
#include<vector>

using namespace std;

int n; int arr[110][110];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
int ret;
struct dc
{
	int x, y, d, g;
}dcc;

vector<dc> dc_info;

void Rotate_90(vector<pair<int,int>>& b, int idx)
{
	// 끝점을 기준으로 한다.
	pair<int, int> end_point = b.back();
	//for (pair<int, int> i : b) cout << i.first << " : " << i.second << endl;
	vector<pair<int, int>> vec;
	// 끝점을 원점으로 보정한다. 
	int correct_x = -1 * end_point.first; int correct_y = -1 * end_point.second;
	// 모든 점을 끝점을 기준으로 보정한다.
	for (pair<int, int> i : b)
	{
		//cout << i.first << " : " << i.second << "에 대하여";
		i.first += correct_x; i.second += correct_y;

		// 회전공식에 따라, (-y, x)으로 바꿔주고 
		int temp = i.first;
		i.first = -1 * i.second; i.second = temp;
		// 다시 끝점과 모든 점을 복구시킨다. 
		i.first += end_point.first; i.second += end_point.second;
		// 새로 생성된 점들에 대하여 점을 찍어준다. 
		arr[i.second][i.first] = idx;
		//cout << i.first << " : " << i.second << "찍어준다" << endl;
		vec.push_back({ i.first, i.second });
	}
	
	for(int i = vec.size() - 2 ; i>=0 ; i--)
	{
		b.push_back(vec[i]);
	}

}

void find_rec()
{
	for (int i = 0; i < 110-1; i++)
	{
		for (int j = 0; j < 110-1; j++)
		{
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1])
				ret++;
		}
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> dcc.x >> dcc.y >> dcc.d >> dcc.g;
		dc_info.push_back(dcc);
	}

	// 드래곤 커브의 정보를 순회한다. 
	int idx = 1;
	for (dc i : dc_info)
	{
		vector<pair<int, int>> xy_;
		// 초기값 세팅(기본 0세대)
		// 시작 방향에 따라 0 세대의 위치가 달라진다. 
		xy_.push_back({ i.x, i.y });
		xy_.push_back({ i.x + dx[i.d] ,i.y + dy[i.d] });
		arr[i.y][i.x] = idx; arr[i.y + dy[i.d]][i.x + dx[i.d]] = idx;


		// 끝점을 기준으로 시계 방향으로 90도 회전한다.  
		int cnt = i.g;
		while (cnt)
		{
			cnt--;
			Rotate_90(xy_,idx);
		}
		idx++;
	}

	find_rec();
	/*for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << ret;
}