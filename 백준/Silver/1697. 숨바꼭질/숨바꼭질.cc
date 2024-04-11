#include <iostream>
#include <queue>
using namespace std;

int n, k, min_value = 100001;
int min_sec[100001];

void bfs(int x) {
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == k) {
			cout << min_sec[cur];
			return;
		}

		if (cur < 0 || cur > 100000) continue;

		if (cur - 1 >= 0 && !min_sec[cur - 1]) {
			q.push(cur - 1);
			min_sec[cur - 1] = min_sec[cur] + 1;
		}

		if (cur + 1 <= 100000 && !min_sec[cur + 1]) {
			q.push(cur + 1);
			min_sec[cur + 1] = min_sec[cur] + 1;
		}

		if (cur * 2 <= 100000 && !min_sec[cur * 2]) {
			q.push(cur * 2);
			min_sec[cur * 2] = min_sec[cur] + 1;
		}
	}
}

int main() {
	cin >> n >> k;

	bfs(n);

	return 0;
}