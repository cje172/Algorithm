#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int t, n, a, b;
	int rank[100001];

	cin >> t;

	while (t--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			rank[a] = b;
		}

		int ans = 1;
		int tmp = rank[1];

		for (int i = 2; i <= n; i++)
		{
			if (rank[i] < tmp)
			{
				tmp = rank[i];
				ans++;
			}
		}
		cout << ans << '\n';
	}
}
