#include<iostream>
#include<vector>
using namespace std;

int is_su = 0;
int index = -1;
int main() {

    int c;
    cin >> c;
    vector<int> count(30);

    for (int i = 0; i < c; i++)
    {
        string n;
        cin >> n;
        count[(int)n[0] - 97]++;
    }

    for (int c : count)
    {
        index++;
        if (c >= 5) {
            cout << (char)(index+97);
            is_su++;
        }
    }

    if (is_su == 0) {
        cout << "PREDAJA";
    }
}