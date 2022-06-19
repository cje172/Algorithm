#include <iostream>
using namespace std;

int main()
{
	int a, b, count = 1;
	bool flag = false;
	
	cin >> a >> b;

	while (a < b && !flag)
	{
		if (b % 2 == 0)
		{
			b /= 2;
			count++;
		}
		else if (b % 10 == 1)
		{
			b /= 10;
			count++;
		}
		else 
			flag = true;
	}

	if (a == b) 
		cout << count;
	else 
		cout << -1;

	return 0;
}
