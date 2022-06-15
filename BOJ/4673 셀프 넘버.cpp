#include <iostream>
using namespace std;

int main()
{
	bool numbers[10001] = { false };
	int n, sum;

	for (int i = 1; i < 10001; i++)
	{
		n = i;
		sum = n + n % 10;
		
    while (n / 10 != 0)
		{
			sum += (n / 10) % 10;
			n /= 10;
		}
    
		if (sum < 10001)
      numbers[sum] = true;
	}

	for (int i = 1; i < 10001; i++)
		if (numbers[i] == false)
      cout << i << '\n';

	return 0;
}
