#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BOJ 1916

#define INF (~0U>>2)
typedef pair<int, int> edge;
vector<vector<edge>> lst;
priority_queue<edge, vector<edge>, greater<edge>> pq;
vector <int> dis;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, fs, fe;
	cin >> n >> m;

	lst.resize(n + 1);
	dis.resize(n + 1);
	fill(dis.begin(), dis.end(), INF);

	for (int i = 0, s, e, v; i < m; i++) {
		cin >> s >> e >> v;
		lst[s].push_back(make_pair(e, v));
	}

	cin >> fs >> fe;
	pq.push(make_pair(0, fs));
	dis[fs] = 0;

	while (!pq.empty()) {
		edge now = pq.top();
		int cost = now.first;
		int city = now.second;
	
		pq.pop();

		for (int i = 0; i < lst[city].size(); i++) {
			int next = lst[city][i].first;
			int nextCost = cost + lst[city][i].second;

			if (dis[next] > nextCost) {
				dis[next] = nextCost;
				pq.push(make_pair(nextCost, next));
			}
		}
	}

	cout << dis[fe];
	return 0;
}