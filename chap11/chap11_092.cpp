#include <iostream>
#include <cmath>
using namespace std;
// BOJ 1328

#define MOD 1000000007;
int l, n, r;
long dp[101][101][101];

int main()
{
	cin >> n >> l >> r;
	dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				dp[i][j][k] = (dp[i-1][j][k] * (i-2)+(dp[i-1][j][k-1]+dp[i-1][j-1][k])) % MOD;
			}
		}
	}

	cout << dp[n][l][r] << "\n";
	return 0;
}