#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// BOJ 13398

vector<int> v, l, r;

int main()
{
	int n;
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	l.resize(n);
	l[0] = v[0];
	int maxV = l[0];

	for (int i = 1; i < n; i++) {
		l[i] = max(l[i - 1] + v[i], v[i]);
		maxV = max(maxV, l[i]);
	}

	r.resize(n);
	r[n - 1] = v[n - 1];

	for (int i = n - 2; i >= 0; i--)
		r[i] = max(r[i + 1] + v[i], v[i]);

	for (int i = 1; i < n - 1; i++) {
		int temp = l[i - 1] + r[i + 1];
		maxV = max(maxV, temp);
 	}

	cout << maxV;
	return 0;
}