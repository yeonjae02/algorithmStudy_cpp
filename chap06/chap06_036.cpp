#include <iostream>
#include <cstring>
using namespace std;

// BOJ 1541

int main()
{
	char op[51], str[51];
	int result = 0, num1 = 0, num[51] = { 0, }, o = 0, n = 0, k = 1, check = 1;

	cin >> str;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			op[o++] = str[i];
			num[n++] = num1;
			num1 = 0;
		}
		else num1 = num1 * 10 + (str[i] - '0');
	}

	num[n] = num1;
	result = num[0], num[n + 1] = op[o] = '\0';
	for (int i = 0; i < o; i++, k++)
	{
		if (op[i] == '+')
		{
			if (check == 1) result += num[k];
			else result -= num[k];
		}
		else
		{
			result -= num[k];
			if (check == 1) check = 0;
		}
	}

	cout << result;
	return 0;
}