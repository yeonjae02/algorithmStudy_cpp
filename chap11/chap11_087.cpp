#include <iostream>
#include <vector>
using namespace std;
// BOJ 11726

int n;
vector<long>dp;

int main()
{
	cin >> n;
	dp.resize(n + 2);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 10007 ;

	cout << dp[n];
	return 0;
}