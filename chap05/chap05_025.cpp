#include <iostream>
#include <vector>
using namespace std;

// BOJ 13023

static vector<vector<int>> v;
static vector<bool> isvisited;

int n, m, a, b;
bool finish = false;

void dfs(int s, int l) {
	if (l == 5) {
		finish = true;
		return;
	}

	isvisited[s] = true;

	for (int i : v[s]) {
		if (!isvisited[i]) dfs(i, l + 1);
	}
	isvisited[s] = false;
}

int main() 
{
	cin >> n >> m;
	v.resize(n);
	isvisited = vector<bool>(n, false);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		dfs(i, 1);
		if (finish) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}