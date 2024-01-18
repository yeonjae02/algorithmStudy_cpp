#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BOJ 1377

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector <pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(v.begin(), v.end());
	int maxValue = 0;

	for (int i = 0; i < n; i++) {
		if (maxValue < v[i].second - i) maxValue = v[i].second - i;
	}

	cout << maxValue + 1;
	return 0;
}