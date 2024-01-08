#include<iostream>
#include <string>
#include <queue>
using namespace std;

int k;
char t;  char arr[12];
string max_rst;
string min_rst;


int main()
{
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> t;
		arr[i] = t;
	}


	// 최소와 최대를 출력해야 한다. 
	// 최소는 0,1,2,3,4,... 순으로 
	// 최대는 9,8,7,6,5... 순으로 
	
	// 최대일 때
	// > 가 나오면 가장 큰 수를 넣어주면 된다.
	// < 가 나오면 >가 나올 때까지 
	// 가장 큰 수 - i을 넣어주면 된다.
	int max_num = 9;
	int adj_max = 0;
	for (int i = 0; i <= k; i++)
	{
		t = arr[i];

		int idx = i + 1;
		int adj = 1;
		if (t == '<')
		{
			adj_max++;
			while (arr[idx] == '<')
			{
				if(idx == k) break;
				idx++;
				adj++;
			}
			max_rst += to_string(max_num - adj);
			continue;
		}
		else
		{
			max_rst += to_string(max_num--);
			max_num -= adj_max;
			adj_max = 0;
		}

	}

	/*if (adj_max != 0)
	{
		max_rst += to_string(max_num--);
	}*/


	int min_num = 0;
	int adj_min = 0;
	for (int i = 0; i <= k; i++)
	{
		t = arr[i];

		int idx = i + 1;
		int adj = 1;
		if (t == '>')
		{
			adj_min++;
			while (arr[idx] == '>')
			{
				if (idx == k) break;
				idx++;
				adj++;
			}
			min_rst += to_string(min_num + adj);
			continue;
		}
		else
		{
			min_rst += to_string(min_num++);
			min_num += adj_min;
			adj_min = 0;
		}

	}

	/*if (adj_min != 0)
	{
		min_rst += to_string(min_num++);
	}*/

	cout << max_rst << endl;;
	cout << min_rst << endl;;

}