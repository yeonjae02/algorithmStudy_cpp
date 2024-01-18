#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BOJ 11437
int n, m;
vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> visited;

void bfs(int i) {
	queue<int> q;
	q.push(i);
	visited[i] = true;

	int level = 1, now_size = 1, count = 0;

	while (!q.empty()) {
		int now_node = q.front();
		q.pop();

		for (int next : tree[now_node]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				parent[next] = now_node;
				depth[next] = level;
			}
		}
		count++;
		if (count == now_size) {
			count = 0;
			now_size = q.size();
			level++;
		}
	}
}

int execute(int a, int b) {
	if (depth[a] < depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}

	while (depth[a] != depth[b])
		a = parent[a];

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	tree.resize(n + 1);
	depth.resize(n + 1);
	parent.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int s, e;
		cin >> s >> e;
		tree[s].push_back(e);
		tree[e].push_back(s);
	}

	bfs(1);
	cin >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		int lca = execute(a, b);
		cout << lca << "\n";
	}
	return 0;
}