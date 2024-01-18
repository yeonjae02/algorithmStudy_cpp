#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// BOJ 9252

int n, dp[1001][1001];
string a, b;
vector<char> path;

void getText(int r, int c) {
	if (r == 0 || c == 0) return;
	if (a[r - 1] == b[c - 1]) {
		path.push_back(a[r - 1]);
		getText(r - 1, c - 1);
	}
	else {
		if (dp[r - 1][c] > dp[r][c - 1]) getText(r - 1, c);
		else getText(r, c - 1);
	}
}

int main() 
{
	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[a.size()][b.size()] << "\n";
	getText(a.size(), b.size());
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i];
	cout << "\n";
	return 0;
}