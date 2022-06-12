#include <iostream>
using namespace std;

int main()
{
    long long int s, n = 1, c = 0;
    cin >> s;
  
    while (s != 0 && s - n >= 0)
    {
            s -= n++;
            c++;
    }
    cout << c;
}
