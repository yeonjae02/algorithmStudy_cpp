#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// BOJ 11657
#define INF (~0U>>2)
typedef tuple<int, int, int> edge;
typedef long long ll;
static int n, m;
static vector<ll> dis;
static vector<edge> edges;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	dis.resize(n + 1);
	fill(dis.begin(), dis.end(), INF);

	for (int i = 0, s, e, t; i < m; i++) {
		cin >> s >> e >> t;
		edges.push_back(make_tuple(s, e, t));
	}

	dis[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			edge m = edges[j];
			int start = get<0>(m);
			int end = get<1>(m);
			int time = get<2>(m);

			if (dis[start] != INF && dis[end] > dis[start] + time)
				dis[end] = dis[start] + time;
		}
	}

	bool mcycle = false;

	for (int j = 0;j < m; j++) {
		edge m = edges[j];
		int start = get<0>(m);
		int end = get<1>(m);
		int time = get<2>(m);

		if (dis[start] != INF && dis[end] > dis[start] + time)
			mcycle = true;
	}

	if (mcycle) cout << "-1\n";
	else {
		for (int i = 2; i <= n; i++) {
			if (dis[i] == INF)  cout << "-1\n";
			else cout << dis[i] << "\n";
		}
	}
	return 0;
}