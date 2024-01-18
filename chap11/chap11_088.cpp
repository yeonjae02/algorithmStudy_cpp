#include <iostream>
#include <vector>
using namespace std;

// BOJ 10844
#define MOD 1000000000
typedef long long ll;
ll dp[101][11],sum;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];

		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}
	
	for (int i = 0; i < 10; i++) {
		sum = (sum + dp[n][i]) % MOD;
	}

	cout << sum;
	return 0;
}