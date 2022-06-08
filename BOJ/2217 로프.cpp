#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int w[100000];
	for (int i = 0; i < n; i++)
		cin >> w[i];

	sort(w, w + n, greater<int>());

	int maxValue = 0;
	for (int i = 0; i < n; i++)
		maxValue = max(maxValue, w[i] * (i + 1));

	cout << maxValue;

	return 0;
}
