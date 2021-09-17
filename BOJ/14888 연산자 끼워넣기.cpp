#include <iostream>
using namespace std;

int n; 
int num[11];
int op[4];

int max_value = -1000000000;
int min_value = 1000000000;

void calValue(int value, int cnt)
{
    if (cnt == n)
    {
        if (value > max_value)
            max_value = value;
        if (value < min_value) 
            min_value = value;
	}

    for (int i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            op[i]--;
            if (i == 0)
                calValue(value + num[cnt], cnt + 1);
            else if (i == 1)
                calValue(value - num[cnt], cnt + 1);
            else if (i == 2)
                calValue(value * num[cnt], cnt + 1);
            else if (i == 3)
                calValue(value / num[cnt], cnt + 1);
            
            op[i]++;
        }
    }
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];

    calValue(num[0], 1);

	cout << max_value << '\n'
		<< min_value << '\n';

	return 0;
}
