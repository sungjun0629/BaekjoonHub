#include<iostream>
#include<algorithm>
using namespace std;

int temp;
int N, M;
int cnt = 0;
int arr[15001];
int main() {

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
    for (int i = 0 ; i< N ; i++)
    {
        auto it = find(begin(arr), end(arr), M - arr[i]);
        //cout << "arr의 배열은" << arr[i] << "이고, M-arr[i]" << it- begin(arr) << "번 째 존재합니다.";
        if(it- begin(arr) < N) cnt++;
    }

    cout << cnt / 2;
}