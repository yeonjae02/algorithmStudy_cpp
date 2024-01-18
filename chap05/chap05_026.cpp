#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// BOJ 1260

int n, m, v;
static vector<vector<int>> arr;
static vector<bool> visited;

void dfs(int s) 
{
	cout << s << " ";
	visited[s] = true;

	for (int i : arr[s]) if (!visited[i]) dfs(i);
}

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i : arr[now]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;
	arr.resize(n+1);
	visited = vector<bool>(n + 1, false);

	for (int i = 0, a=0, b=0; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) sort(arr[i].begin(), arr[i].end());

	dfs(v);
	cout << "\n";
	fill(visited.begin(), visited.end(), false);
	bfs(v);
	return 0;
}