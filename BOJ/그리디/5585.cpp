#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int change = 1000 - n;
	int count = 0;
	
	int coin[6] = { 500, 100, 50, 10, 5, 1 };

	for (int i = 0; i < 6; i++)
	{
		if (change >= coin[i])
		{
			count += change / coin[i];
			change %= coin[i];
		}
	}
	cout << count << '\n';

	return 0;
}
