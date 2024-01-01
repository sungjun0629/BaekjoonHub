#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define prev aaa
#define next aaaa
const int max_n = 200004;
int visited[max_n], prev[max_n], n , k, here, ret;
vector<int> v;
queue<int> q;

int main() {
	cin >> n >> k;
	visited[n] = 1;
	q.push(n);

	while (q.size()) {
		here = q.front(); q.pop();
		// 기저조건
		if (here == k)
		{
			ret = visited[k];
			break;
		}
		// 큐에 넣어준다. 
		for (int next : {here + 1, here - 1, here * 2})
		{
			if(next>= max_n || next<0 || visited[next]) continue;
			visited[next] = visited[here] + 1;
			// Trace
			prev[next] = here;
			q.push(next);
		}
	}

	for (int i = k; i != n; i = prev[i])
	{
		v.push_back(i);
	}
	v.push_back(n);

	cout << ret - 1 << '\n';
	reverse(v.begin(), v.end());
	for (int i : v) cout << i << ' ';
	return 0;
}