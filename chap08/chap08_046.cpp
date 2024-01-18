#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// BOJ 18352
typedef long long ll;

static vector<vector<int>> arr;
static vector<int> result;
static vector<int> visited;

void bfs(int n) {
	queue <int> q;
	q.push(n);
	visited[n]++;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i : arr[now]) {
			if (visited[i] == -1) {
				visited[i] = visited[now] + 1;
				q.push(i);
			}
		}
	}
}

int main()
{
	ll n, m, k, x;
	cin >> n >> m >> k >> x;
	arr.resize(n + 1);
	visited.resize(n + 1);
	fill(visited.begin(), visited.end(), -1);

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
	}

	bfs(x);

	for (int i = 0; i <= n; i++)
		if (visited[i] == k) result.push_back(i);

	if (result.empty()) cout << "-1";
	else {
		sort(result.begin(), result.end());
		for (int i : result)
			cout << i << "\n";
	}

	return 0;
}