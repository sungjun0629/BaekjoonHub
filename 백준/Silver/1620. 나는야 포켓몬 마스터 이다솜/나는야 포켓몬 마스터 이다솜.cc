#include<iostream>
#include<map>
using namespace std;

map<string, int> mp;
map<int, string> mp2;
int N, M;
string temp, prob;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> temp;
        mp2[i] = temp;
        mp[temp] = i;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> prob;
        if (atoi(prob.c_str()) == 0)
        {
            cout << mp[prob] << '\n';
        }
        else
        {
            int index = atoi(prob.c_str());
            cout << mp2[index] << '\n';
        }
    }
}