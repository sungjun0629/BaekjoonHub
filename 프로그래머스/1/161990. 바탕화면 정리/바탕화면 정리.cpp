#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int min_x = 100 , max_x = -1 , min_y = 100 , max_y = -1;
int sizeOfWall;
// 최소한의 이동거리를 갖는 드래그
vector<int> solution(vector<string> wallpaper) {
	vector<int> answer;

	// 바탕화면의 정보를 2차원 배열로 옮겨준다.
	/*int idx = 0;
	for (string s : wallpaper)
	{
		sizeOfWall = s.size();
		for (int i = 0; i < s.size(); i++)
		{
			wallPaper[idx][i] = s[i];
		}
		idx++;
	}*/

	// 최대의 범위를 갖기 위해서는
	// 최외곽에 있는 파일의 정보를 봐야한다
	for (int i = 0; i < wallpaper.size(); i++)
	{
		for (int j = 0; j < wallpaper[i].size(); j++)
		{
			if (wallpaper[i][j] == '#')
			{
				// 좌측변
				min_x = min(min_x, j);
				// 우측변
				max_x = max(max_x, j + 1);
				// 상단변
				min_y = min(min_y, i);
				// 하단변
				max_y = max(max_y, i+1);
			}
		}
	}

	//cout << min_y << min_x << max_y << max_x << endl;
	answer.push_back(min_y);
	answer.push_back(min_x);
	answer.push_back(max_y);
	answer.push_back(max_x);
	return answer;
}