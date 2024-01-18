#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BOJ 1854

typedef pair<int, int> Node;
static int n, m, k;
static int w[1001][1001];
static priority_queue<int> distQueue[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		w[a][b] = c;
	}

	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push(make_pair(0, 1));
	distQueue[1].push(0);

	while (!pq.empty()) {
		Node u = pq.top();
		pq.pop();

		for (int adjNode = 1; adjNode <= n; adjNode++) {
			if (w[u.second][adjNode] != 0) {
				if (distQueue[adjNode].size() < k) {
					distQueue[adjNode].push(u.first + w[u.second][adjNode]);
					pq.push(make_pair(u.first + w[u.second][adjNode], adjNode));
				}
				else if (distQueue[adjNode].top() > u.first + w[u.second][adjNode]) {
					distQueue[adjNode].pop();
					distQueue[adjNode].push(u.first + w[u.second][adjNode]);
					pq.push(make_pair(u.first + w[u.second][adjNode], adjNode));
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (distQueue[i].size() == k) cout << distQueue[i].top() << "\n";
		else cout << -1 << "\n";
	}
	return 0;
}