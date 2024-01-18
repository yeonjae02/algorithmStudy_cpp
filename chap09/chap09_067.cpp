#include <iostream>
#include <vector>
using namespace std;

// BOJ 11725
vector<int> ans;
vector<bool> visited;
vector<vector<int>> tree;

void dfs(int n) {
	visited[n] = true;

	for (int i : tree[n]) {
		if (!visited[i]) {
			ans[i] = n;
			dfs(i);
		}
	}
}

int main() 
{
	int n;
	cin >> n;

	visited.resize(n + 1);
	tree.resize(n + 1);
	ans.resize(n + 1);

	for (int i = 1, a, b; i < n; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) cout << ans[i] << "\n";
	return 0;
}