#include <iostream>
#include <cmath>
using namespace std;
// BOJ 2162

int parent[3001], l[3001][4], n;
typedef long long ll;

int find(int i) {
	if (parent[i] < 0)
		return i;
	return parent[i] = find(parent[i]);
}

void uni(int i, int j) {
	int p = find(i);
	int q = find(j);
	if (p == q) return;
	parent[p] += parent[q];
	parent[q] = p;
}

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll temp = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
	if (temp > 0) return 1;
	else if (temp < 0) return -1;
	return 0;

}
bool isOverlab(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	if (min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2) && min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2))
		return true;
	return false;
}
bool isCross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	int abc = ccw(x1, y1, x2, y2, x3, y3);
	int abd = ccw(x1, y1, x2, y2, x4, y4);
	int cda = ccw(x3, y3, x4, y4, x1, y1);
	int cdb = ccw(x3, y3, x4, y4, x2, y2);
	if (abc * abd == 0 && cda * cdb == 0) { // 선분이 일직 선인 경우
		return isOverlab(x1, y1, x2, y2, x3, y3, x4, y4);
	}
	else if (abc * abd <= 0 && cda * cdb <= 0) { // 선분이 교차하는 경우
		return true;
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) parent[i] = -1;

	for (int i = 1; i <= n; i++) {
		cin >> l[i][0] >> l[i][1] >> l[i][2] >> l[i][3];
		for (int j = 1; j < i; j++) {
			if (isCross(l[i][0], l[i][1], l[i][2], l[i][3], l[j][0], l[j][1], l[j][2], l[j][3]))
				uni(i, j);
		}
	}

	int ans = 0, res = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i] < 0)ans++;
		res = min(res, parent[i]);
	}

	cout << ans << "\n" << -res << "\n";
	return 0;
}