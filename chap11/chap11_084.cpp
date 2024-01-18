#include <iostream>
#include <cmath>
using namespace std;
// BOJ 1463

int dp[1000001], n;

int main()
{
	dp[1] = 0;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	cout << dp[n];
	return 0;
}