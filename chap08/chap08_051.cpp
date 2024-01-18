#include <iostream>
#include <vector>
using namespace std;
// BOJ 1976

vector<int> parent;
int city[201][201],route[201];

int find(int n) {
	if (n == parent[n]) return n;
	else return parent[n] = find(parent[n]);
}

void unionfun(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) parent[b] = a;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> city[i][j];
	}

	for (int i = 1; i <= m; i++) cin >> route[i];

	parent.resize(n + 1);

	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (city[i][j] == 1) unionfun(i, j);
		}
	}

	int index = find(route[1]);

	for (int i = 2; i <= m; i++) {
		if (index != find(route[i])) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}