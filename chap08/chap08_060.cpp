#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;

// BOJ 1219
typedef tuple<int, int, int> edge;
static int n, m, startCity, endCity;
static vector<long> dis, cityMoney;
static vector<edge> edges;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> startCity >> endCity >> m;

	dis.resize(n);
	cityMoney.resize(n);
	fill(dis.begin(), dis.end(), LONG_MIN);

	for (int i = 0, start, end, price; i < m; i++) {
		cin >> start >> end >> price;
		edges.push_back(make_tuple(start, end, price));
	}

	for (int i = 0; i < n; i++) cin >> cityMoney[i];

	dis[startCity] = cityMoney[startCity];

	for (int i = 0; i <= n + 100; i++) {
		for (int j = 0; j < m; j++) {
			int s = get<0>(edges[j]);
			int e = get<1>(edges[j]);
			int p = get<2>(edges[j]);

			if (dis[s] == LONG_MIN) continue;
			else if (dis[s] == LONG_MAX) dis[e] = LONG_MAX;
			else if (dis[e] < dis[s] + cityMoney[e] - p) {
				dis[e] = dis[s] + cityMoney[e] - p;
				if (i >= n - 1) dis[e] = LONG_MAX;
			}
		}
	}

	if (dis[endCity] == LONG_MIN) cout << "gg\n";
	else if (dis[endCity] == LONG_MAX) cout << "Gee\n";
	else cout << dis[endCity] << "\n";
	return 0;
}