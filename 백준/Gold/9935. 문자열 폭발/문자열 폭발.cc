#include<iostream>
#include<string>
using namespace std;

string s; string bomb;
string rst; int sLen;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> bomb;
	sLen = s.size();

	// 배열에 문자열 하나씩을 담는다. 
	// 담은 후 문자열 끝에서부터 비교
	// 그것을 제외하고 다시 담는다.  
	int idx = 0;
	while (true)
	{
		if (idx >= sLen) break;

		if (rst.size() < bomb.size())
		{
			rst += s[idx++];
		}
		// 비교를 한다.
		else
		{
			if (rst.substr(rst.size() - bomb.size(), bomb.size()) == bomb)
			{
				rst.erase(rst.end() - bomb.size(), rst.end());
			}
			else 
			{
				rst += s[idx++];
			}
		}
		
	}

	if (rst.size() >= bomb.size() && rst.substr(rst.size() - bomb.size(), bomb.size()) == bomb)
	{
		rst.erase(rst.end() - bomb.size(), rst.end());
	}


		 
	if (rst.size())
	{
		cout << rst;
	}
	else
	{
		cout << "FRULA";
	}
	return 0;
}