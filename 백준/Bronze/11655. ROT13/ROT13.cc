#include<iostream>
#include<vector>
#include<string>
using namespace std;

string ROT13(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = (char)(s[i] + 13);
            if (s[i] > 'Z') {
                s[i] = (char)(s[i] - 26);
            }
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            if ((s[i]+13)>122) {
                s[i] = (char)(s[i] - 13);
            }
            else {
                s[i] = (char)(s[i] + 13);
            }
        }
    }
    return s;
}

int main()
{
    string a;
    getline(cin, a);

    string ab = ROT13(a);
    cout << ab;
}