#include <iostream>
#include <vector>
using namespace std;

// BOJ 11724

static vector<vector<int>> arr;
static vector<bool> visited;

void dfs(int v) 
{
	if (visited[v]) return;
	
	visited[v] = true;
	for (int i : arr[v]) if (visited[i] == false) dfs(i);
}

int main()
{
	int n, m;
	cin >> n >> m;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arr.resize(n + 1);
	visited = vector<bool>(n + 1, false);

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		arr[s].push_back(e);
		arr[e].push_back(s);
	}

	int cnt = 0;
	for (int i = 1; i < n + 1; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}
	}

	cout << cnt << "\n";
	return 0;
}