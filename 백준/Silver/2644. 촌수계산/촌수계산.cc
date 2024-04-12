#include <iostream>
#include <vector>
using namespace std;

int n, m, p1, p2, x, y, answer;
vector<int> graph[101];
bool visited[101];

void dfs(int cnt, int p1) {
	visited[p1] = true;

	if (p1 == p2) {
		answer = cnt;
		return;
	}

	for (int i = 0; i < graph[p1].size(); i++) {
		int next = graph[p1][i];
		if (!visited[next]) {
			dfs(cnt + 1, next);
		}
	}
}

int main() {
	cin >> n >> p1 >> p2 >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(0, p1);

	if (!answer) cout << -1;
	else cout << answer;

	return 0;
}