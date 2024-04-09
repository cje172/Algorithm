#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, num;
	cin >> n;

	vector<int> wine(n + 1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max({ dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i], dp[i - 1] });
	}

	cout << dp[n];

	return 0;
}