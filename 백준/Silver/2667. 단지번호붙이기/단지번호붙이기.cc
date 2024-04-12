#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> answer;
int n, cnt;
int map[25][25];
bool visited[25][25];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int y, int x) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];

		if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n)
			continue;
		if (visited[next_y][next_x] || !map[next_y][next_x])
			continue;

		cnt++;
		dfs(next_y, next_x);
	}
}

int main() {
	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < n; j++)
			map[i][j] = s[j] - '0';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j]) {
				cnt = 1;
				dfs(i, j);
				answer.push_back(cnt);
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (int item : answer)
		cout << item << '\n';

	return 0;
}