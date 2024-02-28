#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int l, c; 
vector<char> vc;

bool check(vector<char> v)
{
	int j = 0;
	bool m = false;

	for (char i : v)
	{
		if (i == 'a' || i == 'e' || i == 'o' || i == 'i' || i == 'u')
		{
			m = true;
		}
		else
		{
			j++;
		}
	}

	return (j >= 2) && m;
}


void combi(int idx, vector<char> v)
{

	if (v.size() == l)
	{
		if(check(v))
		{
			string str = "";
			for (char i : v)
			{
				str += i;
			}
			cout << str << '\n';
		}
	}


	for (int i = idx +1; i < c; i++)
	{
		v.push_back(vc[i]);
		combi(i, v);
		v.pop_back();

	}
}

int main()
{
	cin >> l >> c;
	for (int i = 0; i < c; i++)
	{
		char t; cin >> t; vc.push_back(t);
	}

	sort(vc.begin(), vc.end());
	vector<char> v;
	combi(-1, v);

}