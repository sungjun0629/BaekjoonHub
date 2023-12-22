#include<iostream>
#include<stack>
#include<queue>
#include<deque>
using namespace std;

int N; int arr[100005]; int A; deque<int> dq;
int M;
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		arr[i] = A;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> A;
		// 스택이라면 들어갔던 수가 나오므로 continue
		// 큐라면 기존에 있던 수가 나오므로 기존에 있던 숫자랑 체인지
		// 따라서 스택은 무시하고 큐에 해당하는 부분을 덱으로 만들어줘서
		// 밀어내기를 해준다. 
		if (arr[i] == 0) dq.push_back(A);
	}

	// 밀어내기
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A;
		dq.push_front(A);
		cout << dq.back() << " ";
		dq.pop_back();
	}

	return 0;
}