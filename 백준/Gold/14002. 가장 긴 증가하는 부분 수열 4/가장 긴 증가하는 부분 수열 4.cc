#include<iostream>
#include<stack>

using namespace std;


int a;
int arr[1004], cnt[1004], prev_[1004];
int max_cnt = -2, trace_idx = -1;
stack<int> stk;

int main()
{
	cin >> a;

	// prev -1을 초기화
	fill(prev_, prev_+1004, -1);

	for (int i = 0; i < a; i++)
	{
		cin >> arr[i];
	}

	// 하나를 pivot하고 0번째 인덱스부터 비교를 하면서 온다.
	for (int i = 0; i < a; i++)
	{
		// 0번째 인덱스는 스킵되겠지.
		for (int j = 0; j <= i; j++)
		{
			// 증가하는 수열이기 때문에, 그리고 연결된 부분이(cnt가 크다) 많이 있으면 좋다. -> 최대값을 찾는것이기 떄문 
			if (arr[i] > arr[j] && cnt[i] <= cnt[j]  )
			{
				// 조건에 부합한다면, 그 수에 연결해준다.
				cnt[i] = cnt[j] + 1;
				prev_[i] = j;

			}
			// 그리고 제일 긴 수열을 갖고 있는 부분인지 확인을 한다.
			// 추후 print를 하기 위해서 => trace
			if (max_cnt < cnt[i]) {
				trace_idx = i;
				max_cnt = cnt[i];
			}
		}
	}

	cout << cnt[trace_idx]+1 << endl;

	for (int i = trace_idx; i!=-1 ; i =prev_[i])
	{
		stk.push(arr[i]);
	}
	int stk_size = stk.size();
	for (int i = 0; i <stk_size; i++)
	{
		cout << stk.top() << " ";
		stk.pop();
	}


	return 0;
}