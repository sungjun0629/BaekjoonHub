#include<iostream>
#include<vector>
using namespace std;

int main() {
    string a;
    cin >> a;
    vector<int> vec(26); 
    for (int i = 0; i < a.size(); i++)
    {
        vec[(int)a[i] - 97]++;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] <<' ';
    }

    return 0;
}