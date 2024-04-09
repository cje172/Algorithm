#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[9];

void dfs(int cnt, int x, vector<int>& answer) {
	if (cnt == m) {
		for (int item : answer)
			cout << item << " ";
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			answer.push_back(i);

			dfs(cnt + 1, i, answer);

			visited[i] = false;
			answer.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	vector<int> answer;
	dfs(0, 1, answer);

	return 0;
}