#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n, answer, min_value = 101, max_value = 0;
int map[101][101];
bool visited[101][101];

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

void bfs(int y, int x, int height) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n)
				continue;
			if (visited[next_y][next_x] || map[next_y][next_x] <= height)
				continue;

			q.push({ next_y, next_x });
			visited[next_y][next_x] = true;
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (min_value > map[i][j])
				min_value = map[i][j];

			if (max_value < map[i][j])
				max_value = map[i][j];
		}
	}

	for (int h = min_value - 1; h < max_value; h++) {
		int cnt = 0;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && map[i][j] > h) {
					bfs(i, j, h);
					cnt++;
				}
			}
		}
		answer = max(answer, cnt);
	}

	cout << answer;

	return 0;
}