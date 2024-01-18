#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// BOJ 14501

int n;
vector<int> d,t,p;

int main()
{
	cin >> n;
	d.resize(n + 2);
	t.resize(n + 1);
	p.resize(n + 1);

	for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];

	for (int i = n; i > 0; i--) {
		if (i + t[i] > n + 1) d[i] = d[i + 1];
		else d[i] = max(d[i + 1], p[i] + d[i + t[i]]);
	}
	cout << d[1];
	return 0;
}