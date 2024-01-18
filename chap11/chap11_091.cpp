#include <iostream>
#include <cmath>
using namespace std;

// BOJ 1915
typedef long long ll;
int n, m, dp[1001][1001];

int main()
{
	cin >> n >> m;
	ll maxValue = 0;

	for (int i = 0; i < n; i++) {
		string mline;
		cin >> mline;
		for (int j = 0; j < m; j++) {
			dp[i][j] = mline[j] - '0';
			if (dp[i][j] == 1 && j > 0 && i > 0) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + dp[i][j];
			}
			if (maxValue < dp[i][j])maxValue = dp[i][j];
		}
	}
	cout << maxValue * maxValue << "\n";
	return 0;
}