#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// BOJ 1167
typedef pair<int, int> edge;
static vector<vector<edge>> arr;
static vector<bool> visited;
static vector<int> dis;

void bfs(int idx) {
	queue<int> q;
	q.push(idx);
	visited[idx] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (edge e : arr[now]) {
			if (!visited[e.first]) {
				visited[e.first] = true;
				q.push(e.first);
				dis[e.first] = dis[now] + e.second;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	arr.resize(n + 1);

	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		while (true) {
			int e, v;
			cin >> e;
			if (e == -1) break;
			cin >> v;
			arr[s].push_back(edge(e, v));
		}
	}

	dis = vector<int>(n + 1);
	visited = vector<bool>(n + 1, false);
	bfs(1);

	int maxidx = 1;

	for (int i = 2; i <= n; i++) {
		if (dis[maxidx] < dis[i]) maxidx = i;
	}
	fill(dis.begin(), dis.end(), 0);
	fill(visited.begin(), visited.end(), false);
	bfs(maxidx);
	sort(dis.begin(), dis.end());
	cout << dis[n] << "\n";
	return 0;
}