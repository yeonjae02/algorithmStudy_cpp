#include <iostream>
#include <vector>
using namespace std;
// BOJ 1717

vector<int> parent;

int find(int n)
{
	if (n == parent[n]) return n;
	return parent[n] = find(parent[n]);
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) parent[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, cmd, a, b;
	cin >> n >> m;

	parent.resize(n + 1);
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> cmd >> a >> b;
		if (cmd == 0) unionfunc(a, b);
		else {
			a = find(a);
			b = find(b);

			if (a == b) cout << "YES\n";
			else cout << "NO\n";

		}
	}
	return 0;
}