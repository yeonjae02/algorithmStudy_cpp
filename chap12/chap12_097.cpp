#include <iostream>
// BOJ 11758

using namespace std;

int main()
{
	int p1x, p1y, p2x, p2y, p3x, p3y,result;
	cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;

	result = (p1x * p2y + p2x * p3y + p3x * p1y) - (p2x * p1y + p3x * p2y + p1x * p3y);

	if (result > 0) cout << 1 << "\n";
	else if (result == 0) cout << 0 << "\n";
	else cout << -1 << "\n";
	return 0;
}