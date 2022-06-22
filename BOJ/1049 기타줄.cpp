#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, p, q, x = 1000, y = 1000; 
	int max = 1000;
	int sum1 = 0, sum2 = 0;
	int a, b, t, j;

	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		cin >> p >> q;
		
		a = (x > p) ? p : x;
		b = (y > q) ? q : y;
		x = a;
		y = b;
	}

	if (n <= 6)
	{
		sum1 = x;
		sum2 = n * y;
	}
	else if (n > 6)
	{
		if (n % 6 == 0)
		{
			t = (n / 6) * x + (n % 6) * y;
			j = (n / 6) * x + x;
			sum1 = (t > j) ? j : t;
			sum2 = n * y;
		}
		else if (n % 6 != 0)
		{
			t = (n / 6) * x + (n % 6) * y;
			j = (n / 6) * x + x;
			sum1 = (t > j) ? j : t;
			sum2 = n * y;
		}
	}

	cout << min(sum1, sum2);

	return 0;
}
