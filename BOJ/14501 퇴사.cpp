#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
vector<pair<int, int>> v(20);
int n;

void solve(int x, int sum);

int main()
{
	cin >> n;
  
	for (int i = 1; i <= n; i++)
	{
		int a, b; cin >> a >> b;
		v[i] = make_pair(a, b);
	}

	for (int i = 1; i <= n; i++)
	{
		if (i + v[i].first - 1 > n) continue;
		solve(i, v[i].second);
	}

	cout << ans;

	return 0;
}


void solve(int x, int sum)
{

	if (sum > ans) ans = sum;
	if (x == n) return;

	for (int i = x + 1; i <= n; i++)
	{
		if (x + v[x].first - 1 >= i) continue;
		if (i + v[i].first - 1 > n) continue;
    
		solve(i, sum + v[i].second);
	}

	return;
}
