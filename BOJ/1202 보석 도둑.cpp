#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int m, v;
vector <pair<int, int> > jewel;
long long c[300001];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		jewel.push_back(make_pair(m, v));
	}

	for (int i = 0; i < k; i++)
	{
		cin >> c[i];
	}
}

bool sortJewel(const pair<int, int> &a, const pair<int, int> &b)
{
	if (a.first != b.first)
	{
		return a.first < b.first;
	}
	return a.second > b.second;
}

void solve()
{
	sort(jewel.begin(), jewel.end(), sortJewel);
	sort(c, c + k);
	long long result = 0;

	priority_queue <int> pq;

	int cnt = 0;
	for (int i = 0; i < k; i++)
	{
		int bag_size = c[i];

		while (cnt < n) {
			int jewel_weight = jewel[cnt].first;
			int jewel_cost = jewel[cnt].second;
			if (bag_size >= jewel_weight)
			{
				pq.push(jewel_cost);
				cnt++;
			}
			else
				break;
		}

		if (!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}
	}

	cout << result;
}

int main()
{
	input();
	solve();

	return 0;
}
