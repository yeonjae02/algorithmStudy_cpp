#include <iostream>
using namespace std;
// BOJ 1010

long long n, m, dp[31][31];

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i <= 30; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= 30; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << dp[m][n] << "\n";
	}
	return 0;
}