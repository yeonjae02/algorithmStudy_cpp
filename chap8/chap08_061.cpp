#include <iostream>
using namespace std;

// BOJ 11404
#define INF (~0U>>2)
int n, m, dis[101][101];

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = INF;
		}
	}

	for (int i = 0, s, e, v; i < m; i++) {
		cin >> s >> e >> v;
		if (dis[s][e] > v) dis[s][e] = v;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dis[j][k] > dis[j][i] + dis[i][k]) {
					dis[j][k] = dis[j][i] + dis[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dis[i][j] == INF) cout << "0 ";
			else cout << dis[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}