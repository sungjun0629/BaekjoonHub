#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

string str;
int cnt = 0;
string answer;
string odd;
int main() {

    cin >> str;
    map<char, int> _map;
    for (int i = 0; i < str.size(); i++)
    {
        _map[str[i]] ++;
    }

    for (auto i : _map) {
        if (i.second % 2 == 1) {
            cnt++;
            i.second--;
            odd = i.first;
        }
        if (cnt > 1) {
            cout << "I'm Sorry Hansoo";
            exit(0);
        }
        else {
            while (i.second > 1) {
                answer += i.first;
                i.second = i.second - 2;
            }
        }
    }

    string temp = answer;
    if (cnt == 1) answer += odd;
    reverse(temp.begin(), temp.end());
    answer += temp;

    cout << answer;

}