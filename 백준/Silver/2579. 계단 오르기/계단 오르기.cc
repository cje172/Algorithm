#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> stair(n + 1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> stair[i];

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = stair[3] + max(stair[1], stair[2]);

	for (int i = 4; i <= n; i++) {
		dp[i] = stair[i] + max(dp[i - 2], stair[i - 1] + dp[i - 3]);
	}

	cout << dp[n];

	return 0;
}