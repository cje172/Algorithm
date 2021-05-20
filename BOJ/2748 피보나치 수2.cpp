#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int f0 = 0, f1 = 1;
	int sum_first = f0 + f1; // f2
	int sum_second = f1 + sum_first; // f3
	long long int sumE = sum_first, sumO = sum_second;  // 짝수, 홀수
	long long int k = (n % 2 == 0) ? n + 1 : n;

	for (int i = 3; i <= k / 2 + 1; i++)
	{
		sumE = sumE + sumO; // 짝수
		sumO = sumE + sumO; // 홀수
	}
	
	if (n == 0)
		cout << 0;
	else if (n == 1)
		cout << 1;
	else if (n == 2)
		cout << sum_first;
	else if (n == 3)
		cout << sum_second;
	else if (n > 3 && n % 2 != 0) // 홀수
		cout << sumO;
	else if (n > 3 && n % 2 == 0) // 짝수
		cout << sumE;

	return 0;
}
