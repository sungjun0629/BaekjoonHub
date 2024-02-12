#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dice_rst[12]; int mal[4];
// 말판은 두 개로 분기할 수 있다.(파란색)
vector<int> malPan[60]; int panScore[104];


void add(int idx, int next_idx)
{
	malPan[idx].push_back(next_idx);
}

void add_ele(int idx, int value)
{
	panScore[idx] = value;
}

void makeMalPan()
{
	// 일방향 
	for (int i = 0; i < 20; i++)
	{
		// 0 -> 1 , 1 -> 2 , ... 19 ->20 idx를 가리킨다.
		malPan[i].push_back(i + 1);
		// 크기는 2씩 증가한다. 
		panScore[i] = i * 2;
	}

	// 도착 지점
	add(20, 100); 

	// 분기되어 만들어지는 맵을 만든다. 
	add(5, 35); add(35, 36); add(36, 37); add(37, 38);
	add(38, 39); add(39, 40); add(40, 20);

	add(10, 50); add(50, 51); add(51, 38);
	add(15, 55); add(55, 56); add(56, 57); add(57, 38);

	// 원소 값을 넣어준다. 
	add_ele(20, 40);
	add_ele(35, 13); add_ele(36, 16); add_ele(37, 19); add_ele(38, 25);
	add_ele(39, 30); add_ele(40, 35);

	add_ele(50, 22); add_ele(51, 24);

	add_ele(55, 28); add_ele(56, 27); add_ele(57, 26);

}

// 현재 말의 위치와 주사위 결과를 넣어준다.
int move(int current_idx, int cnt)
{
	if (current_idx == 100) return 100;
	// 현재 위치가 분기할 수 있는 지점이라면
	// 분기를 한다. 
	if (malPan[current_idx].size() >= 2)
	{
		current_idx = malPan[current_idx][1]; cnt--;
	}


	// 만약 더 이동할 수 있는 주사위 값이라면 
	if (cnt)
	{
		// 한 칸씩 이동을 수행한다.
		// 인덱스를 초과하는 경우를 막기 위해
		queue<int> q;
		q.push(current_idx);

		while (true)
		{
			current_idx = q.front(); q.pop();
			int there = malPan[current_idx][0];
			// 만약 도착지점에 왔다면.
			if (there == 100) return 100;
			cnt--; q.push(there);
			if (cnt == 0) return there;
		}
	}
	return current_idx;

}

bool malCheck(int check_idx)
{
	// 도착지점은 조건에서 예외이다. 
	if (check_idx == 100) return false;

	for (int i = 0; i < 4; i++)
	{
		// 옮겨질 말판에 누군가 존재할 때
		if (check_idx == mal[i])
			return true;
	}

	return false;
}


int go(int cnt)
{
	// 기저조건
	// 10번의 주사위 값을  처리
	if (cnt == 10) return 0;

	int ret = 0;
	// 4개의 말을 처리한다. 
	for (int i = 0; i < 4; i++)
	{
		// 옮길 말의 현재 위치를 받는다.
		int temp_idx = mal[i];
		// 말을 이동시킨 후의 위치를 받는다.
		int move_idx = move(temp_idx, dice_rst[cnt]); 
		// 조건에 부합하는지 확인을 한다. 
		if(malCheck(move_idx)) continue;
		// 다른 주사위 연산을 진행한다. 
		mal[i] = move_idx;
		ret = max(ret, go(cnt + 1) + panScore[move_idx]);
		// 옮긴 말의 위치를 원복시킨다. 
		mal[i] = temp_idx;

	}

	return ret;
}


int main()
{
	makeMalPan();
	// 주사위 값 입력
	for (int i = 0; i < 10; i++) cin >> dice_rst[i];


	// 완전탐색을 통해
	// 말을 움직일 수 있는 모든 경우의 수를 돌린다. 
	// 재귀로 구현
	cout << go(0);
}