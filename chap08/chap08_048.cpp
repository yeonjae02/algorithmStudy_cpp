#include <iostream>
#include <vector>
using namespace std;

// BOJ 1707
static vector<vector<int>> arr;
static vector<int> check;
static vector<bool> visited;
static bool isEven;

void dfs(int n) {
	visited[n] = true;

	for (int i : arr[n]) {
		if (!visited[i]) {
			check[i] = (check[n] + 1) % 2;
			dfs(i);
		}
		else if (check[n] == check[i]) isEven = false;
	}
}

int main()
{
	int k, v, e;
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> v >> e;
		arr.resize(v + 1);
		visited.resize(v + 1);
		check.resize(v + 1);
		isEven = true;

		for (int i = 0, u, v; i < e; i++) {
			cin >> u >> v;
			arr[u].push_back(v);
			arr[v].push_back(u);
		}

		for (int i = 1; i <= v; i++) {
			if (isEven) dfs(i);
			else break;
		}

		if (isEven) cout << "YES\n";
		else cout << "NO\n";

		for (int i = 0; i <= v; i++) {
			arr[i].clear();
			visited[i] = false;
			check[i] = 0;
		}
	}
	return 0;
}