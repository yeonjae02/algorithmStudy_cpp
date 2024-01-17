#include <iostream>
using namespace std;
// BOJ 2775

int t,k, n, dp[15][15];

int main()
{
	cin >> t;

	for (int i = 0; i < 15; i++) {
		dp[i][1] = 1;
		dp[0][i] = i;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 2; j < 15; j++)
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
	}

	for (int i = 0; i < t; i++) {
		cin >> k >> n;
		cout << dp[k][n] << "\n";
	}
	return 0;
}