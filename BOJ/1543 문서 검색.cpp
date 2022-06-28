#include <iostream>
#include <string>
using namespace std;

int main()
{
	string docuStr, findStr;

	getline(cin, docuStr);
	getline(cin, findStr);

	int cnt = 0;
	for (int i = 0; i < docuStr.length(); i++)
	{
		if (docuStr[i] == findStr[0])
		{
			for (int j = 0; j < findStr.length(); j++)
			{
				if (docuStr[i + j] != findStr[j])
				{
					break;
				}
				if (j == findStr.length() - 1) 
				{
					cnt++;
					i += findStr.length() - 1;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}
