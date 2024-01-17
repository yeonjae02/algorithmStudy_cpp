#include <iostream>
using namespace std;

// BOJ 1256
typedef long long ll;
int n, m, k;
ll dp[202][202];

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				if (dp[i][j] > 1000000000) dp[i][j] = 1000000000;
			}
		}
	}

	if (dp[n + m][m] < k)cout << "-1";
	else{
		while (!(n == 0 && m == 0)) {
			if (dp[n - 1 + m][m] >= k) {
				cout << "a";
				n--;
			}
			else {
				cout << "z";
				k -= dp[n - 1 + m][m];
				m--;
			}
		}
	}
	return 0;
}