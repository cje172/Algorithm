#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str, num = "";
	cin >> str;

	int result = 0;
	bool minus = false;
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || i == str.size()) {
			if (minus) {
				result -= stoi(num);
				num = "";
			}
			else {
				result += stoi(num);
				num = "";
			}
		}
		else {
			num += str[i];
		}
		//한번이라도 - 가 나오면 최솟값임(- 누적)
		if (str[i] == '-') {
			minus = true;
		}
	}

	cout << result;

	return 0;
}
[출처] [백준] 1541번 잃어버린 괄호 (C/C++)|작성자 워뇨
