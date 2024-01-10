#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// BOJ 17298

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	vector <int> ans(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];

	stack<int>st;
	st.push(0);

	for (int i = 1; i < n; i++) {
		while (!st.empty() && v[st.top()] < v[i]) {
			ans[st.top()] = v[i];
			st.pop();
		}
		st.push(i);
	}

	while (!st.empty()) {
		ans[st.top()] = -1;
		st.pop();
	}

	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0;
}