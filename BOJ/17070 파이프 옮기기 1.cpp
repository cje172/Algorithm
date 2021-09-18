#include <iostream>
using namespace std;

const int MAXSIZE = 16;

int n;
int cnt = 0;
int home[16][16];

void movePipe(int state, int r, int c) 
{

	if (r == n - 1 && c == n - 1)
	{
		cnt++;
		return;
	}

	bool MoveH = c + 1 < n && home[r][c + 1] == 0;
	bool MoveV = r + 1 < n && home[r + 1][c] == 0;

	if (MoveH && state != 1)
		movePipe(0, r, c + 1);

	if (MoveV && state != 0)
		movePipe(1, r + 1, c);

	if (MoveH && MoveV && home[r + 1][c + 1] == 0)
		movePipe(2, r + 1, c + 1);
}

int main()
{
	cin >> n;

	int s;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> s;
			home[i][j] = s;
		}
	}

	movePipe(0, 0, 1);

	cout << cnt;

	return 0;
}
