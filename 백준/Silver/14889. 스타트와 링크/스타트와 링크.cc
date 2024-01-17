#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



int n, r; int t;
int info[22][22];
int all; int temp; int ret = 999999999;
vector<int> vec;


void combi(int start, vector<int> b)
{
	temp = 0;
	if (b.size() == r)
	{
		// 팀원의 능력치를 더해준다. 
		for (int i = 0; i < b.size(); i++)
		{
			for (int j = i + 1; j < b.size(); j++)
			{
				temp += info[b[i]][b[j]]; temp += info[b[j]][b[i]];
			}
		}

		// 능력치 쌍의 합을 넣어준다.  
		vec.push_back(temp);
		return;
	}

	for (int i = start+1; i < n; i++)
	{
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
}


int main()
{
	cin >> n; r = n / 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> t;
			info[i][j] = t;
			all += t;
		}
	}

	vector<int> b;
	// 조합을 통해 팀을 만들어준다. 
	combi(-1, b);

	for (int i = 0; i < vec.size(); i++)
	{
		int k;

		// 서로 다른 팀 2개의 능력치 차이를 구한다.
		k = abs(vec[i] - vec[vec.size() - 1 - i]);

		ret = min(k, ret);
	}

	cout << ret;
}