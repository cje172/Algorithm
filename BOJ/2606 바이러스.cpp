#include <iostream>
using namespace std;

int computerNum, networkNum, x, y;
int a[101][101];
int infected[101];
int infCount = 0;

void dfs(int n)
{
	infected[n] = 1;
	infCount++;
	for (int i = 1; i <= computerNum; i++)
		if (a[n][i] && !infected[i])
			dfs(i);
}

int main()
{
	cin >> computerNum >> networkNum;

	for (int i = 0; i < networkNum; i++)
	{
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}

	dfs(1);
	cout << infCount - 1 << '\n';

	return 0;
}
