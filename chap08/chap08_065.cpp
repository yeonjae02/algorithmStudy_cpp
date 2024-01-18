#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BOJ 17472
int dr[] = { -1, 0, 1, 0 }, dc[] = { 0,1,0,-1 };
int map[101][101], n, m, snum;
bool visited[101][101] = { false, };
vector<int> parent;
vector<vector<pair<int, int>>> sumlist;
vector <pair<int, int>> mlist;

typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
} Edge;

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

int find(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = find(parent[a]);
}

void munion(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[b] = a;

}

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	mlist.clear();
	q.push(make_pair(i, j));
	mlist.push_back(make_pair(i, j));
	visited[i][j] = true;
	map[i][j] = snum;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;

		q.pop();
		for (int d = 0; d < 4; d++) {
			int tmpr = dr[d];
			int tmpc = dc[d];
			while (r + tmpr >= 0 && r + tmpr < n && c + tmpc >= 0 && c + tmpc < m) {
				if (visited[r + tmpr][c + tmpc] == false && map[r + tmpr][c + tmpc] != 0) {
					int nowi = r + tmpr;
					int nowj = c + tmpc;

					map[nowi][nowj] = snum;
					visited[nowi][nowj] = true;
					mlist.push_back(make_pair(nowi, nowj));
					q.push(make_pair(nowi, nowj));
				}
				else break;

				if (tmpr < 0) tmpr--;
				else if (tmpr > 0) tmpr++;
				else if (tmpc < 0) tmpc--;
				else if (tmpc > 0) tmpc++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	snum = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != -0 && visited[i][j] != true) {
				bfs(i, j);
				snum++;
				sumlist.push_back(mlist);
			}
		}
	}

	for (int i = 0; i < sumlist.size(); i++) {
		vector<pair<int, int>> now = sumlist[i];
		for (int j = 0; j < now.size(); j++) {
			int r = now[j].first;
			int c = now[j].second;
			int nows = map[r][c];

			for (int d = 0; d < 4; d++) {
				int tmpr = dr[d];
				int tmpc = dc[d];
				int bl = 0;

				while (r + tmpr >= 0 && r + tmpr < n && c + tmpc >= 0 && c + tmpc < m) {
					if (map[r + tmpr][c + tmpc] == nows) break;
					else if (map[r + tmpr][c + tmpc] != 0) {
						if (bl > 1) pq.push(Edge{ nows, map[r + tmpr][c + tmpc], bl });
						break;
					}
					else bl++;

					if (tmpr < 0) tmpr--;
					else if (tmpr > 0) tmpr++;
					else if (tmpc < 0) tmpc--;
					else if (tmpc > 0) tmpc++;
				}
			}
		}
	}

	parent.resize(snum);
	for (int i = 0; i < parent.size(); i++) parent[i] = i;

	int useEdge = 0, result = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (find(now.s) != find(now.e)) {
			munion(now.s, now.e);
			result += now.v;
			useEdge++;
		}
	}

	if (useEdge == snum - 2) cout << result << "\n";
	else cout << -1 << "\n";

	return 0;
}