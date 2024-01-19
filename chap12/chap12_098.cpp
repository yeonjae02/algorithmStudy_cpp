#include <iostream>
#include <cmath>
using namespace std;

// BOJ 17387
typedef long long ll; 

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll result = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
	if (result > 0) return 1;
	else if (result < 0) return -1;
	return 0;
}

bool isOverLab(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	if (min(x1, x2) <= max(x3, x4) && min(x3, x4) <= max(x1, x2) && min(y1, y2) <= max(y3, y4) && min(y3, y4) <= max(y1, y2))
		return true;
	return false;
}

bool isCross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
	int abc = ccw(x1, y1, x2, y2, x3, y3);
	int abd = ccw(x1, y1, x2, y2, x4, y4);
	int cda = ccw(x3, y3, x4, y4, x1, y1);
	int cdb = ccw(x3, y3, x4, y4, x2, y2);

	if (abc * abd == 0 && cda * cdb == 0)
		return isOverLab(x1, y1, x2, y2, x3, y3, x4, y4);
	else if (abc * abd <= 0 && cda * cdb <= 0)return true;
	else return false;
}

int main()
{
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	bool cross = isCross(x1, y1, x2, y2, x3, y3, x4, y4);

	if (cross) cout << 1 << "\n";
	else cout << 0 << "\n";
	return 0;
}
