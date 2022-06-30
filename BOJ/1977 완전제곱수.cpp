#include <iostream>
using namespace std;

int main()
{
	int m;
	int n;
	int sum = 0;
	int min = 0;

	cin >> m;
	cin >> n;

	for (int i = m; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == j * j)
			{
				sum = sum + i;

				if (i != 0 && sum == i)
				{
					min = i;
				}
			}
		}
	}

	if (sum == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << sum << endl;
		cout << min << endl;
	}

	return 0;
}
