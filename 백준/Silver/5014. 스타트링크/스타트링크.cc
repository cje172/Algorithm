#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
int min_cnt[1000001];

void bfs(int x) {
	queue<int> q;
	q.push(x);
	min_cnt[x] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == g)
			return;

		if (cur + u <= f && min_cnt[cur + u] == 0) {
			q.push(cur + u);
			min_cnt[cur + u] = min_cnt[cur] + 1;
		}
		if (cur - d >= 1 && min_cnt[cur - d] == 0) {
			q.push(cur - d);
			min_cnt[cur - d] = min_cnt[cur] + 1;
		}
	}
}

int main() {
	cin >> f >> s >> g >> u >> d;

	bfs(s);

	if (min_cnt[g])
		cout << min_cnt[g] -1;
	else
		cout << "use the stairs";

	return 0;
}