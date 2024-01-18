#include <iostream>
using namespace std;
// BOJ 1389

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

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		dis[a][b] = 1;
		dis[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dis[j][k] > dis[j][i] + dis[i][k])
					dis[j][k] = dis[j][i] + dis[i][k];
			}
		}
	}

	int minV=INF, ans;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			tmp += dis[i][j];
		}

		if (minV > tmp)
		{
			minV = tmp;
			ans = i;
		}
	}

	cout << ans;
	return 0;
}