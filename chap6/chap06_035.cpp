#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// BOJ 1931
typedef pair<int, int> p;

bool cmp(p a, p b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	int n, s, e, end, cnt = 0;
	cin >> n;
	vector<p>v;

	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back(make_pair(s, e));
	}

	sort(v.begin(), v.end(), cmp);
	end = v.begin()->second;
	for (int i = 0; i < n; i++) {
		if (v[i].first >= end) {
			cnt++;
			end = v[i].second;
		}
	}
	cout << cnt;
	return 0;
}