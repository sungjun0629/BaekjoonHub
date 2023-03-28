#include<iostream>
#include<stack>
using namespace std;

int N;
int cnt;

int main() {

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        stack<char> stack1;
        string input;
        cin >> input;
        for(int j = 0 ; j<input.size(); j++)
        {
            if (!stack1.empty()  && stack1.top() == input[j]) {
                stack1.pop();
            }
            else
            {
                stack1.push(input[j]);
            }
        }

        if (!stack1.empty()) continue;
        cnt++;
    }
    cout << cnt;
    return 0;
}