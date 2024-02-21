#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int t;  int n, m; int temp;
vector<int > A, B; 
int main()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		A.clear(); B.clear();
		cin >> n >> m;
		int ret = 0;
		// A를 입력받는다.
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			A.push_back(temp);
		}

		// B를 입력받는다. 
		for (int k = 0; k < m; k++)
		{
			cin >> temp;
			B.push_back(temp);
		}

		// B를 정렬시킨다.(오름차순)
		sort(B.begin(), B.end());

		// A를 기준으로 순회한다.
		for (int i = 0; i < n; i++)
		{
			int k = A[i];
			auto iter = lower_bound(B.begin(), B.end(), k);
			ret += iter - B.begin();
			//cout << iter - B.begin() << endl;
		}
		
		cout << ret << endl;

	}

	

}