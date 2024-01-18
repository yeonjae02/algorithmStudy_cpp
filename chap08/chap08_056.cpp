#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BOJ 1753
typedef pair<int, int> edge;
#define INF (~0U>>2) 

int v, e, k;
vector<bool> visited;
vector<int> dis;
vector<vector<edge>> lst;
priority_queue<edge, vector<edge>, greater<edge>> pq;

int main()
{
	cin >> v >> e >> k;
	dis.resize(v + 1);
	visited.resize(v + 1);
	lst.resize(v + 1);
	lst.resize(v + 1);
	fill(dis.begin(), dis.end(), INF);
	fill(visited.begin(), visited.end(), false);

	for (int i = 0, u,v,w; i < e; i++) {
		cin >> u >> v >> w;
		lst[u].push_back(make_pair(v, w));
	}

	pq.push(make_pair(0, k));
	dis[k] = 0;

	while (!pq.empty()) {
		edge now = pq.top();

		pq.pop();
		int cv = now.second;
		if (visited[cv]) continue;
		visited[cv] = true;

		for (int i = 0; i < lst[cv].size(); i++) {
			edge tmp = lst[cv][i];

			int next = tmp.first;
			int cost = tmp.second;

			if (dis[next] > dis[cv] + cost) {
				dis[next] = dis[cv] + cost;
				pq.push(make_pair(dis[next], next));
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (visited[i]) cout << dis[i] << "\n";
		else cout << "INF" << "\n";
	}
	return 0;
}