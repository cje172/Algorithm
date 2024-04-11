#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited1[1001];
bool visited2[1001];
vector<int> graph[1001];

void dfs(int x) {
	visited1[x] = true;

	cout << x << ' ';
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited1[y]) {
			dfs(y);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited2[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		cout << x << ' ';
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited2[y]) {
				q.push(y);
				visited2[y] = true;
			}
		}
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(V);
	cout << '\n';
	bfs(V);

	return 0;
}