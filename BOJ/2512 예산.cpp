#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, sum = 0;
	cin >> n;

	int* a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);

	cin >> m;

	int L = 0, R = a[n-1];
	
	if (sum <= m)
		cout << R << '\n';
	else
	{
		while (L + 1 < R)
		{
			int sum2 = 0;
			int mid = (L + R) / 2;
			
			for (int i = 0; i < n; i++)
			{
				if (a[i] >= mid) 
					sum2 += mid;
				else 
					sum2 += a[i];
			}

			if (sum2 > m)
				R = mid;
			else
				L = mid;
		}
		cout << L << '\n';
	}

	return 0;
}
