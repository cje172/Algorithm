#include <iostream>
using namespace std;

const int NUMBER = 51;
int map[NUMBER][NUMBER];
int m, n, k;

void init() // 초기화
{
	for (int width = 0; width < NUMBER; width++)
		for (int length = 0; length < NUMBER; length++)
			map[width][length] = 0;
}

void searchCabbage(int y, int x)
{
	if (map[y][x] == 1)
		map[y][x] = 0;

	if (map[y][x + 1] == 1)
	{
		searchCabbage(y, x + 1);
	}
	if (map[y][x - 1] == 1)
	{
		searchCabbage(y, x - 1);
	}
	if (map[y + 1][x] == 1)
	{
		searchCabbage(y + 1, x);
	}
	if (map[y - 1][x] == 1)
	{
		searchCabbage(y - 1, x);
	}

}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		init();
		cin >> m >> n;
		cin >> k;
		int x, y;

		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			map[y][x] = 1;
		}

		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 1) 
				{
					count++;
					searchCabbage(i, j);
				}
			}
		}
		cout << count << '\n';
	}
	
	return 0;
}
