#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int N,s,e; vector<int> sosu; 
int che[4000001];
int ret; int sum;

int main()
{
	cin>>N;
	
	//에라토스테네스의 체
	for (int i = 2; i <= sqrt(N); i++)
	{
		if(che[i]) continue;
		for (int j = i * i; j <= N; j += i)
		{
			che[j] = true;
		}
	}
	
	for (int i = 2 ; i<=N; i++)
	{
		if(!che[i]) {
		sosu.push_back(i);
		//cout<< i << ",";
		}
	}

	sosu.push_back(0);
	
	// 투 포인터 
	// s = vector의 앞 부분
	// e = vector의 뒷 부분 

	while (true)
	{
		if(sum >= N) sum -= sosu[s++];
		else if(e==sosu.size()-1) break;
		else if(sum < N) sum += sosu[e++];
		if(sum == N) {
			ret++;
			//cout<< "s : "<<sosu[s]<<", e : "<<sosu[e]<<'\n';
		}

	}

	cout<<ret;
}