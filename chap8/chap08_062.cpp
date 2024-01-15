#include <iostream>
using namespace std;

// BOJ 11403
int dis[101][101], n;

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dis[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dis[j][i] == 1 && dis[i][k] == 1)
					dis[j][k] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}