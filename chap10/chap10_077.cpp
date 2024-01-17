#include <iostream>
using namespace std;

// BOJ 11051
int n, m, dp[11][11];

int main()
{
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		dp[i][1] = i;
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			dp[i][j] %= 10007;
		}
	}

	cout << dp[n][m];
	return 0;
}