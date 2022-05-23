#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int a[10];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int count = 0;
	int i = 1;

	while (i <= n - 1 || k != 0)
	{
		if (k < 5)
		{
			count += k;
			break;
		}
		else if (k / a[n - i] != 0)
		{
			count += k / a[n - 1];
			k = k % a[n - 1];
		}
		i++;
	}

	cout << count;
	
	return 0;
}
