#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
string max_value, min_value;
char ch[9];


void dfs(int cnt, int x, string s, vector<bool>& visited) {
	if (cnt == n) {
		max_value = max(max_value, s);
		min_value = min(min_value, s);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (!visited[i]) {
			if (ch[cnt] == '<' && (x < i)) {
				visited[i] = true;
				dfs(cnt + 1, i, s + to_string(i), visited);
				visited[i] = false;
			}
			else if (ch[cnt] == '>' && (x > i)) {
				visited[i] = true;
				dfs(cnt + 1, i, s + to_string(i), visited);
				visited[i] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i <= n; i++) {
		max_value += '0';
		min_value += '9';
	}

	for (int i = 0; i < n; i++)
		cin >> ch[i];

	for (int i = 0; i <= 9; i++) {
		vector<bool> visited(10, false);
		visited[i] = true;
		dfs(0, i, to_string(i), visited);
	}

	cout << max_value << '\n' << min_value;

	return 0;
}