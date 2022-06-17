#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	string str;
	int zeroCnt = 0, oneCnt = 0;
	cin >> str;
	
  for (int i = 0; i < str.size() - 1; i++)
  {
		if (str[i] != str[i + 1])
			str[i] == '1' ? oneCnt++ : zeroCnt++;
	}
	
  str[str.size() - 1] == '1' ? oneCnt++ : zeroCnt++;
  
	cout << (zeroCnt <= oneCnt ? zeroCnt : oneCnt);
}
