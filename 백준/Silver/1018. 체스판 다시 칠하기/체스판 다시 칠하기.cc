#include<iostream>
using namespace std;


int N, M; char arr[51][51]; char color;
char chess_w[8][8]; char chess_b[8][8];
int rst_min = 999999999;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 체스판 예시를 만들어준다.
	chess_w[0][0] = 'W';
	for (int i = 0; i < 8; i++)
	{
		if (i != 0) chess_w[i][0] = (chess_w[i-1][0] == 'W') ? 'B' : 'W';
		for (int j = 1; j < 8; j++)
		{
			chess_w[i][j] = (chess_w[i][j-1]=='W') ? 'B' : 'W';
		}
	}

	chess_b[0][0] = 'B';
	for (int i = 0; i < 8; i++)
	{
		if (i != 0) chess_b[i][0] = (chess_b[i - 1][0] == 'W') ? 'B' : 'W';
		for (int j = 1; j < 8; j++)
		{
			chess_b[i][j] = (chess_b[i][j - 1] == 'W') ? 'B' : 'W';
		}
	}


	// 보드 예시를 입력 받는다. 
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> color;
			arr[i][j] = color;
		}
	}

	// 체스판과 보드를 비교한다.
	int cnt = (N - 7);
	int delta_y = 0;
	while(cnt-->0)
	{
		int delta_x = 0;
		int rst_w_change = 0;
		// chess_w 와 비교

		int m_cnt = M - 7;
		while(m_cnt-->0)
		{
			for (int i = 0 + delta_y; i < 8 + delta_y; i++)
			{
				for (int j = 0 + delta_x; j < 8 + delta_x; j++)
				{
					if (chess_w[i- delta_y][j-delta_x] != arr[i][j])
					{
						//cout << i << ": " << j << "체스 : " << chess_w[i][j] << " / 종이 : " << arr[i][j] << endl;
						rst_w_change++;
					}
				}

			}

			if (rst_min > rst_w_change)	 rst_min = rst_w_change;
			delta_x++; rst_w_change = 0;
		}

		delta_y++;
	}

	int cnt2 = (N - 7);
	delta_y = 0;
	while (cnt2-- > 0)
	{
		int delta_x = 0;
		int rst_w_change = 0;
		// chess_b 와 비교

		int m_cnt = M - 7;
		while (m_cnt-- > 0)
		{
			for (int i = 0 + delta_y; i < 8 + delta_y; i++)
			{
				for (int j = 0 + delta_x; j < 8 + delta_x; j++)
				{
					if (chess_b[i-delta_y][j- delta_x] != arr[i][j])
					{
						//if(delta_y ==1)
						//cout << i << ": " << j << "체스 : " << chess_b[i-delta_y][j-delta_x] << " / 종이 : " << arr[i][j] << endl;
						rst_w_change++;
					}
				}

			}

			if (rst_min > rst_w_change) rst_min = rst_w_change;
			delta_x++; rst_w_change = 0;
		}

		delta_y++;
	}


	cout << rst_min;
	return 0;
}
