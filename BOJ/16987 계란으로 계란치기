#include <iostream>
#include <algorithm>
using namespace std;

int n;
int s[8];
int w[8];
int result = 0;

void DFS(int index)
{	// 계란을 처음부터 끝까지 전부 집었을 때
	if (index == n)
	{
		int cnt = 0;
		// 내구도가 0 이하인 것을 찾으면 cnt 증가
		for (int i = 0; i < n; ++i)
			if (s[i] <= 0)
				cnt++;

		result = max(result, cnt);
		return;
	}
	// 현재 손에 든 계란이 깨진 경우 오른쪽 계란으로 이동
	if (s[index] <= 0)
		DFS(index + 1);
	else
	{
		bool check = false;  // 계란을 깼는지 안 깼는지 확인

		for (int i = 0; i < n; i++)  
		{
			if (index == i || s[i] <= 0) // 현재 손에 든 계란 또는 이미 깨진 계란은 넘어감
				continue;
			else
			{
				check = true;  // 계란을 깸
				s[index] -= w[i];
				s[i] -= w[index];

				DFS(index + 1); // 오른쪽 계란으로 이동

				s[index] += w[i];
				s[i] += w[index];
			}
		}
		if (!check) // 더 이상 깰 계란이 없으면 바로 n으로 이동
			DFS(n);
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> s[i] >> w[i];

	DFS(0);

	cout << result << '\n';

	return 0;
}
