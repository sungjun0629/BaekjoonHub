#include<iostream>
#include<deque>

using namespace std;

int p, s; string str;
int acgt[100]; 
int sLength;
int a, c, g, t, cnt;

int main()
{
	cin >> p >> s >> str;
	cin >> a >> c >> g >> t;
	
	
	// 부분문자열을 확인한다.
	int left = 0; int right = 0;
	// 포인터를 통해 -> 한 번 확인한 것은 확인하지 않는다.
	// 포인터의 변환된 위치만 연산을 해준다.
	// 오른쪽 포인터를 통한 push, 왼쪽 포인터를 통한 pop을 수행한다.

	while (right < str.size())
	{
		while (sLength < s)
		{
			// DNA 문자를 확인한다.
			char c  = str[right++];
			// 해당하는 문자에 대한 개수를 증가시켜준다..
			acgt[c - 'A']+=1;
			sLength++;
		}

		// 조건에 맞을 때
		if ( a - acgt['A' - 'A']<= 0 && c- acgt['C' - 'A'] <= 0 && g- acgt['G' - 'A'] <= 0 && t -acgt['T' - 'A'] <= 0) {
			cnt++;
		}

		/*cout << a  - acgt['A' - 'A']  << " : " << c - acgt['C' - 'A']  << " : " << g - acgt['G' - 'A']  << " : " << t - acgt['T' - 'A']<< endl;*/

		// 왼쪽 포인터를 늘려주고 덱에서 먼저 넣은 것을 pop을 시켜준다.
		acgt[str[left] - 'A']-=1;
		left++; sLength--;
		
	}

	cout << cnt;
}