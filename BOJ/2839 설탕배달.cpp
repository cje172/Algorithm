#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;


	if ((N % 5) % 3 == 0)
	{
		N = N / 5 + (N % 5) / 3;
	}
	else
	{
		N = N / 3;
		if (N % 3 != 0)
			N = -1;
	}

	cout << N;

	return 0;
}
