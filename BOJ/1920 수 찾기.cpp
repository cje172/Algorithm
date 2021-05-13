#include <iostream>
#include <algorithm>
using namespace std;

bool binary_search(int* arr, int n, int value)
{
	int start = 0;
	int end = n - 1;
	int mid;

	while (end - start >= 0)
	{
		mid = (start + end) / 2;

		if (arr[mid] == value)
			return true;
		else if (arr[mid] > value)
			end = mid - 1;
		else 
			start = mid + 1;
	}
	return false;
}


int main()
{
	int n, m;
	cin >> n;
	
	int* a = new int[n];
	
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	
	cin >> m;
	
	int* b = new int[m];

	for (int i = 0; i < m; i++)
		cin >> b[i];
	
	for (int i = 0; i < m; i++)
		cout << binary_search(a, n, b[i]) << '\n';

	return 0;
}
