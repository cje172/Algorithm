#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, k;
	cin >> N;

	vector<long> len;
	for (int i = 0; i < N - 1; i++)
  {
		cin >> k;
		len.push_back(k);
	}
	vector<long> cost;
	for (int i = 0; i < N; i++)
  {
		cin >> k;
		cost.push_back(k);
	}

	k = 0;
	long result = 0;
	for (int i = 0; i < N - 1; i++)
  {
		if (cost[k] > cost[i])
    {
			k = i;
		}
		result += len[i] * cost[k];
	}

	cout << result;

	return 0;
}
