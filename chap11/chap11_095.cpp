#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
// BOJ 2098

int inf = 1000000 * 16 + 1;
int n, w[16][16], d[16][(1<<16)];

int tsp(int c, int v) {
	if (v == (1 << n) - 1)
		return w[c][0] == 0 ? inf : w[c][0];
	if (d[c][v] != 0)
		return d[c][v];
	int minV = inf;
	for (int i = 0; i < n; i++) {
		if ((v & (1 << i)) == 0 && w[c][i] != 0)
			minV = min(minV, tsp(i, (v | (1 << i))) + w[c][i]);
	}
	d[c][v] = minV;
	return d[c][v];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];

	cout << tsp(0, 1) << "\n";
	return 0;
}