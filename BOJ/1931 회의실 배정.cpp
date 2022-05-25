#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>x, pair<int, int>y)
{
	if (x.second == y.second)
		return x.first < y.first;
	else
		return x.second < y.second;
}

int main() {
	int ans = 0;
	int N;
	vector<pair<int, int>> list;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		list.push_back({ start, end });
	}

	sort(list.begin(), list.end(), cmp);

	int cur = 0;
	int idx = 0;
	while (idx < N)
	{
		for (int i = idx; i < N; i++)
		{
			idx++;
			if (list[i].first >= cur)
			{
				cur = list[i].second;
				ans++;
				break;
			}
		}
	}
	cout << ans << '\n';
}
