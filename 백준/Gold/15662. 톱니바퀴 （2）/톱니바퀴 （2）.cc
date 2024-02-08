#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n, k; 
vector<int> topni; int ret;

// 자신이 기준이라면 loc = 0 , 왼쪽 방향의 톱니라면 1, 오른쪽 방향의 톱니라면 2
void rotate_topni(int topni_idx , int dir, int loc)
{
	// dir에 따라 자신을 먼저 돌린다. 
	// 시계 방향일 때 
	int k = topni[topni_idx];
	//cout << topni_idx + 1 << " : 기준이 회전한다" << endl;

	// loc == 0 이라면, 양쪽으로 전달한다. 
	if (loc == 0)
	{
		if (topni_idx < topni.size() - 1)
		{
			// 톱니가 같은지 체크를 한다.
			int right = topni[topni_idx + 1];
			int right_ns = (right>>1 & 1 );
			int ns = (k>>5 & 1 );
			if (ns != right_ns) {
				//cout << topni_idx + 1 << " : 오른쪽이 회전한다";
				//cout << endl;
				rotate_topni(topni_idx + 1, dir * -1, 2);
			}
		}
		if (topni_idx != 0)
		{
			int left = topni[topni_idx - 1];
			int left_ns = (left >> 5 & 1);
			int ns = (k >> 1 & 1);
			if (ns != left_ns) {
				//cout << topni_idx + 1 << " : 왼쪽이 회전한다";
				//cout << endl;
				rotate_topni(topni_idx - 1, dir * -1, 1);
			}
		}
	}
	// 왼쪽으로만 전달
	else if (loc == 1)
	{
		if (topni_idx != 0)
		{
			int left = topni[topni_idx - 1];
			int left_ns = (left>>5 & 1);
			int ns = (k>>1 & 1 );
			if (ns != left_ns) {
				//cout << topni_idx + 1 << ns<< ": " <<  left_ns <<" : 왼쪽이 회전한다";
				//cout << endl;
				rotate_topni(topni_idx - 1, dir * -1, 1);
			}
		}
	}
	else
	{
		if (topni_idx < topni.size() - 1)
		{
			// 톱니가 같은지 체크를 한다.
			int right = topni[topni_idx + 1];
			int right_ns = (right >> 1 & 1);
			int ns = (k >> 5 & 1);
			if (ns != right_ns) {
				//cout << topni_idx + 1 << " : 오른쪽이 회전한다";
				//cout << endl;
				rotate_topni(topni_idx + 1, dir * -1, 2);
			}

		}
	}

	// 회전시킨다.
	if (dir == 1)
	{
		// 최하위비트는 최상위로 가고 >> 연산을 수행한다. 
		int last_idx = (1 & k) ? 1 : 0;
		k >>= 1; 
		if (last_idx) k += pow(2, 7);
		topni[topni_idx] = k;
		//cout << k <<endl;
	}
	else
	{
		// 최상위 비트가 최하위 비트로 간다. 
		int first_idx = (1 & k>>7) ? 1 : 0;
		k <<= 1; 
		if (first_idx) {
			k -= pow(2, 8);
			k += 1;
		}
		topni[topni_idx] = k;
		//cout << k <<endl;
	}
}



int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		// 배열에 넣게 되면 rotate 시킬 때 
		// 1000번, 1000개의 톱니바퀴를 이동시켜야 한다. 
		// 이진수로 관리를 한다. 
		int sum = 0;
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			int t = str[j] - '0';
			if(t!=0) sum += pow(2, 7-j);
		}

		// 입력값을 이진수로 바꾸어 자료구조에 넣어준다. 
		topni.push_back(sum);
	}

	cin >> k;
	
	// 톱니 바퀴를 회전시킨다. 
	for (int i = 0; i < k; i++)
	{
		int topni_idx;
		int dir;

		// 같은 극이라면 회전하지 않고
		// 다른 극이라면 반대방향으로 회전을 한다. 
		cin >> topni_idx; topni_idx--;
		cin >> dir;

		// topni_idx를 기준으로 왼쪽 톱니의 [5], 자신의 [1]  
		// topni_idx를 기준으로 오른쪽 톱니의 [1], 자신의 [5]
		rotate_topni(topni_idx, dir, 0);

	}

	// 총 k번 회전시킨 이후에 12시 방향인 S극인 톱니바퀴의 개수를 출력
	// 최상위비트 
	for (int i : topni)
	{
		//cout << "탐색" << endl;
		//cout << i << endl;
		if (i>>7 & 1) ret++;
	}

	cout << ret;
	

}