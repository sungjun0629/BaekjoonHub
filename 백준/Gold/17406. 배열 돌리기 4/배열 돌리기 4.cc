#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<cstring>

using namespace std;

int n, m, k;
int arr[52][52];
int copyArr[52][52];
int dy[] = { 0,1,0,-1 }; int dx[] = { 1,0,-1,0 };

struct A
{
	int r, c, s;
} ri;

vector<A> rotate_info;
vector<int> idx;
vector<pair<int, int>> yx_info;
vector<int> yx_value;

// 배열의 회전을 수행한다. 
void rotate_(int r, int c, int d)
{
	// 각각의 꼭짓점에 대한 정보를 입력
	pair<int, int> nw = { r - d,c - d };
	pair<int, int> ne = { r - d, c + d };
	pair<int, int> sw = { r + d, c - d };
	pair<int, int> se = { r + d,c + d };

	yx_value.clear(); yx_info.clear();

	int y, x;
	tie(y, x) = nw;
	int i = 0; bool first_try = true;
	// nw부터 시작하여 시계 방향으로 회전을 하며 정보를 넣어준다.
	while(true)
	{
		// 좌표 정보를 넣어준다. 
		yx_info.push_back({ y,x });
		// 좌표에 해당하는 원소 정보를 넣어준다. 
		yx_value.push_back(arr[y][x]);

		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if ((ny == ne.first && nx == ne.second) || (ny == sw.first && nx == sw.second) || (ny == se.first && nx == se.second))
		{
			i++;
		}
		// 처음 지점으로 돌아왔을 때
		if((ny == nw.first && nx == nw.second) && !first_try) break;

		y = ny; x = nx;
		first_try = false;
	}

	// 입력 받은 정보(좌표, 값)에 대하여 값을 회전시켜주고
	// 좌표에 넣어준다.
	rotate(yx_value.begin(), yx_value.end()-1, yx_value.end());
	
	for (int i = 0 ; i<yx_value.size() ; i++)
	{
		arr[yx_info[i].first][yx_info[i].second] = yx_value[i];
	}

}


// 배열 정보와 순서 정보를 받는다.
// 배열과 순서는 최신화된다.
// 최소 행의 값을 반환한다. 
int go(int arr[52][52], vector<int> order)
{
	int ret = 987654321;
	// 회전 순서대로 연산을 한다. 
	for (int i : order)
	{
		// 회전 연산에 대한 정보를 제공한다.
		int y = rotate_info[i].r;
		int x = rotate_info[i].c;
		int t = rotate_info[i].s;

		// 회전 연산의 정보를 토대로 회전을 수행한다. 
		for (int k = 1; k <= t; k++)
		{
			rotate_(y, x, k);
		}

	}

	// 최소 행의 값을 찾는다. 
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += arr[i][j];
		}

		ret = min(ret, sum);
	}

	return ret;
}



int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> copyArr[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		cin >> ri.r >> ri.c >> ri.s;
		// 입력값과 배열 인덱스를 맞춰준다. 
		ri.r--; ri.c--;
		rotate_info.push_back(ri);
		// 회전 연산 순열을 위해 사용한다.->순서를 결정하기 위함.
		idx.push_back(i);
	}

	int ret = 987654321;
	do 
	{
		// 0 1 2, 0 2 1, ... 과 같은 순서를 제공한다. 
		
		memcpy(arr, copyArr, sizeof(copyArr));
		ret = min(ret, go(arr, idx));

	} while (next_permutation(idx.begin(), idx.end()));

	cout << ret;
}