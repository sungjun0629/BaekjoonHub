#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int n; vector<int> arr; int cnt;
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t; arr.push_back(t);
	}

	// 두 개의 합 -> 2000 * 1999 = 4,000,000

	// 원소는 오름차순 정렬하므로 
	sort(arr.begin(), arr.end());
	// 합으로 이루어지기 위해서는 원소보다 작은 위치의 원소들이
	// 더해져야 한다. 
	// 1 2 3 4 5 6 7 
	// 4를 만들기 위해서는 1 2 3 의 조합으로 이루어져야 한다. 

	// 예외) 음수도 존재한다. 
	// -4 -3 -1 3 4 
	for (int i = 0; i < n; i++)
	{
		int elem = arr[i];
		int left = 0; 
		int right = arr.end()-arr.begin()-1;
		if (left == i) left++; if (right == i) right--;

		while (left < right)
		{
			// 자기 자신은 제외한다.
			int sum = arr[left] + arr[right];
			if (sum < elem)	left++;
			else if (sum > elem) right--;
			else
			{
				//cout << elem << "와 같은 수 확인 : " << left << " : " << right << endl;
				cnt++; break;
			}
			if (left == i) left++; if (right == i) right--;
		}
	}

	cout << cnt;

}