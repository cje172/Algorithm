#include <iostream>
#include <queue>
using namespace std;

int M, N, H, day;
int box[101][101][101];
int date[101][101][101];
bool visited[101][101][101];

int dx[] = { 1, 0, -1, 0, 0, 0 };
int dy[] = { 0, 1, 0, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

struct tomato {
	int z;
	int y;
	int x;
};
queue<tomato> q;

void bfs() {
	while (!q.empty()) {
		int curZ = q.front().z;
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nextZ = curZ + dz[i];
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			if (nextZ < 0 || nextZ >= H || nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
				continue;
			if (visited[nextZ][nextY][nextX] || box[nextZ][nextY][nextX] != 0)
				continue;

			q.push({ nextZ , nextY ,nextX });
			visited[nextZ][nextY][nextX] = true;
			box[nextZ][nextY][nextX] = 1;
			date[nextZ][nextY][nextX] = date[curZ][curY][curX] + 1;
			if (day < date[nextZ][nextY][nextX])
				day = date[nextZ][nextY][nextX];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[i][j][k];

				if (box[i][j][k] == 1) {
					q.push({ i, j, k });
				}
			}
		}
	}

	bfs();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << day;

	return 0;
}