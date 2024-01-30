#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


int n; char t; int cnt_back;
vector<int> vec; 
vector<int> str; 
int temp_rst = 987654321;

// T가 되는 비트의 개수를 구한다. 
// 만약 H>T라면 flip을 수행한다. 
int check_bit(vector<int> b , int bit_idx)
{
	int sum = 0;
	for (int i = 0; i < b.size(); i++)
	{
		// 열에 해당하는 비트의 검사 

		// 해당 비트가 켜져 있다면 -> 0 이 되므로 좋다.
		if (b[i] & (1 << bit_idx))	sum--;
		// 해당 비트가 꺼져 있다면 
		else sum++;
	}

	return sum;
}


int flip_bit(int b)
{
	int i = 0;
	while (i<n)
	{
		// 만약 비트가 1이라면 꺼진다.
		if (b & 1 << i) cnt_back--;
		// 만약 비트가 0이라면 켜진다.
		else cnt_back++;
		// toggle을 수행한다. (XOR)
		b ^= 1 << i++;
		//cout << i-1<<"번 idx의 " << "b의 토글 결과" << b << endl;
	}

	return b;

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> t;
			// 배열로 만들어주면 공간복잡도가 너무 크기 때문에
			// 비트마스킹을 활용한다. 
			if(t == 'T') {
				sum += 1 << (n-j-1);
				cnt_back++;
			}
		}
		vec.push_back(sum);
		str.push_back(sum);
	}

	// 한 행 또는 한 열에 놓인 N개의 동전을 뒤집는 작업 수행
	// 1개의 행과 1개의 열만 뒤집는다
	// 가지수 : 20 * 20 = 400개 

	// 뒤집을 행에 대한 경우를 비트로 확인을 한다.  
	for (int b = 0; b < pow(2, n); b++)
	{
		// 켜져 있는 비트를 확인한다. 
		int temp_cnt = cnt_back;
		for (int i = 0; i < n ; i++)
		{
			// 현재 비트가 켜져 있다면 즉, 뒤집어야 한다면.
			if(b & (1 << i))
			{
				int temp = vec[i];
				// 행에 대한 flip을 수행한다.
				vec[i] = flip_bit(vec[i]);
			}
		}

		int flip_sum = 0;
		// 열에 대한 flip을 수행한다. -> 개수만 파악을 한다.
		for (int j = 0; j < n; j++)
		{
			int tt = check_bit(vec, j);
			// 뒤집기를 수행한다. 
			if (tt < 0)
			{
				flip_sum += tt;
			}
		}
		//cout << b << " : " << flip_sum << endl;
		temp_rst = min(temp_rst, flip_sum + cnt_back);
		// 원복을 한다. 
		for (int i = 0 ; i<str.size(); i++)
		{
			vec[i] = str[i];
		}
		cnt_back = temp_cnt;
	}
	cout << temp_rst;
}