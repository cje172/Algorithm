#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[101];
bool visited[101];
int cnt;

void dfs(int x) {
	visited[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		int next = graph[x][i];

		if (!visited[next]) {
			cnt++;
			dfs(next);
		}
	}
}

int main() {
	int n, m, num1, num2;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}

	dfs(1);
	cout << cnt;

	return 0;
}