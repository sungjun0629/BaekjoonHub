#include<iostream>
using namespace std;

int a, b, c, d, e, f;

int main() {
	cin >> a >> b >> c >> d >> e >> f;
	
	for (int i = -999; i < 1000; i++)
	{
		for (int j = -999; j < 1000; j++)
		{
			if (d * i + e * j == f && a * i + b * j == c)
			{
				cout << i << " " << j << endl;
			}
		}
	}
}