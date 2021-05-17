#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 501;
int paper[MAX][MAX];
bool visited[MAX][MAX];
int m, n;
int area, maxSize;


void searchPicture(int n, int m)
{
	area++;
	visited[n][m] = true;

	if (!visited[n][m] && paper[n][m] == 1)
		paper[n][m] = 0;

	if (!visited[n][m + 1] && paper[n][m + 1] == 1)
		searchPicture(n, m + 1);
	if (!visited[n][m - 1] && paper[n][m - 1] == 1)
		searchPicture(n, m - 1);
	if (!visited[n + 1][m] && paper[n + 1][m] == 1)
		searchPicture(n + 1, m);
	if (!visited[n - 1][m] && paper[n - 1][m] == 1)
		searchPicture(n - 1, m);
}


int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> paper[i][j];
		}

	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && paper[i][j] == 1)
			{
				area = 0;
				searchPicture(i, j);
				maxSize = max(maxSize, area);
				cnt++;

			}
		}
	}
	cout << cnt << '\n' << maxSize << '\n';
	
	return 0;
}
