#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;
const int INF = 987654321;
int n, mp, mf, ms, mv; int cost = INF;

struct A
{
	// 단백질, 지방, 탄수화물, 비타민, 가격
	int p, f, s, v, c;
} stra;

vector<A> info; 
// 식재료 순서를 넣는다. 
vector<vector<int>> a;
map<int, vector<vector<int>>> map_;

int main()
{
	cin >> n;
	// 최소 영양 성분
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++)
	{
		// 각각을 벡터에 집어 넣는다. 
		cin >> stra.p >> stra.f >> stra.s >> stra.v >> stra.c;
		info.push_back(stra);
	}

	// 조건을 만족시키면서도 비용이 최소가 되야 한다.
	// 6C1, 6C2, 6C3, 6C4 ... 등을 모두 구현해야 한다.
	// -> 비트마스킹을 이용한다!
	// 여섯자리 비트 111111
	for (int i = 0; i < pow(2,n); i++)
	{
		int mp_a = 0;
		int mf_a = 0;
		int ms_a = 0;
		int mv_a = 0;
		int cost_a = 0;
		vector<int> temp;

		// 인덱스가 켜져 있는 것을 확인한다. 
		for (int j = 0; j < n; j++)
		{
			// 인덱스가 켜져있다면
			if (i & (1 << j))
			{
				// 해당 정보를 확인한다. 
				mp_a += info[j].p;
				mf_a += info[j].f;
				ms_a += info[j].s;
				mv_a += info[j].v;
				cost_a += info[j].c;
				temp.push_back(j+1);
			}
		}

		// 최소 조건에 만족한다면
		if (mp_a >= mp && mf_a >= mf && ms_a >= ms && mv_a >= mv)
		{
			if (cost_a <= cost)
			{
				temp.push_back(cost_a);
				a.push_back(temp);
			}
			cost = min(cost_a, cost);
		}
	}

	if (cost == INF) cout << -1 << '\n';
	else
	{
		cout << cost << '\n';

		sort(a.begin(), a.end());
		// 같은 비용의 집합이 하나 이상이면
		// 사전 순으로 가장 빠른 것을 출력한다. 
		for (int i = 0; i < a.size(); i++)
		{
			if (*(a[i].end() - 1) == cost)
			{
				for (int j = 0; j < a[i].size() - 1; j++)
				{
					cout << a[i][j] << " ";
				}
                // 출력을 했으면 끝!
				return 0;
			}
		}

	}

	return 0;
}