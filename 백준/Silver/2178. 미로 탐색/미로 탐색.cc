#include <iostream>
#include <string>
#include <queue>
using namespace std;

int map[100][100];
int dist[100][100];
bool visited[100][100];

int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	dist[y][x] = 1;

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m)
				continue;
			if (visited[next_y][next_x] || !map[next_y][next_x])
				continue;

			q.push({ next_y, next_x });
			visited[next_y][next_x] = true;
			dist[next_y][next_x] = dist[cur_y][cur_x] + 1;
		}
	}
	cout << dist[n - 1][m - 1];
}

int main() {
	cin >> n >> m;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < m; j++)
			map[i][j] = s[j] - '0';
	}

	bfs(0, 0);

	return 0;
}