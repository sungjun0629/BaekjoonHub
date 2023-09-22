#include <iostream>

using namespace std;

string str, bomb;
string ret;

int main()
{
	cin>>str>>bomb; 

	for(int i = 0 ; i<str.size(); i++)
	{

		string compartStr;
		if (ret.size() < bomb.size())
		{
			ret += str[i];
			//cout<<"추가 : "<<ret<<endl;
		}
		else {

			compartStr	= ret.substr(ret.size()-bomb.size(), bomb.size());
			//cout<<"Parsing : "<< compartStr<<endl;

			if (compartStr == bomb)
			{
				ret.erase(ret.end() - bomb.size(), ret.end());
			}
			ret += str[i];
		}
	}

	if(ret.size()>=bomb.size())
	{
		string compartStr = ret.substr(ret.size() - bomb.size(), bomb.size());
		//cout << "Parsing : " << compartStr << endl;

		if (compartStr == bomb)
		{
			ret.erase(ret.end() - bomb.size(), ret.end());
		}
	}

	if(!ret.size()) ret = "FRULA";
	cout<<ret;

}