#include <iostream>
using namespace std;

int main()
{
	int l, p, v, answer, i = 0;
	cin >> l >> p >> v;

	do 
	{
		i++;
		answer = 0;
		answer += (v / p) * l + min(v % p, l);

		cout << "Case " << i << ": " << answer << '\n';
		cin >> l >> p >> v;

	} while ((l != 0) && (p != 0) && (v != 0));
	
	return 0;
}
