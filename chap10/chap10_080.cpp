#include <iostream>
using namespace std;
// BOJ 13251

int m, k, dp[51],s;
double p[51],ans;

int main()
{
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> dp[i];
		s += dp[i];
	}

	cin >> k;
	for (int i = 0; i < m; i++) {
		if (dp[i] >= k) {
			p[i] = 1;
			for (int j = 0; j < k; j++) {
				p[i] *= (double)(dp[i] - j) / (s - j);
			}
		}
		ans += p[i];
	}

	cout << fixed;
	cout.precision(20);
	cout << ans;
	return 0;
}