#include <iostream>
using namespace std;

// BOJ 11659
int n, m, s[100001] = {0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		s[i] = s[i - 1] + tmp;
	}

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		cout << s[end] - s[start - 1] << "\n";
	}

	return 0;
}