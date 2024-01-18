#include <iostream>
#include <vector>
using namespace std;

// BOJ 1068
vector<bool>visited;
vector<vector<int>> tree;
int ans = 0, delNode = 0, n,root;

void dfs(int n) {
	visited[n] = true;
	int node = 0;

	for (int i : tree[n]) {
		if (visited[i] == false && i != delNode) {
			node++;
			dfs(i);
		}
	}
	if (node == 0) ans++;
}

int main()
{
	cin >> n;
	visited.resize(n);
	tree.resize(n);

	for (int i = 0, a; i < n; i++) {
		cin >> a;

		if (a != -1) {
			tree[i].push_back(a);
			tree[a].push_back(i);
		}
		else root = i;
	}

	cin >> delNode;

	if (delNode == root) cout << 0 << "\n";
	else {
		dfs(root);
		cout << ans << "\n";
	}
	return 0;
}