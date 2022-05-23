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

	for (int i = 1; k > 0; i++)
	{
		count += k / a[n - i];
		k = k % a[n - i];
	}

	cout << count;
	
	return 0;
}
