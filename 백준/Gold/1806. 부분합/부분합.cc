#include<iostream>
#include<vector>
using namespace std;

int N, S, temp; int min_length = 100005;
vector<int> vec;
int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}

	auto left = vec.begin();
	auto right = vec.begin();
	int sum = *left;

	while (true)
	{
		if (sum >= S)
		{
			//cout << right - left << endl;
			if (min_length > right - left)
			{
				min_length = right - left + 1;
			}

			sum -= *left;
			left++; 

		}
		else if (sum < S)
		{
			right++;
			if (right == vec.end()) break;
			sum += *right;
		}
	}

	if (min_length == 100005) cout << 0 << endl;
	else cout << min_length << endl;
}