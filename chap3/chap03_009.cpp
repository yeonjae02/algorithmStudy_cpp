#include <iostream>
using namespace std;

// BOJ 12891

int tmp[4], condition[4], idx;
int s, p,result;
string str;

void valueChange(char c, int isadd) {
	if (c == 'A')idx = 0;
	else if (c == 'C') idx = 1;
	else if (c == 'G') idx = 2;
	else if (c == 'T') idx = 3;

	tmp[idx]+= isadd;
}

bool check() {
	for (int i = 0; i < 4; i++) if (tmp[i] != condition[i]) return false;
	return true;
}

int main()
{
	cin >> s >> p >> str;

	for (int i = 0; i < 4; i++) cin >> condition[i];

	for (int i = 0; i < p; i++) valueChange(str[i], 1);
	if (check()) result++;

	for (int end = p; end <= s; end++)
	{
		int start = end - p;
		cout << "\n";
		valueChange(str[end],1);
		valueChange(str[start], -1);
		if (check()) result++;
	}

	cout << result << "\n";
	return 0;
}