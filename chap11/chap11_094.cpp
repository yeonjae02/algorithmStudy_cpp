#include <iostream>
#include <climits>
#include <vector>
using namespace std;
// BOJ 11049

int n;
typedef long long ll;
vector<pair<int, int>>m;
ll dp[502][502];

int execute(int s, int e)
{
	int result = INT_MAX;
	if (dp[s][e] != -1) return dp[s][e];
	if (s == e) return 0;
	if (s + 1 == e)
		return m[s].first * m[s].second * m[e].second;
	for (int i = s; i < e; i++)
		result = min(result, m[s].first * m[i].second * m[e].second + execute(s, i) + execute(i + 1, e));
	return dp[s][e] = result;
}

int main()
{
	cin >> n;
	m.resize(n + 1);
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++)
			dp[i][j] = -1;
	}

	for (int i = 1, x, y; i <= n; i++) {
		cin >> y >> x;
		m[i] = make_pair(y, x);
	}
	cout << execute(1, n) << "\n";
	return 0;
}