#include <iostream>
using namespace std;

// BOJ 1947
typedef long long ll;
int n, mod = 1000000000;
ll dp[1000001];

int main()
{
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % mod;
	cout << dp[n];
	return 0;
}