#include<iostream>
using namespace std;


int N, G; int arr[11][11];
int dx[4] = { 0, -1, 0 ,1 }, dy[4] = { -1,0,1,0 };
int visited[11][11]; int rst = 5000;

// 꽃이 겹치지 않는지 확인을 한다. 
bool check(int y, int x)
{
	// 꽃의 위치에 다른 꽃이 있는지 확인한다.
	if (visited[y][x]) return false;
	// 꽃잎의 위치에 따른 꽃이 있는지 확인한다.
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx<0 || ny >= N || nx>=N || visited[ny][nx])
		{
			return false;
		}
	}

	// 꽃이 없다면 참을 반환한다. 
	return true;
}

// 화단의 비용을 계산한다.
int cash(int y, int x)
{
	int sum = arr[y][x];
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i]; int nx = x + dx[i];
		visited[ny][nx] = 1;
		sum += arr[ny][nx];
	}

	return sum;
}

// 화단의 방문여부를 지워준다.(원복)
void erase(int y, int x)
{
	visited[y][x] = false;
	for (int i = 0; i < 4; i++)
	{
		int ny = y+ dy[i]; int nx = x+ dx[i];
		visited[ny][nx] = false;
	}
}

void search(int cnt, int sum)
{

	if (cnt == 3)
	{
		// 가장 작은 비용인지 총합(sum)을 비교한다.,
		if (rst >= sum) rst = sum;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 문제 조건에 부합을 한지 확인한다.
			// 조건에 부합하지 않다면 
			// 조건에 부합할 때까지 for문을 순회한다.
			// -> 다른 화단을 찾는다.   
			if (check(i,j))
			{
				// 해당 화단의 비용을 구한다. 
				search(cnt + 1, sum+cash(i,j));
				// 방문여부를 거짓으로 바꿔준다. 
				erase(i, j);

			}
		}
	}


}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> G;
			arr[i][j] = G;
		}
	}

	// [0][0] ~ [N-1][N-1] 까지 순회를 한다.
	// 총 3개의 화단의 가격이 가장 작은 경우를 찾는다.
	search(0, 0);

	cout << rst;
	return 0;
}